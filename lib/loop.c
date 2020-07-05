#include "loop.h"

LoopClass loop_build() {
    LoopClass obj;

    obj.range = loop_range;
    obj.range_with_step = loop_range_with_step;
    obj.each_int = loop_each_int;
    obj.each_int_with_index = loop_each_int_with_index; 
    obj.each_float = loop_each_float;
    obj.each_float_with_index = loop_each_float_with_index;
    obj.each_double = loop_each_double;
    obj.each_double_with_index = loop_each_double_with_index;
    obj.each_char = loop_each_char;
    obj.each_char_with_index = loop_each_char_with_index;  

    return obj;
}

int loop_range(int min, int max, int* counter) {
    return loop_range_with_step(min, max, 1, counter);
}
 
int loop_range_with_step(int min, int max, int step_value, int* counter) {
    static int start = 0, step = 1, is_start = TRUE;

    if (is_start) {
        is_start = FALSE; start += min;
        step = step_value;
        if (min > max) step *= -1;
    } else
        start += step;

    *counter = start;

    if ((step < 0 and start <= max) or (step > 0 and start >= max)) {
        // static variables maintain their values throughout function calls,
        // thus it is made a reset of them all
        *counter = 0;
        start = 0; step = 1; is_start = TRUE;
        return FALSE;
    } else
        return TRUE;
}

int loop_each_number(void* array, int size, void* value, LoopNumberType number_class) {
    static int pos = 0;

    switch (number_class) {
        case Integer:
            *(int*)value = *((int*)array + pos);
            break;
        case Float:
            *(float*)value = *((float*)array + pos);
            break;
        case Double:
            *(double*)value = *((double*)array + pos);
            break;
    }

    pos += 1;

    if (pos > size) {
        pos = 0;
        return FALSE;
    }
    else
        return TRUE;
}

int loop_each_index(int limit) {
    static int i = 0;
    int index;

    index = i; i += 1;
    if (i == limit) i = 0;

    return index;
}

int loop_each_int(int* array, int size, int* value) {
    return loop_each_number(array, size, value, Integer);
}

int loop_each_int_with_index(int* array, int size, int* value, int* index) {
    *index = loop_each_index(size);
    return loop_each_number(array, size, value, Integer);
}

int loop_each_float(float* array, int size, float* value) {
    return loop_each_number(array, size, value, Float);
}

int loop_each_float_with_index(float* array, int size, float* value, int* index) {
    *index = loop_each_index(size);
    return loop_each_number(array, size, value, Float);
}

int loop_each_double(double* array, int size, double* value) {
    return loop_each_number(array, size, value, Double);
}

int loop_each_double_with_index(double* array, int size, double* value, int* index) {
    *index = loop_each_index(size);
    return loop_each_number(array, size, value, Double);
}

int loop_each_char(String array, char* value) {
    static int pos = 0;

    *value = *(array + pos);
    pos += 1;

    if (*value equals END_STRING) {
        pos = 0;
        return FALSE;
    }
    else
        return TRUE;
}

int loop_each_char_with_index(char* array, char* value, int* index) {
    static int pos = 0;

    *value = *(array + pos);
    *index = pos;
    pos += 1;

    if (*value equals END_STRING) {
        pos = 0; *index = 0;
        return FALSE;
    }
    else
        return TRUE;
}
