//ast.c的头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// AST 节点定义
typedef struct ASTNode {
    char *type;            // 节点类型
    char *value;           // 节点值
    struct ASTNode *left;  // 左子节点
    struct ASTNode *right; // 右子节点
} ASTNode;

//创建AST节点，type为节点类型，value为节点值
ASTNode* create_node(char *type, char *value);


// 打印 AST（更好的树状显示）。
// 使用示例：
//     print_ast_tree(root);
// 输出含有 ├─ └─ │ 等字符以清晰显示树结构。
//参数为根节点指针
void print_ast_tree(ASTNode *root);