#pragma once

#include "vec.hpp"

namespace gml {
    struct Ray {
        Vec3 origin;
        Vec3 direction;

        Ray()
            : origin( Vec3( 0, 0, 0 ) )
            , direction( Vec3( 0, 0, -1 ) )
        {}

        Ray( Vec3 o, Vec3 d )
            : origin( o )
            , direction( d )
        {}

        inline Vec3 at( float t ) const { return origin + t * direction; }
    };

    struct Sphere {
        Vec3 center;
        float radius;
    };
}
