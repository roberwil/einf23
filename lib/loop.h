#ifndef LOOP_H
#define LOOP_H

#include "types.h"
#include <stdlib.h>
#include <stdio.h>

int range(int min, int max, int* counter);
int range_step(int min, int max, int _step, int* counter);

int each_int(int* array, int size, int* value);
int each_char(String array, char* value);

#endif