#include "collision.hpp"

int gml::Collision::IntersectRaySphere( const Ray r, const Sphere o, float& t, Vec3& intersection ) {
    Vec3 d = normalize( r.direction ); // dot( d, d ) is 1 => saves some unnecessary dot products
    Vec3 p = o.center - r.origin;

    float b = dot( p, d );
    float c = dot( p, p ) - o.radius * o.radius;

    // early exit; r starts outside o, but r points away from o
    if ( c > 0 && b > 0 ) return 0;

    float discr = b - c;

    // r misses o
    if ( discr < 0 ) return 0;

    t = -b - sqrt( discr );

    // r starts inside o
    if ( t < 0 ) return 0;

    intersection = r.at( t );

    return 1;
}
