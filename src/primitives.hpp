#pragma once

#include "vec.hpp"

struct Ray {
    Vec3 origin;
    Vec3 direction;
    inline Vec3 at( float t ) const { return origin + t * direction; }
};

struct Sphere {
    Vec3 center;
    float radius;
};
