#pragma once

#include "vec.hpp"

// a color (r,g,b,a) is basically a Vec4
typedef Vec<4> Color;

// basic color definitions
const Color white             = Vec4( 1, 1, 1, 1 );
const Color black             = Vec4( 0, 0, 0, 1 );
const Color transparent_black = Vec4( 0, 0, 0, 0 );

inline Color engamma( const Color in ) {
    Vec4 out = in;
    out ^= 2.2;
    out.a = in.a;
    return out;
}

inline Color degamma( const Color in ) {
    Vec4 out = in;
    out ^= ( 1.0 / 2.2 );
    out.a = in.a;
    return out;
}
