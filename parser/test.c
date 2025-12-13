#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ASTNode {
    char *type;              // 节点类型
    char *value;             // 节点值（可选）
    struct ASTNode *left;    // 左子节点
    struct ASTNode *right;   // 右子节点
} ASTNode;

// 创建 AST 根节点，返回指向根节点的指针
ASTNode* create_node(char *type, char *value) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = value ? strdup(value) : NULL;
    node->left = node->right = NULL;
    return node;
}

// 打印 AST（漂亮的树状结构）
// prefix: 当前行前缀（由上层传入）
// is_tail: 是否为当前兄弟链上的最后一个节点（决定使用 └── 还是 ├──）
void print_ast(ASTNode *node, const char *prefix, int is_tail) {
    if (!node) return;

    printf("%s", prefix);
    printf(is_tail ? "└── " : "├── ");
    printf("%s", node->type);
    if (node->value) printf(": %s", node->value);
    printf("\n");

    // 为子节点构造新的前缀
    char new_prefix[1024];
    snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_tail ? "    " : "│   ");

    // 只考虑最多两个子节点（left 和 right），按左、右顺序打印
    int has_left = node->left != NULL;
    int has_right = node->right != NULL;

    if (has_left && has_right) {
        print_ast(node->left, new_prefix, 0);
        print_ast(node->right, new_prefix, 1);
    } else if (has_left) {
        print_ast(node->left, new_prefix, 1);
    } else if (has_right) {
        print_ast(node->right, new_prefix, 1);
    }
}

// 释放 AST 内存
void free_ast(ASTNode *node) {
    if (!node) return;
    free_ast(node->left);
    free_ast(node->right);
    free(node->type);
    if (node->value) free(node->value);
    free(node);
}

// 测试 create_node 和 print_ast 函数
int main() {
    printf("========== AST 测试开始 ==========\n\n");

    // 测试1: 创建简单节点
    printf("测试1: 创建简单节点\n");
    ASTNode *root = create_node("Program", NULL);
    printf("创建了根节点: Program\n\n");

    // 测试2: 创建带有值的节点
    printf("测试2: 创建带有值的节点\n");
    ASTNode *expr = create_node("BinaryOp", "+");
    printf("创建了表达式节点: BinaryOp: +\n\n");
    // 把 expr 暂时不挂到 root，单独创建以示例

    // 测试3: 构建 AST 树
    printf("测试3: 构建 AST 树\n");
    root->left = create_node("Assignment", "=");
    root->left->left = create_node("Identifier", "x");
    root->left->right = create_node("Number", "10");
    
    root->right = create_node("BinaryOp", "+");
    root->right->left = create_node("Identifier", "x");
    root->right->right = create_node("Number", "5");

    printf("AST 树结构:\n");
    print_ast(root, "", 1);
    
    printf("\n========== AST 测试结束 ==========\n");

    // 释放内存
    free_ast(root);
    free_ast(expr);

    return 0;
}