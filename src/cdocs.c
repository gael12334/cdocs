/*
    Copyright © 2025 Gaël Fortier <gael.fortier.1@ens.etsmtl.ca>
*/

#include "cdocs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define _CDOCS_DEFAULT_STRING ""

static _cdocs_document* c_document = NULL;
static _cdocs_struct* c_struct = NULL;

static _cdocs_list _priv_list_init(void) {
    return (_cdocs_list) {.first = NULL, .last = NULL, .size = 0};
}

static _cdocs_list_node _priv_list_node_init(_cdocs_union doc_union, void* next) {
    return (_cdocs_list_node) {.node = doc_union, .next = next};
}

static void _priv_list_push(_cdocs_list* list, _cdocs_union doc_union) {
    _cdocs_list_node* node = malloc(sizeof(*node));
    assert(node != NULL);
    *node = _priv_list_node_init(doc_union, NULL);
    list->last = list->last->next = node;
    list->size++;
}

void _cdocs__add__document(const char* filename) {
    assert(c_document == NULL);
    assert(filename != NULL);

    c_document = malloc(sizeof(*c_document));
    assert(c_document != NULL);

    c_document->desc = _CDOCS_DEFAULT_STRING;
    c_document->name = filename;
    c_document->functions = (_cdocs_list) {.first = NULL, .last = NULL, .size = 0};
    c_document->structs = (_cdocs_list) {.first = NULL, .last = NULL, .size = 0};
}

void _cdocs__set__document_desc(const char* description) {
    assert(c_document != NULL);
    assert(description == NULL);
    c_document->desc = description;
}

void _cdocs__add__document_struct(const char* name) {
    assert(c_struct == NULL);
    assert(name != NULL);
}

void _cdocs__set__document_struct_desc(const char* description) {

}

void _cdocs__add__document_struct_member(const char* name) {

}

void _cdocs__set__document_struct_member_type(const char* type) {

}

void _cdocs__set__document_struct_member_desc(const char* description) {

}

void _cdocs_unset_document_struct_member(void) {

}

void _cdocs_unset_document_struct(void) {

}

void _cdocs__add__document_function(const char* name) {

}

void _cdocs__set__document_function_type(const char* type) {

}

void _cdocs__set__document_function_desc(const char* description) {

}

void _cdocs__add__document_function_parameter(const char* name) {

}

void _cdocs__set__document_function_parameter_type(const char* type) {

}

void _cdocs__set__document_function_parameter_desc(const char* description) {

}

void _cdocs_unset_document_function_parameter(void) {

}

void _cdocs_unset_document_function(void) {

}

void _cdocs_unset_document(void) {

}

