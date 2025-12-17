//构建语法树的一些函数实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"



// 创建 AST 节点，创建AST节点，type为节点类型，value为节点值
ASTNode* create_node(char *type, char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->left = node->right = NULL;
    return node;
}



// 内部递归函数：打印单个节点以及其子树，只在ast.c内部被print_ast_tree使用，故不用在头文件中声明
static void print_ast_node(const ASTNode *node, const char *prefix, int is_last) {
    if (!node) return;

    // 打印前缀与分支符号
    printf("%s", prefix);
    printf(is_last ? "└─" : "├─");
    printf("%s", node->type);
    if (node->value) printf(": %s", node->value);
    printf("\n");

    // 为子节点构造新的前缀
    char new_prefix[1024];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_last ? "  " : "│ ");

    // 收集非空子节点（按 left, right 顺序）
    const ASTNode *children[2];
    int n = 0;
    if (node->left) children[n++] = node->left;
    if (node->right) children[n++] = node->right;

    for (int i = 0; i < n; i++) {
        print_ast_node(children[i], new_prefix, i == n - 1);
    }
}

// 对外包装：从根节点开始打印整棵树
void print_ast_tree(ASTNode *root) {
    if (!root) return;
    // 根节点单独打印（没有前缀），随后递归打印子树
    printf("%s", root->type);
    if (root->value) printf(": %s", root->value);
    printf("\n");

    const ASTNode *children[2];
    int n = 0;
    if (root->left) children[n++] = root->left;
    if (root->right) children[n++] = root->right;
    for (int i = 0; i < n; i++) {
        print_ast_node(children[i], "", i == n - 1);
    }
}
