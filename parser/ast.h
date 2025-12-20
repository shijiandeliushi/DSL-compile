/* ast.h - AST node definitions */
#ifndef PARSER_AST_H
#define PARSER_AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义值类型枚举
typedef enum {
    VALUE_TYPE_NONE,    // 无值
    VALUE_TYPE_STRING,  // 字符串类型
    VALUE_TYPE_INT,     // 整数类型
    VALUE_TYPE_FLOAT,   // 浮点数类型
    VALUE_TYPE_CHAR     // 字符类型
} ValueType;

// 值联合体
typedef union {
    char *string;  // 字符串值
    int integer;   // 整数值
    float floating;// 浮点数值
    char character;// 字符值
} NodeValue;

// AST 节点定义
typedef struct ASTNode {
    char *type;            // 节点类型
    ValueType value_type;  // 值类型
    NodeValue value;       // 节点值
    struct ASTNode *left;  // 左子节点
    struct ASTNode *right; // 右子节点
    struct ASTNode **children; // 可变数量的子节点数组（可为 NULL）
    int child_count;           // 子节点数量
} ASTNode;

// 创建 AST 节点（type 可为 NULL）
ASTNode* create_node(char *type);

// 设置节点的值（字符串类型）
void set_node_string_value(ASTNode *node, char *value);

// 设置节点的值（整数类型）
void set_node_int_value(ASTNode *node, int value);

// 设置节点的值（浮点数类型）
void set_node_float_value(ASTNode *node, float value);

// 设置节点的值（字符类型）
void set_node_char_value(ASTNode *node, char value);

// 向父节点添加子节点
void add_child(ASTNode *parent, ASTNode *child);

// 打印 AST（树状显示）
void print_ast_tree(ASTNode *root);

#endif /* PARSER_AST_H */