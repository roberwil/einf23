#include "loop.h"

//TODO: Negative ranges; 
//TODO: Ranges starting at 0
int range(int min, int max, int* counter) {
    static int start = 0, step = 1;
    
    if (min < 0) min *= -1;
    if (max < 0) max *= -1;

    if (start == 0) {
        start += min;
        if (min > max) step *= -1;
    } else
        start += step;

    *counter = start;

    if (start == max) {
        start = 0; step = 1;
        return FALSE;
    } else
        return TRUE;
}
