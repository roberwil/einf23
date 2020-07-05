#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"
#include <stdio.h>
#include <stdlib.h>
typedef enum {
    ArrayInt = 1,
    ArrayFloat,
    ArrayDouble,
    ArrayChar
} ArrayType;

typedef struct ArrayItem {
    int Int; float Float; double Double;
    char Char;
} ArrayItem;

typedef struct array_node {
    ArrayItem item;
    int index;
    struct array_node* previous;
    struct array_node* next;
} array_node;

typedef struct _array {
    array_node* start;
    array_node* end;
    ArrayType type;
    int len;
} _array;

typedef array_node* Node;
typedef _array* OArray;

typedef struct {
    int* (*Int)(int item);
    float* (*Float)(float item);
    double* (*Double)(double item);
    char* (*Char)(char item);
} ArrayItemFunctions;

typedef struct {
    OArray (*init)(ArrayType type);
    void* (*origin)(OArray array);
    void (*destroy)(OArray array);

    int (*is_empty)(OArray array);
    int (*len)(OArray array);

    int (*unshift)(OArray array, void* item);
    int (*push)(OArray array, void* item);

    int (*shift)(OArray array);
    int (*pop)(OArray array);

    ArrayItemFunctions Itemize;
} ArrayClass;

ArrayClass array_build();

OArray array_init(ArrayType type);
void* array_origin(OArray array);
void array_destroy(OArray array);

int array_is_empty(OArray array);
int array_len(OArray array);

int array_unshift(OArray array, void* item); //insert at start
int array_push(OArray array, void* item); //insert at end

int array_shift(OArray array); //remover from start
int array_pop(OArray array); //remove from the end

#endif