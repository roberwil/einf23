#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "types.h"

Class {
    int (*integer)(OString text, OString warning);
	float (*floatn)(OString text, OString warning);
	double (*doublen)(OString text, OString warning);
} ReadClassWarning;

Class {
	OString (*string)();
	OString (*password)();
	
	int (*integer)();
	float (*floatn)();
	double (*doublen)();
	
	char (*character)();
	
	ReadClassWarning Warning;
}ReadClass;

ReadClass read_build ();

OString  GetString();
OString  GetPassword();

int GetInt();
int WGetInt (OString text, OString warning);
int IsNan();

float GetFloat();
float WGetFloat (OString text, OString warning);

double GetDouble();
double WGetDouble (OString text, OString warning);

char GetChar();

#endif




















