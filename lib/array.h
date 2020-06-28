#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    Int = 1,
    Float,
    Double,
    Char
} ArrayType;

typedef struct {
    int number;
} ArrayItem;

typedef struct node {
    ArrayItem item;
    void* _item;
    struct node* previous;
    struct node* next;
} node;

typedef struct {
    node* start;
    node* end;
    ArrayType type;
    int len;
} array;

typedef node* Node;
typedef array* Array;

void init(Array array);
void destroy(Array array);

int is_empty(Array array);
int len(Array array);

int unshift(Array array, void* item);
int push(Array array, void* item);

int shift(Array array); //remover from start
int pop(Array array); //remove from the end

#endif