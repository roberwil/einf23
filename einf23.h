
/*
* Based on the cs50.h library by University of Harvard
* Author: Ribeiro, Roberto W. P.
* Description: This header handles simple string manipulation
* hiding "c-noobs", at first, from the complexity of pointers
* as well as ...
* It defines a new type built essencially to declare Strings and
* read them from a terminal tab.
* Copyright Rober Wil © 2016  
*/

//define the header, if it was not defined
#ifndef EINF23_H
#define EINF23_H

  
//used library includes
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>

//constants definition
#define ENTER_KEY   10
#define TRUE        1
#define FALSE       0
#define INT        'i' 
#define FLOAT      'f'
#define END_STRING '\0'
#define nil         NULL
#define ERR_NAN    "Invalid number!"

//definition of "String" types
typedef char*  String;
typedef char** StringArray;

/*start*/

//Core Structs
typedef struct 
{
	String      (*string)    ();
	String      (*password)  ();
	int         (*integer)   ();
    int         (*winteger)  (String, String);
	float       (*floatn)    ();
    float       (*wfloatn)   (String, String);
	double      (*doublen)   ();
    double      (*wdoublen)  (String, String);
	char        (*character) ();
}Read;

typedef struct
{
	StringArray (*split)        (char, int*, String);
	String      (*join)         (char, int  , ...);
	String      (*slice)        (String, int, int);
	int         (*is_digit)     (String);
	int 		(*to_int)       (String, int* );
	int 		(*to_float)     (String, int* );
	int         (*include)      (String, String);
	char        (*is_of_type)   ();

}Str;


//Core types
typedef Str  StrObject;
typedef Read ReadObject;

//Core builders
ReadObject build_read ();
StrObject  build_str  ();

/*end*/

//functions signature

//core functions - input handling
String  GetString();
String  GetPassword();
int     GetInt();
int     WGetInt (String text, String warning);
float   GetFloat();
float   WGetFloat (String text, String warning);
double  GetDouble();
double  WGetDouble (String text, String warning);
char    GetChar();
int     IsNan();

//other features

//String handling
StringArray str_split        (char, int* , String);

String      str_join         (char, int  , ...);
String      str_slice        (String, int, int);

int         str_is_digit     (String);
int 		str_to_int       (String, int* );
int 		str_to_float     (String, int* );
int         str_include      (String, String);

char        str_is_of_type   ();

//other-other features
void new_lines(int n);

#endif




















