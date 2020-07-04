#include "einf23.h"

E23Class e23_init() {
    E23Class obj;

    obj.Read = read_build();
    obj.Array = array_build();

    return obj;
}