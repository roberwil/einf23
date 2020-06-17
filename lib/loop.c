#include "loop.h"

int range(int min, int max, int* counter) {
    static int start = 0, step = 1, is_start = TRUE;

    if (is_start) {
        is_start = FALSE;
        start += min;
        if (min > max) step *= -1;
    } else
        start += step;

    *counter = start;

    if (start equals max) {
        start = 0; step = 1; is_start = TRUE;
        return FALSE;
    } else
        return TRUE;
}

int range_step(int min, int max, int step_value, int* counter) {
    static int start = 0, step = 1, is_start = TRUE;

    if (is_start) {
        is_start = FALSE; start += min;
        step = step_value;
        if (min > max) step *= -1;
    } else
        start += step;

    *counter = start;

    if ((step < 0 and start <= max) or (step > 0 and start >= max)) {
        *counter = 0;
        start = 0; step = 1; is_start = TRUE;
        return FALSE;
    } else
        return TRUE;
}

int each_number(void* array, int size, void* value, NumberClass number_class) {
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

int each_int(int* array, int size, int* value) {
    return each_number(array, size, value, Integer);
}

int each_float(float* array, int size, float* value) {
    return each_number(array, size, value, Float);
}

int each_double(double* array, int size, double* value) {
    return each_number(array, size, value, Double);
}

int each_char(String array, char* value) {
    static int pos = 0;

    *value = *(array + pos);
    pos += 1;

    if (*value equals END_STRING)
        return FALSE;
    else
        return TRUE;
}
