#include "array.h"

int* itemize_int(int item){int *pitem = &item; return pitem;}
float* itemize_float(float item){float *pitem; return pitem;}
double* itemize_double(double item){double *pitem; return pitem;}
char* itemize_char(char item){char *pitem; return pitem;}

OArray array_init(ArrayType type) {
    OArray array = (OArray)malloc(sizeof(_array));
    // set the array type
    array->type = type;
    // The head and tail of the array point to nil
    array->start = array->end = nil;
    // The length o f the array is set to 0
    array->len = 0;

    return array;
}

void array_destroy(OArray array) {
    Node node = array->start, temp;

    //Loop every node of the array and free one at a time starting from the first one
    for (int i = 0; i < array_len(array); i++) {
        // Get the next node
        temp = node->next;
        // Free the previous node
        free(node);
        // Set the next node (used in the next iteration)
        node = temp;
    }
}

void array_insert_type_decode(Node node, void* item, ArrayType type) {
    switch(type) {
        case ArrayInt:
            node->item.Int = *(int*)item;
        case ArrayFloat:
            node->item.Float = *(float*)item;
        case ArrayDouble:
            node->item.Double = *(double*)item;
        case ArrayChar:
            node->item.Char = *(char*)item;
        break;
    }
}

void array_retrieve_type_decode(Node node, void* item, ArrayType type) {
    switch(type) {
        case ArrayInt:
           *(int*)item = node->item.Int;
        case ArrayFloat:
           *(float*)item = node->item.Float;
        case ArrayDouble:
           *(double*)item = node->item.Double;
        case ArrayChar:
           *(char*)item = node->item.Char;
        break;
    }
}


Bool array_get(OArray array, int index, void* value) {
    
    int len = array_len(array);
    if(index >= len) return false;

    int middle = (int)len/2;
    Node node; 
    
    if (index <= middle) {
        node = array->start;
        for (int i = 0; i < len; i++) {
            if (i == index) {
                switch(array->type) {
                    case ArrayInt:
                        *(int*)value = node->item.Int;
                    break;

                    case ArrayFloat:
                        *(float*)value = node->item.Float;
                    break;

                    case ArrayDouble:
                        *(double*)value = node->item.Double;
                    break;

                    case ArrayChar:
                        *(char*)value = node->item.Char;
                    break;
                }

                break; 
            }
            node = node->next;
        }
    } else {
        node = array->end;
        for (int i = len - 1; i >= 0; i--) {
            if (i == index) {
                *(int*)value = node->item.Int;
                break; 
            }
            node = node->previous;
        }
    }

    return true;
}

Bool array_set(OArray array, int index, void* value) {
    return true;
}

int array_each(OArray array, void* value) {
    switch (array->type) {
        case ArrayInt: {
            return loop_each_int(array_origin(array), array_len(array), value);
        } break;

        case ArrayFloat: {
            return loop_each_float(array_origin(array), array_len(array), value);
        } break;

        case ArrayDouble: {
            return loop_each_double(array_origin(array), array_len(array), value);
        } break;

        case ArrayChar: {
            return loop_each_char(array_origin(array), value);
        } break;
    }
}

int array_each_with_index(OArray array, void* value, int* index) {
    switch (array->type) {
        case ArrayInt: {
            return loop_each_int_with_index(array_origin(array), array_len(array), value, index);
        } break;

        case ArrayFloat: {
            return loop_each_float_with_index(array_origin(array), array_len(array), value, index);
        } break;

        case ArrayDouble: {
            return loop_each_double_with_index(array_origin(array), array_len(array), value, index);
        } break;

        case ArrayChar: {
            return loop_each_char_with_index(array_origin(array), value, index);
        } break;
    }
}

int array_is_empty(OArray array) {
    // Check whether the array is empty or not
    return array->len == 0 && array->start == nil && array->end == nil;
}

int array_len(OArray array) {
    // Returns the length of the array
    return array->len;
}

int array_unshift(OArray array, void* item) {
    // Create the node to be inserted
    Node node = (Node)malloc(sizeof(array_node));
    // If, somehow, memory is not available
    if (node == nil) return FALSE;

    // Set the node item
    array_insert_type_decode(node, item, array->type);
    node->index = array_len(array);

    // The new head points to no previous node
    node->previous = nil;

    // if the array is empty
    if (array_is_empty(array)) {
        // The head is the tail
        array->end = node;
        // the head and the tail have no next or previous node
        node->next = nil;
    } else {
        // The new node now points to the old head
        node->next = array->start;
        // The old head has the new head as the previous node
        array->start->previous = node;
    }

    // The new node becomes the head
    array->start = node;
    // The length of the array increases
    array->len++;

    return TRUE;
}

int array_push(OArray array, void* item) {
    // Create the node to be inserted
    Node node = (Node)malloc(sizeof(array_node));
    // If, somehow, memory is not available
    if (node == nil) return FALSE;
    
    // Set the node item
    array_insert_type_decode(node, item, array->type);
    
    // Since it is an insertion at the end, the node has to point to nowhere
    node->next = nil;

    if (array_is_empty(array)) {
        // if the array is empty, the head and the tail have to be the same
        array->start = node;
        // There is no previous node to point to
        node->previous = nil;
    } else {
        // the old tail has as next node the new tail 
        array->end->next = node;
        // The new tail has as previous node the old tail
        node->previous = array->end;
    }

    // The new node becomes the tail
    array->end = node;
    // The length of the array increases
    array->len++;

    return TRUE;
}

int array_shift(OArray array) {
    // If the array is empty, there is nothing to remove
    if (array_is_empty(array)) return FALSE;

    // Get the first node
    Node first_node = array->start;

    if (array->start == array->end)
        // if array is of length 1, then the head and the tail must point to nowhere
        array->start = array->end = nil;
    else {
        // the node pointed by the old head becomes the head
        array->start = array->start->next;
        // the first node has no previous node
        array->start->previous =  nil;
    }

    // Free the old head
    free(first_node);
    // The length of the array decreases
    array->len--;

    return TRUE;
}

int array_pop(OArray array) {
    // If the array is empty, there is nothing to remove
    if (array_is_empty(array)) return FALSE;

    // If the array is of size of 1
    if (array->start == array->end) {
        // Free the single node
        free(array->start);
        // Head an tail point to nowhere
        array->start = array->end = nil;
    } else {
        // Get the last node
        Node last_node = array->end;
        // The penultimate node, which is the previous node of the last node, is now the last node 
        array->end = last_node->previous;
        // The new tail has no next node
        array->end->next = nil;
        // Free the old tail
        free(last_node);
    }

    // The length of the array decreases
    array->len--;

    return TRUE;
}

void* array_origin(OArray array) {
    void* result = nil;

    Node node = array->start; 
    int len = array_len(array);

    switch(array->type) {
        case ArrayInt: {
            int* items = (int*)calloc(len, sizeof(int));

            for (int i = 0; i < len; i++) {
                *(items + i) = node->item.Int;
                node = node->next;
            }

            result = items;
        } break;

        case ArrayFloat: {
            float* items = (float*)calloc(len, sizeof(float));

            for (int i = 0; i < len; i++) {
                *(items + i) = node->item.Float;
                node = node->next;
            }

            result = items;
        } break;

        case ArrayDouble: {
            double* items = (double*)calloc(len, sizeof(double));

            for (int i = 0; i < len; i++) {
                *(items + i) = node->item.Double;
                node = node->next;
            }

            result = items;
        } break;

        case ArrayChar: {
            char* items = (char*)calloc(len, sizeof(char));

            for (int i = 0; i < len; i++) {
                *(items + i) = node->item.Char;
                node = node->next;
            }

            result = items;
        } break;
    }

    return result;
}

ArrayClass array_build(){
    ArrayClass obj;
    
    obj.init = array_init;
    obj.destroy = array_destroy;
    obj.origin = array_origin;

    obj.each = array_each;
    obj.each_with_index = array_each_with_index;
    obj.get = array_get;
    obj.set = array_set;
    obj.is_empty = array_is_empty;
    obj.len = array_len;

    obj.unshift = array_unshift;
    obj.push = array_push;
    obj.shift = array_shift;
    obj.pop = array_pop;

    obj.Itemize.Int = itemize_int;
    obj.Itemize.Float = itemize_float;
    obj.Itemize.Double = itemize_double;
    obj.Itemize.Char = itemize_char;
    
    return obj;
}