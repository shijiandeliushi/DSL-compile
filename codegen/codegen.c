#include <stdio.h>
#include <string.h>
#include "codegen.h"

static void print_indent(int n) {
    for (int i = 0; i < n; i++) printf("    ");
}

void generate_code(ASTNode *node, int indent) {
    if (!node) return;

    if (strcmp(node->type, "Program") == 0) {
        printf("from homelang_rt import *\n\n");
        for (int i = 0; i < node->child_count; i++) generate_code(node->children[i], indent);
    }
    else if (strcmp(node->type, "DeviceDeclaration") == 0) {
        char *type = node->children[1]->value.string;
        char *id = node->children[2]->value.string;
        char *alias = node->children[4]->value.string;
        // 映射到 Python 类
        if (strcmp(type, "LIGHT") == 0) printf("%s = Light('%s', '%s')\n", id, id, alias);
        else if (strcmp(type, "AIR_CONDITIONER") == 0) printf("%s = AirConditioner('%s', '%s')\n", id, id, alias);
        else if (strcmp(type, "FRIDGE") == 0) printf("%s = Fridge('%s', '%s')\n", id, id, alias);
        else printf("%s = Device('%s', '%s')\n", id, id, alias);
    }
    else if (strcmp(node->type, "varibleDeclaration") == 0) {
        ASTNode *id_list = node->children[2];
        for(int i=0; i<id_list->child_count; i++) {
            if (strcmp(id_list->children[i]->type, "Identifier") == 0) {
                printf("%s = 0\n", id_list->children[i]->value.string);
            }
        }
    }
    else if (strcmp(node->type, "variableAssignment") == 0) {
        print_indent(indent);
        printf("%s = ", node->children[0]->value.string);
        generate_code(node->children[2], 0);
        printf("\n");
    }
    else if (strcmp(node->type, "Rule") == 0) {
        char *rule_name = node->children[1]->value.string;
        printf("\ndef rule_%s():\n", rule_name);
        generate_code(node->children[3], indent + 1);
        printf("\nrun_rule('%s', rule_%s)\n", rule_name, rule_name);
    }
    
    else if (strcmp(node->type, "Action") == 0) {
        print_indent(indent);
        char *id = node->children[1]->value.string;
        ASTNode *status = node->children[3]->children[0];
        if (strcmp(status->type, "Switch") == 0) {
            printf("%s.set_status('%s')\n", id, status->value.string);
        } else {
            printf("%s.set_value(", id);
            generate_code(status, 0);
            printf(")\n");
        }
    }
    else if (strcmp(node->type, "IfStatement") == 0) {
        print_indent(indent);
        printf("if ");
        generate_code(node->children[2], 0); // condition
        printf(":\n");
        generate_code(node->children[5], indent + 1); // stateList
    }
    else if (strcmp(node->type, "WhileStatement") == 0) {
        print_indent(indent);
        printf("while ");
        generate_code(node->children[2], 0);
        printf(":\n");
        generate_code(node->children[6], indent + 1);
    }
    else if (strcmp(node->type, "Expression") == 0 || strcmp(node->type, "Condition") == 0) {
        for (int i = 0; i < node->child_count; i++) {
            ASTNode *c = node->children[i];
            if (c->value_type == VALUE_TYPE_STRING) printf("%s ", c->value.string);
            else if (c->value_type == VALUE_TYPE_INT) printf("%d ", c->value.integer);
            else if (c->value_type == VALUE_TYPE_FLOAT) printf("%f ", c->value.floating);
            else generate_code(c, 0);
        }
    }
    else if (strcmp(node->type, "TimeCondition") == 0) {
        // 翻译为 homelang_rt 中的辅助函数
        char *kw = node->children[1]->value.string;
        if (strcmp(kw, "BETWEEN") == 0) {
            printf("is_time_between('%s', '%s') ", node->children[2]->value.string, node->children[4]->value.string);
        } else if (strcmp(kw, "AFTER") == 0) {
            printf("is_time_after('%s') ", node->children[2]->value.string);
        }
    }
    else {
        // 默认递归处理列表类节点
        for (int i = 0; i < node->child_count; i++) generate_code(node->children[i], indent);
    }
}