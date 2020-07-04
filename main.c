#include <stdio.h>
#include <stdlib.h>
#include "einf23.h"

E23Class e23;

void print_if(int condition, char* title, char* yes, char* no) {

    #ifndef nil
    #define nil NULL
    #endif

    if (title != nil) 
        printf("%s = ", title);

    if (condition) {
        if (yes == nil)
            printf("Yes!\n");
        else
            printf("%s", yes);
    } else {
        if (no == nil)
            printf("No!\n");
        else 
            printf("%s", no);
    }

}

//Read input
void example1() {
    String str;
    int number;

    str = e23.Read.string();
    printf("%s\n", str);

    number = e23.Read.Warning.integer("$", nil);
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

    while(range_with_step(0, 10, 2, &i)) {
        printf("%d\n", i);
    }
    
    printf("\n\n");

    while(range_with_step(10, 21, 1, &i)) {
        printf("%d\n", i);
    }

}

//loop.h -> Each
void example3() {
    int iarray[] = {1, 2, 3, 4, 5};
    int value, index, size = 5;
    char c;

    for(;each_int(iarray, size, &value);){
        printf("%d ", value);
    }

    printf("\n\n");

    for(;each_int_with_index(iarray, size, &value, &index);){
        printf("array[%d] = %d\n", index, value);
    }    

    printf("\n");
    
    for(;each_char("Hello, commit!", &c);){
        printf("%c ", c);
    }

    printf("\n");

    for(;each_char_with_index("Hello, commit!", &c, &index);){
        printf("string[%d] = %c\n", index, c);
    }
}

//array.c
void example4() {
    OArray numbers = e23.Array.init(ArrayInt);

    printf("%d\n", e23.Array.len(numbers));
    print_if(e23.Array.is_empty(numbers), "Empty?", nil, nil);
}

int main(int argc, char const *argv[])
{   
    e23 = e23_init();

    example1();
    //example2();
    //example3();
    //example4();

    return 0;
}
