#ifndef READ_H
#define READ_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include "types.h"

typedef struct 
{
	String (*string)();
	String (*password)();
	
	int (*integer)();
    int (*winteger)(String, String);
	
	float (*floatn)();
    float (*wfloatn)(String, String);
	
	double (*doublen)();
    double (*wdoublen)(String, String);
	
	char (*character)();
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




















