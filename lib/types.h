#ifndef TYPES_H
#define TYPES_H

#define ENTER_KEY   10
#define TRUE        1
#define FALSE       0
#define INT        'i' 
#define FLOAT      'f'
#define END_STRING '\0'
#define nil         NULL
#define or          ||
#define and         &&
#define equals      ==
#define ERR_NAN    "Invalid number!"

typedef enum {
    Integer = 1,
    Float,
    Double  
} NumberClass;

typedef char*  String;
typedef char** StringArray;

#endif