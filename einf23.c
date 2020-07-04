#include "einf23.h"

E23Class e23_init() {
    E23Class obj;

    // Read
    obj.Read = read_build();
    // Array
    obj.Array = array_build();


    return obj;
}