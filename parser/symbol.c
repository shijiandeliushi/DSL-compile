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

/**
 * 打印符号表（表格样式）
 */
void print_symbol_table() {
    printf("\n+----------------------+----------------+----------------------+\n");
    printf("| %-20s | %-14s | %-20s |\n", "Symbol Name", "Kind", "Sub-Type/Info");
    printf("+----------------------+----------------+----------------------+\n");

    Symbol *curr = symbol_table;
    if (!curr) {
        printf("| %-58s |\n", " (Symbol table is empty) ");
    }

    while (curr) {
        char *kind_str;
        switch (curr->kind) {
            case SYM_DEVICE:   kind_str = "DEVICE"; break;
            case SYM_VARIABLE: kind_str = "VARIABLE"; break;
            case SYM_RULE:     kind_str = "RULE"; break;
            default:           kind_str = "UNKNOWN"; break;
        }

        // 打印每一行，sub_type 为空时显示 "N/A"
        printf("| %-20s | %-14s | %-20s |\n", 
               curr->name, 
               kind_str, 
               curr->sub_type ? curr->sub_type : "N/A");
        
        curr = curr->next;
    }
    printf("+----------------------+----------------+----------------------+\n\n");
}

/**
 * 递归处理标识符列表
 */
void process_identifier_list(ASTNode *node, char *val_type) {
    if (!node) return;

    if (strcmp(node->type, "Identifier") == 0) {
        if (!insert_symbol(node->value.string, SYM_VARIABLE, val_type)) {
            fprintf(stderr, "语义错误: 变量 '%s' 重复声明\n", node->value.string);
        }
    } 
    else {
        for (int i = 0; i < node->child_count; i++) {
            process_identifier_list(node->children[i], val_type);
        }
    }
}

void build_symbol_table(ASTNode *node) {
    if (!node) return;

    if (strcmp(node->type, "DeviceDeclaration") == 0) {
        char *dev_type = node->children[1]->value.string;
        char *dev_id = node->children[2]->value.string;
        if (!insert_symbol(dev_id, SYM_DEVICE, dev_type)) {
            fprintf(stderr, "语义错误: 设备 '%s' 重复声明\n", dev_id);
        }
    } 
    else if (strcmp(node->type, "varibleDeclaration") == 0) {
        char *val_type = node->children[1]->children[0]->value.string;
        ASTNode *id_list_root = node->children[2];
        process_identifier_list(id_list_root, val_type);
    }
    else if (strcmp(node->type, "Rule") == 0) {
        char *rule_id = node->children[1]->value.string;
        insert_symbol(rule_id, SYM_RULE, NULL);
    }

    for (int i = 0; i < node->child_count; i++) {
        if (strcmp(node->type, "varibleDeclaration") != 0) {
             build_symbol_table(node->children[i]);
        }
    }
}