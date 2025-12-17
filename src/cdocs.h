/*
    Copyright © 2025 Gaël Fortier <gael.fortier.1@ens.etsmtl.ca>
*/

#pragma once
#include <stddef.h>

typedef struct _cdocs_document _cdocs_document;
typedef struct _cdocs_function _cdocs_function;
typedef struct _cdocs_struct _cdocs_struct;
typedef struct _cdocs_member _cdocs_member;
typedef struct _cdocs_parameter _cdocs_parameter;
typedef union _cdocs_union _cdocs_union;
typedef struct _cdocs_list _cdocs_list;
typedef struct _cdocs_list_node _cdocs_list_node;

struct _cdocs_list {
    _cdocs_list_node* first;
    _cdocs_list_node* last;
    size_t size;
};

struct _cdocs_document {
    const char* name;
    const char* desc;
    _cdocs_list functions;
    _cdocs_list structs;
};

struct _cdocs_parameter {
    const char* type;
    const char* name;
    const char* desc;
};

struct _cdocs_function {
    const char* type;
    const char* name;
    const char* desc;
    _cdocs_list parameters;
};

struct _cdocs_member {
    const char* type;
    const char* name;
    const char* desc;
};

struct _cdocs_struct {
    const char* name;
    const char* desc;
    _cdocs_list members;
};

union _cdocs_union {
    _cdocs_document doc;
    _cdocs_function fn;
    _cdocs_member member;
    _cdocs_struct type;
    _cdocs_parameter param;
};

struct _cdocs_list_node {
    _cdocs_union node;
    _cdocs_list_node* next;
};

void _cdocs__add__document(const char* filename);
void _cdocs__set__document_desc(const char* description);
void _cdocs__add__document_struct(const char* name);
void _cdocs__set__document_struct_desc(const char* description);
void _cdocs__add__document_struct_member(const char* name);
void _cdocs__set__document_struct_member_type(const char* type);
void _cdocs__set__document_struct_member_desc(const char* description);
void _cdocs_unset_document_struct_member(void);
void _cdocs_unset_document_struct(void);
void _cdocs__add__document_function(const char* name);
void _cdocs__set__document_function_type(const char* type);
void _cdocs__set__document_function_desc(const char* description);
void _cdocs__add__document_function_parameter(const char* name);
void _cdocs__set__document_function_parameter_type(const char* type);
void _cdocs__set__document_function_parameter_desc(const char* description);
void _cdocs_unset_document_function_parameter(void);
void _cdocs_unset_document_function(void);
void _cdocs_unset_document(void);
