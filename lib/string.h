
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
#include "types.h"

typedef struct
{
	OStringArray (*split)(char dlm, int* number_of_tokens, OString);
	
    OString (*join)(char dlm, int number_of_string_to_join , ...);
	OString (*slice)(OString str, int start, int end);
	
    int (*is_digit)(OString str);
	int (*to_int)(OString str, int* value);
	int (*to_float)(OString str, int* value);
	int (*include)(OString str, OString substr);

	void (*destroy)(OString str);
	
    char (*is_of_type)();
} StringClass;

//Core types
StringClass str_build();

OStringArray str_split(char, int* , OString);

OString str_join(char, int  , ...);
OString str_slice(OString, int, int);

void str_destroy(OString str);

int str_is_digit(OString);
int str_to_int(OString, int* );
int str_to_float(OString, int* );
int str_include(OString, OString);

char str_is_of_type();

#endif




















