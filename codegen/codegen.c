#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "codegen.h"

// 缩进处理
static void print_indent(int n) {
    for (int i = 0; i < n; i++) printf("    ");
}

// 递归处理标识符列表 (var a, b, c)
static void generate_id_list(ASTNode *node) {
    if (!node) return;
    if (strcmp(node->type, "IdentifierList") == 0) {
        if (node->child_count == 3) { // idList COMMA IDENTIFIER
            generate_id_list(node->children[0]);
            printf("%s = 0\n", node->children[2]->value.string);
        } else if (node->child_count == 1) { // IDENTIFIER
            printf("%s = 0\n", node->children[0]->value.string);
        }
    }
}

void generate_code(ASTNode *node, int indent) {
    if (!node) return;

    // 1. 程序入口
    if (strcmp(node->type, "Program") == 0) {
        printf("from preDefination import *\n\n");
        for (int i = 0; i < node->child_count; i++) {
            generate_code(node->children[i], indent);
        }
    }

    // 2. 处理左递归列表 (保证顺序)
    else if (strcmp(node->type, "DeviceDeclarationList") == 0 ||
             strcmp(node->type, "VariableDeclarationList") == 0 ||
             strcmp(node->type, "VariableAssignmentList") == 0 ||
             strcmp(node->type, "RuleList") == 0 ||
             strcmp(node->type, "StateList") == 0) {
        if (node->child_count == 2) {
            generate_code(node->children[0], indent); 
            generate_code(node->children[1], indent); 
        } else if (node->child_count == 1) {
            generate_code(node->children[0], indent);
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

        printf("%s = %s('%s', '%s')\n", id, py_type, id, alias);
    }

    // 4. 变量声明
    else if (strcmp(node->type, "varibleDeclaration") == 0) {
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
        generate_code(node->children[3], indent + 1);
        printf("\nrun_rule('%s', rule_%s)\n", rule_name, rule_name);
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

        ASTNode *val_node = status_node->children[0];
        if (strcmp(val_node->type, "Switch") == 0) {
            printf("'%s'", val_node->value.string);
        } else if (strcmp(val_node->type, "Identifier") == 0) {
            // 如果 set 后面跟着 currTime
            if (strcmp(val_node->value.string, "currTime") == 0) printf("get_current_time_str()");
            else printf("%s", val_node->value.string);
        } else {
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
        generate_code(node->children[2], 0); 
        printf(":\n");
        generate_code(node->children[6], indent + 1); 
    }

    // 10. For 循环 (仅保留整数范围)
    else if (strcmp(node->type, "ForStatement") == 0) {
        print_indent(indent);
        char *iter_var = node->children[2]->value.string;
        ASTNode *range_node = node->children[4];

        if (strcmp(range_node->children[1]->type, "INT_NUMBER") == 0) {
            int start = range_node->children[1]->value.integer;
            int end = range_node->children[3]->value.integer;
            printf("for %s in range(%d, %d):\n", iter_var, start, end + 1);
            generate_code(node->children[7], indent + 1);
        }
    }

    // 11. If 语句
    else if (strcmp(node->type, "IfStatement") == 0) {
        print_indent(indent);
        printf("if ");
        generate_code(node->children[2], 0);
        printf(":\n");
        generate_code(node->children[5], indent + 1);
    }

    // 12. 表达式与条件 (处理 currTime 和 逻辑词)
    else if (strcmp(node->type, "Expression") == 0 || strcmp(node->type, "Condition") == 0) {
        for (int i = 0; i < node->child_count; i++) {
            ASTNode *c = node->children[i];
            if (c->value_type == VALUE_TYPE_STRING) {
                if (strcmp(c->value.string, "and") == 0) printf(" and ");
                else if (strcmp(c->value.string, "or") == 0) printf(" or ");
                else if (strcmp(c->value.string, "not") == 0) printf(" not ");
                else if (strcmp(c->value.string, "currTime") == 0) printf("get_current_time_str()");
                else printf(" %s ", c->value.string);
            } 
            else if (c->value_type == VALUE_TYPE_INT) printf("%d", c->value.integer);
            else if (c->value_type == VALUE_TYPE_FLOAT) printf("%f", c->value.floating);
            else generate_code(c, 0);
        }
    }

    // 13. 时间条件 (核心修改：currTime between A and B)
    else if (strcmp(node->type, "TimeCondition") == 0) {
        // 结构: currTime/TIME(0), BETWEEN/AFTER/BEFORE(1), TIMEPOINT(2)...
        char *op = node->children[1]->value.string;
        if (strcmp(op, "between") == 0) {
            printf("is_time_between('%s', '%s')", node->children[2]->value.string, node->children[4]->value.string);
        } else if (strcmp(op, "after") == 0) {
            printf("is_time_after('%s')", node->children[2]->value.string);
        } else if (strcmp(op, "before") == 0) {
            printf("is_time_before('%s')", node->children[2]->value.string);
        }
    }

    // 14. 基础字面量
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
        if (strcmp(node->value.string, "true") == 0) printf("True");
        else if (strcmp(node->value.string, "false") == 0) printf("False");
        else printf("%s", node->value.string);
    }
    else if (strcmp(node->type, "TimePoint") == 0) {
        printf("'%s'", node->value.string);
    }

    // 15. 默认递归
    else {
        for (int i = 0; i < node->child_count; i++) {
            generate_code(node->children[i], indent);
        }
    }
}