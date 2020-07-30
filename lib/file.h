#ifndef FILE_H
#define FILE_H

#include "types.h"

Bool each_line(OString path);
int no_lines(OString path);
OString read_lines(OString path);
OString read_line(OString path);

#endif