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
    OString str;
    int number;

    str = e23.Read.string();
    printf("%s\n", str);

    number = e23.Read.Warning.integer("$", nil);
    printf("%d\n", number);
}

//loop.h -> Ranges
void example2() {
    int i;

    for (;e23.Loop.range(-20, 10, &i);){
        printf("%d\n", i);
    }
    
    printf("\n\n");

    for (;e23.Loop.range(10, -2, &i);){
        printf("%d\n", i);
    }

    printf("\n\n");

    while(e23.Loop.range(0, 10, &i)) {
        printf("%d\n", i);
    }
    
    printf("\n\n");

    while(e23.Loop.range_with_step(0, 10, 2, &i)) {
        printf("%d\n", i);
    }
    
    printf("\n\n");

    while(e23.Loop.range_with_step(10, 21, 1, &i)) {
        printf("%d\n", i);
    }

}

//loop.h -> Each
void example3() {
    int iarray[] = {1, 2, 3, 4, 5};
    int value, index, size = 5;
    char c;

    for(;e23.Loop.each_int(iarray, size, &value);){
        printf("%d ", value);
    }

    printf("\n\n");

    for(;e23.Loop.each_int_with_index(iarray, size, &value, &index);){
        printf("array[%d] = %d\n", index, value);
    }    

    printf("\n");
    
    for(;e23.Loop.each_char("Hello, commit!", &c);){
        printf("%c ", c);
    }

    printf("\n");

    for(;e23.Loop.each_char_with_index("Hello, commit!", &c, &index);){
        printf("string[%d] = %c\n", index, c);
    }
}

//array.c
void example4() {
    
    OArray numbers = e23.Array.init(ArrayInt);
    int item, index;

    printf("%d\n", e23.Array.len(numbers));
    print_if(e23.Array.is_empty(numbers), "Empty?", nil, nil);

    e23.Array.push(numbers, e23.Array.Itemize.Int(90));
    e23.Array.push(numbers, e23.Array.Itemize.Int(11));
    e23.Array.push(numbers, e23.Array.Itemize.Int(67));

    e23.Array.unshift(numbers, e23.Array.Itemize.Int(43));
    e23.Array.unshift(numbers, e23.Array.Itemize.Int(53));
    e23.Array.unshift(numbers, e23.Array.Itemize.Int(78));

    printf("%d\n", e23.Array.len(numbers));
    print_if(e23.Array.is_empty(numbers), "Empty?", nil, nil);

    printf("print powered by -> Loop.each_int, Array.origin\n");
    while(e23.Loop.each_int(e23.Array.origin(numbers), e23.Array.len(numbers), &item)) {
        printf("%d\n", item);
    }

    e23.Array.shift(numbers);
    e23.Array.pop(numbers);

    printf("%d\n", e23.Array.len(numbers));
    print_if(e23.Array.is_empty(numbers), "Empty?", nil, nil);

    printf("print powered by -> Array.each\n");
    while(e23.Array.each(numbers, &item)) {
        printf("%d\n", item);
    }

    e23.Array.set(numbers, 1, e23.Array.Itemize.Int(66));
    e23.Array.set(numbers, 2, e23.Array.Itemize.Int(70));

    printf("print powered by -> Loop.range, Array.get\n");
    while(e23.Loop.range(0, e23.Array.len(numbers), &index)){
        e23.Array.get(numbers, index, &item);
        printf("%d\n", item);
    }

    e23.Array.destroy(numbers);

}

// string.h
void example5() {

}

void example6() {
    
}

void example7(){

}

int main(int argc, char const *argv[])
{   
    e23 = e23_init();

    //example1();
    //example2();
    //example3();
    example4();

    e23.suicide();
    return 0;
}
