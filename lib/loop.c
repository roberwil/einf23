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

    if (start == max) {
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

int each_int(int* array, int size, int* value) {
    static int pos = 0;

    *value = *(array + pos);
    pos += 1;

    if (pos > size)
        return FALSE;
    else
        return TRUE;
}

int each_char(String array, char* value) {
    static int pos = 0;

    *value = *(array + pos);
    pos += 1;

    if (*value == END_STRING)
        return FALSE;
    else
        return TRUE;
}

int each_float(float* array, int size, float* value) {
    return FALSE;
}

int each_double(float* array, int size, float* value) {
    return FALSE;
}
