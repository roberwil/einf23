#include <stdio.h>
#include <stdlib.h>
#include "einf23.h"

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
    Read read = build_read();
    String str;
    int number;

    str = read.string();
    printf("%s\n", str);

    number = read.winteger("$", nil);
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

int main(int argc, char const *argv[])
{   
    List list;
    ListItem item;

    init(list);
    print_if(is_empty(list), "Empty", nil, nil);

    item.number = 12;
    insert_start(list, &item);

    item.number = 0;
    insert_start(list, &item);

    item.number = 1;
    insert_start(list, &item);

    item.number = 2;
    insert_end(list, &item);

    item.number = 5;
    insert_end(list, &item);

    item.number = 13;
    insert_end(list, &item);

    print_if(is_empty(list), "Empty", nil, nil);
    print(list);
    printf("Length: %d\n", len(list));

    remove_start(list);
    remove_end(list);

    print(list);
    printf("Length: %d\n", len(list));
    
    destroy(list);
    return 0;
}
