#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "ast.h"
#include "symbol.h"
#include "semantic.h" // 确保包含 semantic.h

// ---------------------------------------------------------
// 内部类型定义与辅助函数声明
// ---------------------------------------------------------

typedef enum {
    TYPE_UNKNOWN,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_BOOL,
    TYPE_STRING,
    TYPE_TIMEPOINT, 
    TYPE_VOID
} DataType;

// 【修改】获取节点的真实行号
#define GET_LINENO(node) ((node) ? (node)->lineno : 0)




static void semantic_error(int lineno, const char *format, ...);
static void semantic_warning(int lineno, const char *format, ...);
static DataType infer_expression_type(ASTNode *node);
static DataType string_to_datatype(const char *type_str);
static int parse_time_to_minutes(const char *time_str);
static int is_numeric(DataType t);
static const char* datatype_to_string(DataType t);

// ---------------------------------------------------------
// 具体检查逻辑实现
// ---------------------------------------------------------

// 1. 检查变量赋值
void check_assignment(ASTNode *node) {
    // 结构: variableAssignment -> [Identifier, AssignmentOperator, Expression, fenjiefu]
    if (!node || node->child_count < 3) return;

    ASTNode *id_node = node->children[0];
    ASTNode *expr_node = node->children[2];
    char *var_name = id_node->value.string;
    int lineno = GET_LINENO(node);

    // 检查是否声明
    Symbol *sym = lookup_symbol(var_name);
    if (!sym) {
        semantic_error(lineno, "未声明的变量 '%s'", var_name);
        return;
    }

    if (sym->kind != SYM_VARIABLE) {
        semantic_error(lineno, "标识符 '%s' 不是变量，不能赋值", var_name);
        return;
    }

    // 类型检查
    DataType lhs_type = string_to_datatype(sym->sub_type);
    DataType rhs_type = infer_expression_type(expr_node);

    // 2.3 时间类型使用错误
    if (lhs_type == TYPE_TIMEPOINT && rhs_type != TYPE_TIMEPOINT) {
        semantic_error(lineno, "时间点变量'%s'不能赋值为非时间类型，只允许时间点格式(HH:MM)", var_name);
    }
    // 2.4 温度类型错误 (温度底层通常是 float/int)
    else if (sym->sub_type && strcmp(sym->sub_type, "TEMPERATURE") == 0 && rhs_type == TYPE_STRING) {
        semantic_error(lineno, "温度变量'%s'不能赋值为字符串，只允许数值类型", var_name);
    }
    // 2.1 赋值类型不匹配
    else if (lhs_type == TYPE_INT && rhs_type == TYPE_BOOL) {
        semantic_error(lineno, "类型不匹配，不能将布尔值赋值给整型变量'%s'", var_name);
    }
    else if (lhs_type == TYPE_BOOL && is_numeric(rhs_type)) {
        semantic_warning(lineno, "将数值赋值给布尔变量'%s'，将进行隐式转换", var_name);
    }
    // 简单类型兼容性
    else if (lhs_type != rhs_type && lhs_type != TYPE_UNKNOWN && rhs_type != TYPE_UNKNOWN) {
        // 允许 int <-> float 互转 (报警告或允许)
        if (is_numeric(lhs_type) && is_numeric(rhs_type)) {
             // 8.2 无效的类型转换 (警告)
             if (lhs_type == TYPE_INT && rhs_type == TYPE_FLOAT) {
                 semantic_warning(lineno, "从浮点型到整型的隐式转换可能丢失精度");
             }
        } else {
            semantic_error(lineno, "类型不匹配: 无法将 '%s' 赋值给 '%s'", 
                          datatype_to_string(rhs_type), datatype_to_string(lhs_type));
        }
    }
}

// 2. 检查动作 (Set Device)
void check_action(ASTNode *node) {
    // 结构: Action -> [Keyword(SET), Identifier, Keyword(TO), Status, fenjiefu]
    if (!node || node->child_count < 4) return;

    // 修改开始：处理设备名中可能包含的点号 (例如 laundry.mode)
    char *full_id = node->children[1]->value.string;
    char dev_name[256]; // 创建缓冲区存储纯设备名
    
    // 查找点号的位置
    char *dot = strchr(full_id, '.');
    if (dot) {
        // 如果有点号，只拷贝点号前面的部分
        size_t len = dot - full_id;
        if (len >= sizeof(dev_name)) len = sizeof(dev_name) - 1;
        strncpy(dev_name, full_id, len);
        dev_name[len] = '\0'; // 确保字符串结束符
    } else {
        // 如果没有点号，直接拷贝全部
        strncpy(dev_name, full_id, sizeof(dev_name) - 1);
        dev_name[sizeof(dev_name) - 1] = '\0';
    }
    // 修改结束

    ASTNode *status_node = node->children[3]; // Status 节点
    int lineno = GET_LINENO(node);

    // 使用提取出来的 dev_name 进行查找
    Symbol *sym = lookup_symbol(dev_name);
    
    // 1.1 未声明的标识符
    if (!sym) {
        semantic_error(lineno, "未声明的设备标识符'%s'", dev_name);
        return;
    }
    if (sym->kind != SYM_DEVICE) {
        semantic_error(lineno, "'%s' 不是有效的设备标识符", dev_name);
        return;
    }

    char *dev_type = sym->sub_type ? sym->sub_type : "";
    
    // 获取 Status 的实际值类型
    if (status_node->child_count == 0) return;

    ASTNode *val_node = status_node->children[0]; 
    DataType val_type = TYPE_UNKNOWN;
    
    if (strcmp(val_node->type, "IntegerLiteral") == 0) val_type = TYPE_INT;
    else if (strcmp(val_node->type, "FloatLiteral") == 0) val_type = TYPE_FLOAT;
    else if (strcmp(val_node->type, "Switch") == 0) val_type = TYPE_BOOL; // ON/OFF
    else if (strcmp(val_node->type, "Identifier") == 0) {
        Symbol *var_sym = lookup_symbol(val_node->value.string);
        if (var_sym) val_type = string_to_datatype(var_sym->sub_type);
    }

    // 4.1 & 2.2 设备状态约束
    if (strcmp(dev_type, "LIGHT") == 0) {
        if (val_type != TYPE_BOOL) {
            semantic_error(lineno, "设备'%s'(LIGHT类型)不能设置为数值，只允许on/off", dev_name);
        }
    } 
    else if (strcmp(dev_type, "AIR_CONDITIONER") == 0) {
        if (val_type == TYPE_BOOL) {
            semantic_error(lineno, "设备'%s'(AIR_CONDITIONER类型)不能设置为开关状态，应设置温度值", dev_name);
        }
        // 4.2 温度范围约束
        if (val_type == TYPE_INT && strcmp(val_node->type, "IntegerLiteral") == 0) {
            int temp = val_node->value.integer;
            if (temp < 16 || temp > 30) {
                semantic_error(lineno, "设备'%s'温度设置'%d'超出合理范围(16-30)", dev_name, temp);
            }
        }
    }
}

// 3. 检查表达式 (递归)
void check_expression(ASTNode *node) {
    if (!node) return;
    int lineno = GET_LINENO(node);

    // Expression -> Expression Operator Expression
    if (node->child_count == 3 && node->children[1] && strcmp(node->children[1]->type, "Operator") == 0) {
        ASTNode *left = node->children[0];
        ASTNode *op = node->children[1];
        ASTNode *right = node->children[2];
        char *op_str = op->value.string;

        DataType t1 = infer_expression_type(left);
        DataType t2 = infer_expression_type(right);

        // 8.1 除零错误
        if (strcmp(op_str, "/") == 0) {
            // 检查右操作数是否为字面量0
            // Expression -> IntegerLiteral
            if (right->child_count == 1 && strcmp(right->children[0]->type, "IntegerLiteral") == 0) {
                // [FIXED] 使用 value.integer
                if (right->children[0]->value.integer == 0) {
                    semantic_error(lineno, "检测到除零操作");
                }
            }
        }

        // 2.1(2) 算术运算类型不匹配
        if (strcmp(op_str, "+") == 0 || strcmp(op_str, "-") == 0 || 
            strcmp(op_str, "*") == 0 || strcmp(op_str, "/") == 0) {
            
            if (t1 == TYPE_BOOL || t2 == TYPE_BOOL) {
                semantic_error(lineno, "算术运算符'%s'的操作数类型不匹配(包含布尔型)", op_str);
            }
            if (t1 == TYPE_TIMEPOINT || t2 == TYPE_TIMEPOINT) {
                semantic_error(lineno, "时间点类型不能参与算术运算");
            }
        }

        // 2.1(3) 比较运算类型不匹配
        if (strcmp(op_str, ">") == 0 || strcmp(op_str, "<") == 0 || 
            strcmp(op_str, ">=") == 0 || strcmp(op_str, "<=") == 0) {
            
            // 5.2 时间点比较无效
            if ((t1 == TYPE_TIMEPOINT && t2 != TYPE_TIMEPOINT) || 
                (t1 != TYPE_TIMEPOINT && t2 == TYPE_TIMEPOINT)) {
                semantic_error(lineno, "时间点不能与非时间类型进行比较");
            }
            else if (t1 != t2 && !(is_numeric(t1) && is_numeric(t2))) {
                semantic_error(lineno, "比较运算符'%s'的操作数类型不匹配", op_str);
            }
        }
    }
    // 逻辑运算 Expression -> Expression Keyword(AND/OR) Expression
    else if (node->child_count == 3 && node->children[1] && strcmp(node->children[1]->type, "Keyword") == 0) {
        char *kw = node->children[1]->value.string;
        if (strcmp(kw, "AND") == 0 || strcmp(kw, "OR") == 0) {
            DataType t1 = infer_expression_type(node->children[0]);
            DataType t2 = infer_expression_type(node->children[2]);
            
            // 2.1(4) 逻辑运算类型不匹配
            if (t1 != TYPE_BOOL || t2 != TYPE_BOOL) {
                semantic_error(lineno, "逻辑运算符'%s'的操作数必须是布尔类型", kw);
            }
        }
    }
    // 检查子节点
    for (int i = 0; i < node->child_count; i++) {
        check_expression(node->children[i]);
    }
}

// 4. 检查时间条件
void check_time_condition(ASTNode *node) {
    // 结构: TimeCondition -> [Keyword(TIME), Keyword(BETWEEN), TimePoint, Keyword(AND), TimePoint]
    if (node->child_count == 5 && strcmp(node->children[1]->value.string, "BETWEEN") == 0) {
        char *start_str = node->children[2]->value.string;
        char *end_str = node->children[4]->value.string;
        int lineno = GET_LINENO(node);

        int t1 = parse_time_to_minutes(start_str);
        int t2 = parse_time_to_minutes(end_str);

        // 5.1 时间范围无效
        if (t1 > t2) {
            semantic_error(lineno, "时间范围无效，开始时间'%s'晚于结束时间'%s'", start_str, end_str);
        }
    }
}

// 5. 检查循环
void check_loop(ASTNode *node) {
    int lineno = GET_LINENO(node);

    // 3.3 死循环检测
    if (strcmp(node->type, "WhileStatement") == 0) {
        // WhileStatement -> [WHILE, (, Condition, ), DO, {, StateList, }, ;]
        ASTNode *cond = node->children[2];
        if (cond && cond->child_count == 1) { // Condition -> Expression
             ASTNode *expr = cond->children[0];
             // Expression -> BooleanLiteral
             if (expr->child_count == 1 && strcmp(expr->children[0]->type, "BooleanLiteral") == 0) {
                 if (strcmp(expr->children[0]->value.string, "TRUE") == 0 || 
                     strcmp(expr->children[0]->value.string, "true") == 0) {
                     semantic_warning(lineno, "检测到可能的死循环 (while true)");
                 }
             }
        }
    }
    // 3.1 & 3.2 For 循环检查
    else if (strcmp(node->type, "ForStatement") == 0) {
        // ForStatement -> [FOR, (, Identifier, IN, Range, ), ...]
        char *iter_var = node->children[2]->value.string;
        ASTNode *range = node->children[4]; // Range
        
        Symbol *sym = lookup_symbol(iter_var);
        
        // 【修改】: 删除了 "循环变量未声明" 的检查和报错逻辑
        // for 循环中的变量如果未声明，视为隐式声明的局部变量
        
        // 3.1 循环变量类型错误
        ASTNode *start_val = range->children[1]; 
        
        DataType range_type = TYPE_INT;
        if (strcmp(start_val->type, "TimePoint") == 0 || strcmp(start_val->type, "TIMEPOINT") == 0) {
            range_type = TYPE_TIMEPOINT;
        }

        // 【修改】: 仅当变量在外部已显式声明时，才检查类型是否冲突
        // 如果 sym 为空，说明是隐式声明，默认类型匹配，不报错
        if (sym) {
            DataType var_type = string_to_datatype(sym->sub_type);
            if (var_type != range_type) {
                 semantic_error(lineno, "for循环变量'%s'类型(%s)与迭代范围类型(%s)不匹配", 
                    iter_var, datatype_to_string(var_type), datatype_to_string(range_type));
            }
        }
    }
}

// ---------------------------------------------------------
// 主入口
// ---------------------------------------------------------

void check_semantics(ASTNode *node) {
    if (!node) return;

    // 根据节点类型分发
    if (strcmp(node->type, "variableAssignment") == 0) {
        check_assignment(node);
    }
    else if (strcmp(node->type, "Action") == 0) {
        check_action(node);
    }
    else if (strcmp(node->type, "Expression") == 0) {
        check_expression(node);
    }
    else if (strcmp(node->type, "TimeCondition") == 0) {
        check_time_condition(node);
    }
    else if (strcmp(node->type, "WhileStatement") == 0 || strcmp(node->type, "ForStatement") == 0) {
        check_loop(node);
    }
    
    // 递归遍历所有子节点
    for (int i = 0; i < node->child_count; i++) {
        check_semantics(node->children[i]);
    }
}

// ---------------------------------------------------------
// 辅助函数实现
// ---------------------------------------------------------

static void semantic_error(int lineno, const char *format, ...) {
    // 暂时用 ? 或 0 表示行号，因为 AST 节点中没有
    if (lineno > 0)
        fprintf(stderr, "语义错误 (第 %d 行): ", lineno);
    else
        fprintf(stderr, "语义错误: ");
        
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fprintf(stderr, "\n");
}

static void semantic_warning(int lineno, const char *format, ...) {
    if (lineno > 0)
        fprintf(stderr, "语义警告 (第 %d 行): ", lineno);
    else
        fprintf(stderr, "语义警告: ");

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    fprintf(stderr, "\n");
}

static DataType string_to_datatype(const char *type_str) {
    if (!type_str) return TYPE_UNKNOWN;
    if (strcmp(type_str, "INT0") == 0 || strcmp(type_str, "int") == 0 || strcmp(type_str, "IntegerLiteral") == 0) return TYPE_INT;
    if (strcmp(type_str, "FLOAT0") == 0 || strcmp(type_str, "float") == 0) return TYPE_FLOAT;
    if (strcmp(type_str, "BOOL0") == 0 || strcmp(type_str, "bool") == 0 || strcmp(type_str, "STATE") == 0) return TYPE_BOOL;
    if (strcmp(type_str, "TIMEPOINT") == 0) return TYPE_TIMEPOINT;
    if (strcmp(type_str, "TEMPERATURE") == 0) return TYPE_FLOAT; // 温度视为数值
    return TYPE_UNKNOWN;
}

static const char* datatype_to_string(DataType t) {
    switch(t) {
        case TYPE_INT: return "INT";
        case TYPE_FLOAT: return "FLOAT";
        case TYPE_BOOL: return "BOOL";
        case TYPE_TIMEPOINT: return "TIMEPOINT";
        case TYPE_STRING: return "STRING";
        default: return "UNKNOWN";
    }
}

static int is_numeric(DataType t) {
    return t == TYPE_INT || t == TYPE_FLOAT;
}

// 推导表达式类型
static DataType infer_expression_type(ASTNode *node) {
    if (!node) return TYPE_VOID;

    // 字面量 (根据 parser.y 中的 create_node 名称)
    if (strcmp(node->type, "IntegerLiteral") == 0) return TYPE_INT;
    if (strcmp(node->type, "FloatLiteral") == 0) return TYPE_FLOAT;
    if (strcmp(node->type, "BooleanLiteral") == 0) return TYPE_BOOL;
    if (strcmp(node->type, "StringLiteral") == 0) return TYPE_STRING;
    if (strcmp(node->type, "TimePoint") == 0) return TYPE_TIMEPOINT;
    
    // 标识符
    if (strcmp(node->type, "Identifier") == 0) {
        Symbol *sym = lookup_symbol(node->value.string);
        if (sym) return string_to_datatype(sym->sub_type);
        return TYPE_UNKNOWN;
    }

    // 表达式 Expression -> 子节点
    if (strcmp(node->type, "Expression") == 0) {
        // 如果只有一个子节点，直接透传类型 (如 primary)
        if (node->child_count == 1) {
            return infer_expression_type(node->children[0]);
        }
        // 如果是二元运算: Left Op Right
        if (node->child_count == 3) {
            char *mid_type = node->children[1]->type; // Operator or Keyword
            
            // 逻辑运算/比较运算 -> BOOL
            if (strcmp(mid_type, "Operator") == 0) {
                char *op = node->children[1]->value.string;
                if (strcmp(op, ">") == 0 || strcmp(op, "<") == 0 || 
                    strcmp(op, "==") == 0 || strcmp(op, "!=") == 0 ||
                    strcmp(op, ">=") == 0 || strcmp(op, "<=") == 0) {
                    return TYPE_BOOL;
                }
                // 算术运算 -> 数值 (简单推导：有float则float，否则int)
                DataType t1 = infer_expression_type(node->children[0]);
                DataType t2 = infer_expression_type(node->children[2]);
                if (t1 == TYPE_FLOAT || t2 == TYPE_FLOAT) return TYPE_FLOAT;
                return TYPE_INT;
            }
            if (strcmp(mid_type, "Keyword") == 0) { // AND, OR
                return TYPE_BOOL;
            }
        }
        // NOT Expression
        if (node->child_count == 2 && strcmp(node->children[0]->type, "Keyword") == 0) {
             return TYPE_BOOL;
        }
    }
    
    // Condition 节点
    if (strcmp(node->type, "Condition") == 0) {
        if (node->child_count > 0) return infer_expression_type(node->children[0]);
    }

    return TYPE_UNKNOWN;
}

static int parse_time_to_minutes(const char *time_str) {
    if (!time_str) return 0;
    int h = 0, m = 0;
    sscanf(time_str, "%d:%d", &h, &m);
    return h * 60 + m;
}