#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

static Symbol *symbol_table = NULL;

void init_symbol_table() {
    symbol_table = NULL;
}

int insert_symbol(char *name, SymbolKind kind, char *sub_type) {
    if (lookup_symbol(name)) return 0; // 已存在
    Symbol *new_sym = (Symbol*)malloc(sizeof(Symbol));
    new_sym->name = strdup(name);
    new_sym->kind = kind;
    new_sym->sub_type = sub_type ? strdup(sub_type) : NULL;
    new_sym->next = symbol_table;
    symbol_table = new_sym;
    return 1;
}

Symbol* lookup_symbol(char *name) {
    Symbol *curr = symbol_table;
    while (curr) {
        if (strcmp(curr->name, name) == 0) return curr;
        curr = curr->next;
    }
    return NULL;
}

void build_symbol_table(ASTNode *node) {
    if (!node) return;

    if (strcmp(node->type, "DeviceDeclaration") == 0) {
        // children: DEVICE, DeviceType, Identifier, AS, StringLiteral
        char *dev_type = node->children[1]->value.string;
        char *dev_id = node->children[2]->value.string;
        if (!insert_symbol(dev_id, SYM_DEVICE, dev_type)) {
            fprintf(stderr, "语义错误: 设备 '%s' 重复声明\n", dev_id);
        }
    } 
    else if (strcmp(node->type, "varibleDeclaration") == 0) {
        // children: VAR, ValueType, IdentifierList
        char *val_type = node->children[1]->children[0]->value.string;
        ASTNode *id_list = node->children[2];
        // 递归处理标识符列表
        for(int i=0; i<id_list->child_count; i++) {
            if (strcmp(id_list->children[i]->type, "Identifier") == 0) {
                char *var_id = id_list->children[i]->value.string;
                if (!insert_symbol(var_id, SYM_VARIABLE, val_type)) {
                    fprintf(stderr, "语义错误: 变量 '%s' 重复声明\n", var_id);
                }
            }
        }
    }
    else if (strcmp(node->type, "Rule") == 0) {
        char *rule_id = node->children[1]->value.string;
        insert_symbol(rule_id, SYM_RULE, NULL);
    }

    for (int i = 0; i < node->child_count; i++) {
        build_symbol_table(node->children[i]);
    }
}