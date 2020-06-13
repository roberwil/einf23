#include <stdio.h>
#include <stdlib.h>
#include "einf23.h"

int main(int argc, char const *argv[])
{
    Read read = build_read();
    String str;
    int number;

    str = read.string();
    printf("%s\n", str);

    number = read.integer();
    printf("%d\n", number)

    return 0;
}
