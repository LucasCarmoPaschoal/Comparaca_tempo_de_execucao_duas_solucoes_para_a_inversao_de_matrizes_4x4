#include <iostream>
#include "invert4x4_llvm.h"

int main() {
    float src[16] = {
        1, 2, 3, 4,
        5, 6, 7, 8,
        2, 6, 4, 8,
        3, 1, 1, 2
    };

    float dst[16]; 

    
    for (int i = 0; i < 1000000000; i++) {
        invert4x4(src, dst);
    }
    
    return 0;
}