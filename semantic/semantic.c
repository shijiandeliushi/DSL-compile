#include <stdio.h>
#include <string.h>
#include "semantic.h"

void check_semantics(ASTNode *node) {
    if (!node) return;

    // 检查变量赋值
    if (strcmp(node->type, "variableAssignment") == 0) {
        char *var_id = node->children[0]->value.string;
        if (!lookup_symbol(var_id)) {
            fprintf(stderr, "语义错误: 尝试给未声明的变量 '%s' 赋值\n", var_id);
        }
    }
    // 检查动作执行
    else if (strcmp(node->type, "Action") == 0) {
        char *dev_id = node->children[1]->value.string;
        Symbol *sym = lookup_symbol(dev_id);
        if (!sym || sym->kind != SYM_DEVICE) {
            fprintf(stderr, "语义错误: '%s' 不是有效的设备标识符\n", dev_id);
        }
    }
    // 检查表达式中的标识符
    else if (strcmp(node->type, "Identifier") == 0) {
        // 排除声明处的标识符，只检查引用处的
        // 这里简化处理，实际应根据父节点类型判断
    }

    for (int i = 0; i < node->child_count; i++) {
        check_semantics(node->children[i]);
    }
}