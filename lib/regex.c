#include "regex.h"

Bool match(OString pattern, OString token){
    return true;
}

OString replace(OString pattern, OString token) {
    return EMPTY_STR;
}

OStringArray search(OString pattern) {
    return EMPTY_STR;
}

RegexClass regex_build() {
    RegexClass rgx;
    rgx.match = match;
    rgx.replace = replace;
    rgx.search = search;
    return rgx;
}