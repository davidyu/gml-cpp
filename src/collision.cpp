#include "collision.hpp"

int gml::Collision::IntersectRaySphere( const gml::Ray    r
                                      , const gml::Sphere o
                                      , float&            t
                                      , Vec3&             pt
                                      , Vec3&             normal ) {
    Vec3 d = normalize( r.direction ); // dot( d, d ) is 1 => saves some unnecessary dot products
    Vec3 p = r.origin - o.center;

    float b = dot( p, d );
    float c = dot( p, p ) - o.radius * o.radius;

    // early exit; r starts outside o, but r points away from o
    if ( c > 0 && b > 0 ) return 0;

    float discr = b*b - c;

    // r misses o
    if ( discr < 0 ) return 0;

    t = -b - sqrt( discr );

    // r starts inside o
    if ( t < 0 ) return 0;

    pt = r.at( t );
    normal = normalize( pt - o.center );

    return 1;
}
