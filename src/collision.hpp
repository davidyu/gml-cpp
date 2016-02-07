#pragma once

#include "primitives.hpp"

namespace gml {
    namespace Collision {
        // returns number of intersection points with the sphere
        // if the ray starts inside the sphere, it is considered not to intersect with the sphere.
        int IntersectRaySphere( const Ray r, const Sphere o, float& t, Vec3& intersection );
    }
}
