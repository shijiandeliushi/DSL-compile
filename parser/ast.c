//构建语法树的一些函数实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"



// 创建 AST 节点，type为节点类型
ASTNode* create_node(char *type) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value_type = VALUE_TYPE_NONE;
    memset(&node->value, 0, sizeof(NodeValue));
    node->left = node->right = NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

// 设置节点的值（字符串类型）
void set_node_string_value(ASTNode *node, char *value) {
    if (node == NULL) return;
    
    // 如果之前是字符串类型，释放内存
    if (node->value_type == VALUE_TYPE_STRING) {
        free(node->value.string);
    }
    
    node->value_type = VALUE_TYPE_STRING;
    node->value.string = value ? strdup(value) : NULL;
}

// 设置节点的值（整数类型）
void set_node_int_value(ASTNode *node, int value) {
    if (node == NULL) return;
    
    // 如果之前是字符串类型，释放内存
    if (node->value_type == VALUE_TYPE_STRING) {
        free(node->value.string);
    }
    
    node->value_type = VALUE_TYPE_INT;
    node->value.integer = value;
}

// 设置节点的值（浮点数类型）
void set_node_float_value(ASTNode *node, float value) {
    if (node == NULL) return;
    
    // 如果之前是字符串类型，释放内存
    if (node->value_type == VALUE_TYPE_STRING) {
        free(node->value.string);
    }
    
    node->value_type = VALUE_TYPE_FLOAT;
    node->value.floating = value;
}

// 设置节点的值（字符类型）
void set_node_char_value(ASTNode *node, char value) {
    if (node == NULL) return;
    
    // 如果之前是字符串类型，释放内存
    if (node->value_type == VALUE_TYPE_STRING) {
        free(node->value.string);
    }
    
    node->value_type = VALUE_TYPE_CHAR;
    node->value.character = value;
}

// 向父节点添加一个子节点（动态扩展 children 数组）
void add_child(ASTNode *parent, ASTNode *child) {
    if (!parent || !child) return;
    parent->children = (ASTNode**)realloc(parent->children, sizeof(ASTNode*) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}



// 内部递归函数：打印单个节点以及其子树，只在ast.c内部被print_ast_tree使用，故不用在头文件中声明
static void print_ast_node(const ASTNode *node, const char *prefix, int is_last) {
    if (!node) return;

    // 打印前缀与分支符号
    printf("%s", prefix);
    printf(is_last ? "└─" : "├─");
    printf("%s", node->type);
    
    // 根据值类型打印不同的值
    switch (node->value_type) {
        case VALUE_TYPE_STRING:
            if (node->value.string) printf(": %s", node->value.string);
            break;
        case VALUE_TYPE_INT:
            printf(": %d", node->value.integer);
            break;
        case VALUE_TYPE_FLOAT:
            printf(": %f", node->value.floating);
            break;
        case VALUE_TYPE_CHAR:
            printf(": '%c'", node->value.character);
            break;
        case VALUE_TYPE_NONE:
            // 无值，不打印
            break;
    }
    printf("\n");

    // 为子节点构造新的前缀
    char new_prefix[1024];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_last ? "  " : "│ ");

    // 优先使用 children 数组（若存在），否则回退到 left/right 两个字段（兼容旧代码）
    if (node->child_count > 0 && node->children) {
        for (int i = 0; i < node->child_count; ++i) {
            print_ast_node(node->children[i], new_prefix, i == node->child_count - 1);
        }
    } else {
        const ASTNode *children_arr[2];
        int n = 0;
        if (node->left) children_arr[n++] = node->left;
        if (node->right) children_arr[n++] = node->right;
        for (int i = 0; i < n; i++) {
            print_ast_node(children_arr[i], new_prefix, i == n - 1);
        }
    }
}

// 对外包装：从根节点开始打印整棵树
void print_ast_tree(ASTNode *root) {
    if (!root) return;
    // 根节点单独打印（没有前缀），随后递归打印子树
    printf("%s", root->type);
    
    // 根据值类型打印不同的值
    switch (root->value_type) {
        case VALUE_TYPE_STRING:
            if (root->value.string) printf(": %s", root->value.string);
            break;
        case VALUE_TYPE_INT:
            printf(": %d", root->value.integer);
            break;
        case VALUE_TYPE_FLOAT:
            printf(": %f", root->value.floating);
            break;
        case VALUE_TYPE_CHAR:
            printf(": '%c'", root->value.character);
            break;
        case VALUE_TYPE_NONE:
            // 无值，不打印
            break;
    }
    printf("\n");

    if (root->child_count > 0 && root->children) {
        for (int i = 0; i < root->child_count; ++i) {
            print_ast_node(root->children[i], "", i == root->child_count - 1);
        }
    } else {
        const ASTNode *children_arr[2];
        int n = 0;
        if (root->left) children_arr[n++] = root->left;
        if (root->right) children_arr[n++] = root->right;
        for (int i = 0; i < n; i++) {
            print_ast_node(children_arr[i], "", i == n - 1);
        }
    }
}
