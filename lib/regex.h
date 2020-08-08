#ifndef REGEX_H
#define REGEX_H
#include "types.h"

typedef struct {
    OString pattern;
    OStringArray rules;
} ORegex;

Class {
    Bool (*match)(OString pattern, OString token);
    OString (*replace)(OString pattern, OString token);
    OStringArray (*search)(OString pattern);
} RegexClass;

RegexClass regex_build();

Bool match(OString pattern, OString token);
OString replace(OString pattern, OString token);
OStringArray search(OString pattern);

#endif