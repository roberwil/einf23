#include <stdio.h>
#include <stdlib.h>
#include "einf23.h"

int main(int argc, char const *argv[])
{
    Read read = build_read();
    String str;

    str = read.string();
    printf("%s", str);

    return 0;
}
