#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "types.h"

Class {
    int (*integer)(String, String);
	float (*floatn)(String, String);
	double (*doublen)(String, String);
} ReadClassWarning;

Class {
	String (*string)();
	String (*password)();
	
	int (*integer)();
	float (*floatn)();
	double (*doublen)();
	
	char (*character)();
	
	ReadClassWarning Warning;
}ReadClass;

ReadClass read_build ();

String  GetString();
String  GetPassword();

int GetInt();
int WGetInt (String text, String warning);
int IsNan();

float GetFloat();
float WGetFloat (String text, String warning);

double GetDouble();
double WGetDouble (String text, String warning);

char GetChar();

#endif




















