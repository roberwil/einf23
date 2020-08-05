#ifndef ARRAY_H
#define ARRAY_H

#include "types.h"
#include "loop.h"
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

    Bool (*get)(OArray array, int index, void* value);
    Bool (*set)(OArray array, int index, void* value);
    int (*each)(OArray array, void* value);
    int (*each_with_index)(OArray array, void* value, int* index);
    int (*is_empty)(OArray array);
    int (*len)(OArray array);

    int (*unshift)(OArray array, void* item);
    int (*push)(OArray array, void* item);

    int (*shift)(OArray array);
    int (*pop)(OArray array);

    ArrayItemFunctions Itemize;
} ArrayClass;

ArrayClass array_build();

/**
 * Creates an array of primitive elements
 * @type: the array type
 * @return the array 
 */ 
OArray array_init(ArrayType type);

/**
 * Creates a primitive array 
 * @array: the array to be converted to its primitive equivalent
 * @return the primitive array 
 */ 
void* array_origin(OArray array);

/**
 * Destroys the array
 * @array: the array to destroy
 */ 
void array_destroy(OArray array);

/**
 * Get an item from the array at a given position 
 * @array: the array to deal with
 * @index: the index of the element to get
 * @value: the place where to store the element at such index
 * @return True if the element exists, False if not 
 */ 
Bool array_get(OArray array, int index, void* value);

/**
 * Set/update an item in the array at a given position  
 * @array: the array to deal with
 * @index: the index of the element to set
 * @value: the element to set
 * @return True if the index is valid, False if not 
 */ 
Bool array_set(OArray array, int index, void* value);

/**
 * Iterate each item in the array 
 * @array: the array to deal with
 * @value: the place where to store the current item
 * @return False if the there are still items to iterate, True if not 
 */ 
int array_each(OArray array, void* value);

/**
 * Iterate each item in the array with respective indexes
 * @array: the array to deal with
 * @value: the place where to store the current item
 * @index: the index of the current item
 * @return False if the there are still items to iterate, True if not 
 */
int array_each_with_index(OArray array, void* value, int* index);

/**
 * Check if the array is empty
 * @array: the array to deal with
 * @return False if the array is no empty, True if yes 
 */
int array_is_empty(OArray array);

/**
 * Check the array size
 * @array: the array to deal with
 * @return the size of the array 
 */
int array_len(OArray array);

/**
 * Insert an item at the start of the array
 * @array: the array to deal with
 * @item: the item to insert
 * @return False if the insertion was not a success, True if it was 
 */
int array_unshift(OArray array, void* item);

/**
 * Insert an item at the end of the array
 * @array: the array to deal with
 * @item: the item to insert
 * @return False if the insertion was not a success, True if it was 
 */
int array_push(OArray array, void* item);

/**
 * Remove an item from the start of the array
 * @array: the array to deal with
 * @return False if the deletion was not a success, True if it was 
 */
int array_shift(OArray array);

/**
 * Remove an item from the start of the array
 * @array: the array to deal with
 * @return False if the deletion was not a success, True if it was 
 */
int array_pop(OArray array);

#endif