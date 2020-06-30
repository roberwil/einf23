#include "array.h"

void build_array(){
    Array->init = init;
    Array->destroy = destroy;
    Array->is_empty = is_empty;
    Array->len = len;
    Array->unshift = unshift;
    Array->push = push;
    Array->shift = shift;
    Array->pop = pop;
}

void init(OArray array) {
    // The head and tail of the array point to nil
    array->start = array->end = nil;
    // The length o f the array is set to 0
    array->len = 0;
}

void destroy(OArray array) {
    Node nd = array->start, temp;

    //Loop every node of the array and free one at a time starting from the first one
    for (int i = 0; i < len(array); i++) {
        // Get the next node
        temp = nd->next;
        // Free the previous node
        free(nd);
        // Set the next node (used in the next iteration)
        nd = temp;
    }

    // Initialize the array
    init(array);
}

int is_empty(OArray array) {
    // Check whether the array is empty or not
    return array->len == 0 && array->start == nil && array->end == nil;
}

int len(OArray array) {
    // Returns the length of the array
    return array->len;
}

int unshift(OArray array, void* item) {
    // Create the node to be inserted
    Node node = (Node)malloc(sizeof(_node));
    // If, somehow, memory is not available
    if (node == nil) return FALSE;

    // Set the node item
    //TODO: item is generic now, adapt
    node->item = item;
    // The new head points to no previous node
    node->previous = nil;

    // if the array is empty
    if (is_empty(array)) {
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

int push(OArray array, void* item) {
    // Create the node to be inserted
    Node node = (Node)malloc(sizeof(_node));
    // If, somehow, memory is not available
    if (node == nil) return FALSE;
    // Set the node item
    //TODO: item is generic now, adapt
    node->item = item;
    // Since it is an insertion at the end, the node has to point to nowhere
    node->next = nil;

    if (is_empty(array)) {
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

int shift(OArray array) {
    // If the array is empty, there is nothing to remove
    if (is_empty(array)) return FALSE;

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

int pop(OArray array) {
    // If the array is empty, there is nothing to remove
    if (is_empty(array)) return FALSE;

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

