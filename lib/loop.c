#include "loop.h"

int range(int min, int max, int* counter) {
    static int start = 0;
    int step = 1;
    
    if (start == 0) 
        start += min;
    else
        start += step;

    *counter = start;

    if (start == max)
        return FALSE;
    else
        return TRUE;
}
