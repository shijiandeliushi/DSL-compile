#ifndef SYMBOL_H
#define SYMBOL_H

#include "ast.h"

typedef enum { SYM_DEVICE, SYM_VARIABLE, SYM_RULE } SymbolKind;

typedef struct Symbol {
    char *name;
    SymbolKind kind;
    char *sub_type; // 对于设备是 LIGHT/AC，对于变量是 int/float
    struct Symbol *next;
} Symbol;

// 符号表操作
void init_symbol_table();
int insert_symbol(char *name, SymbolKind kind, char *sub_type);
Symbol* lookup_symbol(char *name);
void build_symbol_table(ASTNode *node);

#endif