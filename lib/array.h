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

typedef struct _node {
    void* item;
    struct _node* previous;
    struct _node* next;
} _node;

typedef struct {
    ArrayType type;
    int len;
    _node *start, *end;
} _array;

typedef _node* Node;
typedef _array* OArray;

typedef struct {
    void (*init)(OArray array, ArrayType type);
    void (*destroy)(OArray array);

    int (*is_empty)(OArray array);
    int (*len)(OArray array);

    int (*unshift)(OArray array, void* item);
    int (*push)(OArray array, void* item);

    int (*shift)(OArray array);
    int (*pop)(OArray array);
} ArrayClass;

ArrayClass* Array;
void build_array();

void array_init(OArray array, ArrayType type);
void array_destroy(OArray array);

int array_is_empty(OArray array);
int array_len(OArray array);

int array_unshift(OArray array, void* item); //insert at start
int array_push(OArray array, void* item); //insert at end

int array_shift(OArray array); //remover from start
int array_pop(OArray array); //remove from the end

#endif