#pragma once

#include "primitives.hpp"

namespace gml {
    // NOTE: if the ray starts inside the sphere, it will be considered not to intersect with the sphere.
    bool IntersectRaySphere( const gml::Ray    r
                           , const gml::Sphere o
                           , float&            t
                           , Vec3&             pt
                           , Vec3&             normal );


    bool IntersectRayPlane( const gml::Ray   r
                          , const gml::Plane pl
                          , float&           t
                          , Vec3&            pt
                          , Vec3&            normal );
}
