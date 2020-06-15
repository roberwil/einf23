#include "loop.h"

//TODO: Negative ranges; 
int range(int min, int max, int* counter) {
    static int start = 0, step = 1, is_start = TRUE;
    
    if (min < 0) min *= -1;
    if (max < 0) max *= -1;

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
