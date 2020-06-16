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

int range_step(int min, int max, int _step, int* counter) {
    static int start = 0, step = 1, is_start = TRUE;

    if (is_start) {
        is_start = FALSE;
        start += min;
        step = _step;
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
