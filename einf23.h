
/*
* Based on the cs50.h library by University of Harvard
* Author: Ribeiro, Roberto W. P.
* Description: This header handles simple string manipulation
* hiding "c-noobs", at first, from the complexity of pointers
* It defines a new type built essencially to declare Strings and
* read them from a terminal tab.
*/

#ifndef EINF23_H
#define EINF23_H

#include "lib/read.h"
#include "lib/string.h"
#include "lib/loop.h"
#include "lib/array.h"
#include "lib/bool.h"
#include "lib/garbage_collector.h"
#include "lib/file.h"
#include "lib/regex.h"

Class {
    ArrayClass Array;
    ReadClass Read;
    LoopClass Loop;
    void (*suicide)();
} E23Class;

E23Class e23_init();
void suicide();

#endif




















