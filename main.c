#include <stdio.h>
#include <stdlib.h>
#include "einf23.h"

void example1() {
    Read read = build_read();
    String str;
    int number;

    str = read.string();
    printf("%s\n", str);

    number = read.integer();
    printf("%d\n", number);
}

void example2() {
    int i;

    for (;range(2, 10, &i);){
        printf("%d\n", i);
    }
}

int main(int argc, char const *argv[])
{
    //example1();
    example2();
    return 0;
}
