
/*
* Based on the cs50.h library by University of Harvard
* Author: Ribeiro, Roberto W. P.
* Description: This header handles simple string manipulation
* hiding "c-noobs", at first, from the complexity of pointers
* It defines a new type built essencially to declare Strings and
* read them from a terminal tab.
*/

//define the header, if it was not defined
#ifndef STRING_H
#define STRING_H

//used library includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "lib/types.h"

typedef struct
{
	StringArray (*split)(char, int*, String);
	
    String (*join)(char, int  , ...);
	String (*slice)(String, int, int);
	
    int (*is_digit)(String);
	int (*to_int)(String, int* );
	int (*to_float)(String, int* );
	int (*include)(String, String);
	
    char (*is_of_type)();
}Str;

//Core types
typedef Str  StrObject;
StrObject  build_str  ();

StringArray str_split(char, int* , String);

String str_join(char, int  , ...);
String str_slice(String, int, int);

int str_is_digit(String);
int str_to_int(String, int* );
int str_to_float(String, int* );
int str_include(String, String);

char str_is_of_type();

#endif




















