#include "einf23.h"

E23Class e23_init() {
    E23Class obj;

    obj.suicide = suicide;
    obj.Read = read_build();
    obj.Array = array_build();
    obj.Loop = loop_build();

    return obj;
}

// Collect garbage
void suicide() {

}