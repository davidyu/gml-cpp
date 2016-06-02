#include <stdint.h>

#include "mat.hpp"

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;

Mat4 fromRows( Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3 ) {
    Mat4 out;
    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[0][i] = r0.v[i];
    }

    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[1][i] = r1.v[i];
    }

    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[2][i] = r2.v[i];
    }

    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[3][i] = r3.v[i];
    }

    return out;
}

Mat4 fromCols( Vec4 c0, Vec4 c1, Vec4 c2, Vec4 c3 ) {
    Mat4 out;
    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[i][0] = c0.v[i];
    }

    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[i][1] = c1.v[i];
    }

    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[i][2] = c2.v[i];
    }

    for ( uint8 i = 0; i < 4; i++ ) {
        out.m[i][3] = c3.v[i];
    }

    return out;
}
