#pragma once

#include "vec.hpp"

typedef Vec<4> Color;

const Color white             = Vec4( 1, 1, 1, 1 );
const Color black             = Vec4( 0, 0, 0, 1 );
const Color transparent_black = Vec4( 0, 0, 0, 0 );

Color degamma( Color in );

inline Color degamma( Color in ) {
    Vec4 out = in;
    out ^= ( 1.0 / 2.2 );
    out.a = in.a;
    return out;
}
