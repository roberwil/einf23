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

