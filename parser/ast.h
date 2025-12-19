/* ast.h - AST node definitions */
#ifndef PARSER_AST_H
#define PARSER_AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AST 节点定义
typedef struct ASTNode {
    char *type;            // 节点类型
    char *value;           // 节点值
    struct ASTNode *left;  // 左子节点
    struct ASTNode *right; // 右子节点
    struct ASTNode **children; // 可变数量的子节点数组（可为 NULL）
    int child_count;           // 子节点数量
} ASTNode;

// 创建 AST 节点（type 和 value 均可为 NULL）
ASTNode* create_node(char *type, char *value);

// 向父节点添加子节点
void add_child(ASTNode *parent, ASTNode *child);

// 打印 AST（树状显示）
void print_ast_tree(ASTNode *root);

#endif /* PARSER_AST_H */