#include <stdlib.h>
#include "rand_utils.h"

int rand_int_0_6(void) {
    return rand() % 7;  // 0–6
}
