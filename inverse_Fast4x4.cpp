#include <iostream>
#include "FAST4X4.h"

int main() {
    Matrix4 src;
    // preencher a matriz src
    src.m[0][0] = 1; src.m[0][1] = 2; src.m[0][2] = 3; src.m[0][3] = 4;
    src.m[1][0] = 5; src.m[1][1] = 6; src.m[1][2] = 7; src.m[1][3] = 8;
    src.m[2][0] = 2; src.m[2][1] = 6; src.m[2][2] = 4; src.m[2][3] = 8;
    src.m[3][0] = 3; src.m[3][1] = 1; src.m[3][2] = 1; src.m[3][3] = 2;

    Matrix4 dst;

    
    for (int i = 0; i < 1000000000; i++) {
        dst = GetInverse(src);
    
    }

    return 0;

}
