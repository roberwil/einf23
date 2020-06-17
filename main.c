#include <stdio.h>
#include <stdlib.h>
#include "einf23.h"

//Read input
void example1() {
    Read read = build_read();
    String str;
    int number;

    str = read.string();
    printf("%s\n", str);

    number = read.integer();
    printf("%d\n", number);
}

//loop.h -> Ranges
void example2() {
    int i;

    for (;range(-20, 10, &i);){
        printf("%d\n", i);
    }
    
    printf("\n\n");

    for (;range(10, -2, &i);){
        printf("%d\n", i);
    }

    printf("\n\n");

    while(range(0, 10, &i)) {
        printf("%d\n", i);
    }
    
    printf("\n\n");

    while(range_step(0, 10, 2, &i)) {
        printf("%d\n", i);
    }
    
    printf("\n\n");

    while(range_step(10, 21, 1, &i)) {
        printf("%d\n", i);
    }

}

//loop.h -> Each
void example3() {
    int array[] = {1, 2, 3, 4, 5};
    int value, size = 5;
    char c;

    for(;each_int(array, size, &value);){
        printf("%d\n", value);
    }

    printf("\n\n");
    
    for(;each_char("Hello, commit!", &c);){
        printf("%c\n", c);
    }
}

int main(int argc, char const *argv[])
{
    //example1();
    //example2();
    example3();
    return 0;
}
