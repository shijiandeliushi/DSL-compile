#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "codegen.h"

// ==========================================
// 【新增】全局变量管理
// ==========================================
#define MAX_GLOBAL_VARS 512
static char *global_var_names[MAX_GLOBAL_VARS];
static int global_var_count = 0;

static void add_global_var(char *name) {
    if (global_var_count < MAX_GLOBAL_VARS) {
        // 查重（可选，但为了生成的代码整洁）
        for (int i = 0; i < global_var_count; i++) {
            if (strcmp(global_var_names[i], name) == 0) return;
        }
        global_var_names[global_var_count++] = strdup(name);
    }
}

// ==========================================
// 辅助函数
// ==========================================

// 缩进处理
static void print_indent(int n) {
    for (int i = 0; i < n; i++) printf("    ");
}

// 递归处理标识符列表 (var a, b, c)
static void generate_id_list(ASTNode *node) {
    if (!node) return;
    if (strcmp(node->type, "IdentifierList") == 0) {
        if (node->child_count >= 3) { // idList COMMA IDENTIFIER
            generate_id_list(node->children[0]); // 递归处理前面的
            
            // 处理当前的 Identifier
            char *var_name = node->children[2]->value.string;
            printf("%s = 0\n", var_name);
            add_global_var(var_name); // 【新增】记录为全局变量
            
        } else if (node->child_count == 1) { // IDENTIFIER
            char *var_name = node->children[0]->value.string;
            printf("%s = 0\n", var_name);
            add_global_var(var_name); // 【新增】记录为全局变量
        }
    }
}

void generate_code(ASTNode *node, int indent) {
    if (!node) return;

    // 1. 程序入口
    if (strcmp(node->type, "Program") == 0) {
        // 重置全局变量计数（如果是多次调用）
        global_var_count = 0;

        // 导入预定义库
        printf("from preDefinition import *\n");
        printf("import datetime\n\n");
        
        printf("# 补充生成的辅助函数\n");
        printf("def is_time_after(t): return get_current_time_str() >= t\n");
        printf("def is_time_before(t): return get_current_time_str() <= t\n\n");
        
        // 继续递归生成后续代码
        for (int i = 0; i < node->child_count; i++) {
            generate_code(node->children[i], indent);
        }
    }

    // 2. 处理列表 (左递归展开)
    else if (strcmp(node->type, "DeviceDeclarationList") == 0 ||
             strcmp(node->type, "VariableDeclarationList") == 0 ||
             strcmp(node->type, "VariableAssignmentList") == 0 ||
             strcmp(node->type, "RuleList") == 0 ||
             strcmp(node->type, "StateList") == 0) {
        for (int i = 0; i < node->child_count; i++) {
            generate_code(node->children[i], indent);
        }
    }

    // 3. 设备声明
    else if (strcmp(node->type, "DeviceDeclaration") == 0) {
        char *raw_type = node->children[1]->value.string;
        char *id = node->children[2]->value.string;
        char *alias = node->children[4]->value.string; 

        char py_type[50];
        if (strcmp(raw_type, "LIGHT") == 0) strcpy(py_type, "Light");
        else if (strcmp(raw_type, "AIR_CONDITIONER") == 0) strcpy(py_type, "AirConditioner");
        else if (strcmp(raw_type, "WATER_HEATER") == 0) strcpy(py_type, "WaterHeater");
        else if (strcmp(raw_type, "TELEVISION") == 0) strcpy(py_type, "Television");
        else if (strcmp(raw_type, "WASHER") == 0) strcpy(py_type, "Washer");
        else if (strcmp(raw_type, "FRIDGE") == 0) strcpy(py_type, "Fridge");
        else if (strcmp(raw_type, "ELECTRIC_FAN") == 0) strcpy(py_type, "ElectricFan");
        else strcpy(py_type, "Device");

        printf("%s = %s('%s','%s')\n", id, py_type, id, alias);
    }

    // 4. 变量声明
    else if (strcmp(node->type, "varibleDeclaration") == 0) {
        // 这里会调用修改后的 generate_id_list，从而填充 global_var_names 数组
        generate_id_list(node->children[2]);
    }

    // 5. 变量赋值 (全局)
    else if (strcmp(node->type, "variableAssignment") == 0) {
        printf("%s = ", node->children[0]->value.string);
        generate_code(node->children[2], 0);
        printf("\n");
    }

    // 6. 规则定义
    else if (strcmp(node->type, "Rule") == 0) {
        char *rule_name = node->children[1]->value.string;
        printf("\ndef rule_%s():\n", rule_name);

        // 【新增】在函数开头声明 global
        if (global_var_count > 0) {
            print_indent(indent + 1);
            printf("global ");
            for (int i = 0; i < global_var_count; i++) {
                printf("%s%s", global_var_names[i], (i == global_var_count - 1) ? "" : ", ");
            }
            printf("\n");
        }

        // 如果规则体为空，打印 pass
        if (node->children[3]->child_count == 0) {
            print_indent(indent + 1);
            printf("pass\n");
        } else {
            generate_code(node->children[3], indent + 1);
        }
        printf("\n# 执行规则\nrun_rule('%s', rule_%s)\n", rule_name, rule_name);
    }

    // 7. 动作执行 (Set ... to ...)
    else if (strcmp(node->type, "Action") == 0) {
        print_indent(indent);
        char *full_id = strdup(node->children[1]->value.string);
        ASTNode *status_node = node->children[3]; 

        char *dot = strchr(full_id, '.');
        if (dot) {
            *dot = '\0';
            printf("%s.set_%s(", full_id, dot + 1);
        } else {
            printf("%s.set_status(", full_id);
        }

        if (status_node->child_count > 0) {
            ASTNode *val_node = status_node->children[0];
            generate_code(val_node, 0);
        }
        
        printf(")\n");
        free(full_id);
    }

    // 8. 规则内的赋值语句
    else if (strcmp(node->type, "AssignStatement") == 0) {
        print_indent(indent);
        printf("%s = ", node->children[0]->value.string);
        generate_code(node->children[2], 0);
        printf("\n");
    }

    // 9. While 循环
    else if (strcmp(node->type, "WhileStatement") == 0) {
        print_indent(indent);
        printf("while ");
        generate_code(node->children[2], 0); // Condition
        printf(":\n");
        generate_code(node->children[6], indent + 1); // StateList
    }

    // 10. For 循环
    else if (strcmp(node->type, "ForStatement") == 0) {
        print_indent(indent);
        char *iter_var = node->children[2]->value.string;
        ASTNode *range_node = node->children[4];

        ASTNode *val1 = range_node->children[1];
        ASTNode *val2 = range_node->children[3];
        
        if (strcmp(val1->type, "IntegerLiteral") == 0 || strcmp(val1->type, "INT_NUMBER") == 0) {
            int start = val1->value.integer;
            int end = val2->value.integer;
            printf("for %s in range(%d, %d):\n", iter_var, start, end + 1);
            generate_code(node->children[7], indent + 1); // StateList
        } else {
             printf("# For loop with non-integer range not fully supported in simple codegen\n");
             print_indent(indent + 1);
             printf("pass\n");
        }
    }

    // 11. If 语句
    else if (strcmp(node->type, "IfStatement") == 0) {
        print_indent(indent);
        printf("if ");
        generate_code(node->children[2], 0); // Condition
        printf(":\n");
        generate_code(node->children[5], indent + 1); // StateList
    }

    // 12. 表达式与条件
    else if (strcmp(node->type, "Expression") == 0 || strcmp(node->type, "Condition") == 0) {
        for (int i = 0; i < node->child_count; i++) {
            generate_code(node->children[i], 0);
        }
    }

    // 13. 运算符与关键字处理
    else if (strcmp(node->type, "Operator") == 0) {
        printf(" %s ", node->value.string);
    }
    else if (strcmp(node->type, "Keyword") == 0) {
        char *kw = node->value.string;
        if (strcmp(kw, "AND") == 0 || strcmp(kw, "and") == 0) printf(" and ");
        else if (strcmp(kw, "OR") == 0 || strcmp(kw, "or") == 0) printf(" or ");
        else if (strcmp(kw, "NOT") == 0 || strcmp(kw, "not") == 0) printf(" not ");
        else if (strcmp(kw, "currTime") == 0) printf("get_current_time_str()");
        else {
            // 其他关键字
        }
    }
    else if (strcmp(node->type, "AssignmentOperator") == 0) {
         printf(" %s ", node->value.string);
    }

    // 14. 时间条件
    else if (strcmp(node->type, "TimeCondition") == 0) {
        char *op = node->children[1]->value.string;
        if (strcmp(op, "BETWEEN") == 0 || strcmp(op, "between") == 0) {
            printf("is_time_between('%s', '%s')", node->children[2]->value.string, node->children[4]->value.string);
        } else if (strcmp(op, "AFTER") == 0 || strcmp(op, "after") == 0) {
            printf("is_time_after('%s')", node->children[2]->value.string);
        } else if (strcmp(op, "BEFORE") == 0 || strcmp(op, "before") == 0) {
            printf("is_time_before('%s')", node->children[2]->value.string);
        }
    }

    // 15. 基础字面量
    else if (strcmp(node->type, "Identifier") == 0) {
        if (strcmp(node->value.string, "currTime") == 0) printf("get_current_time_str()");
        else printf("%s", node->value.string);
    }
    else if (strcmp(node->type, "IntegerLiteral") == 0) {
        printf("%d", node->value.integer);
    }
    else if (strcmp(node->type, "FloatLiteral") == 0) {
        printf("%f", node->value.floating);
    }
    else if (strcmp(node->type, "BooleanLiteral") == 0) {
        char *val = node->value.string;
        if (strcmp(val, "true") == 0 || strcmp(val, "TRUE") == 0) printf("True");
        else if (strcmp(val, "false") == 0 || strcmp(val, "FALSE") == 0) printf("False");
        else printf("%s", val); 
    }
    else if (strcmp(node->type, "StringLiteral") == 0) {
        printf("%s", node->value.string);
    }
    else if (strcmp(node->type, "TimePoint") == 0) {
        printf("'%s'", node->value.string);
    }
    else if (strcmp(node->type, "Switch") == 0) {
        printf("'%s'", node->value.string);
    }
    
    // 16. 默认递归
    else {
        for (int i = 0; i < node->child_count; i++) {
            generate_code(node->children[i], indent);
        }
    }
}
