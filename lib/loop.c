#include "loop.h"

int range(int min, int max, int* counter) {
    static int start = 0;
    
    if (start == 0) 
        start += min;
    else
        start += 1;

    *counter = start;

    if (start == max)
        return TRUE;
    else
        return FALSE;
}
