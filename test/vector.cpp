#include "vec.hpp"
#include "lib/catch.hpp"

TEST_CASE( "base vector accessors", "" ) {
    Vec<1> x = { 5 };
    REQUIRE( x[0] == 5 );
    x[0] = 9;
    REQUIRE( x[0] == 9 );

    Vec<2> xy = { 1, 2 };
    REQUIRE( xy[0] == 1 );
    REQUIRE( xy[1] == 2 );

    Vec<100> big;
    for ( int i = 0; i < 100; i++ ) big[i] = i;
    for ( int i = 0; i < 100; i++ ) REQUIRE( big[i] == i );
}

TEST_CASE( "structured vector accessors", "" ) {
    Vec2 xy = { 1, 2 };
    REQUIRE( xy.x == 1 );
    REQUIRE( xy.y == 2 );

    xy.x = 3;
    xy.y = 4;
    REQUIRE( xy.x == 3 );
    REQUIRE( xy.y == 4 );

    Vec3 xyz = { 5, 6, 7 };
    REQUIRE( xyz.x == 5 );
    REQUIRE( xyz.y == 6 );
    REQUIRE( xyz.z == 7 );
    REQUIRE( xyz.r == 5 );
    REQUIRE( xyz.g == 6 );
    REQUIRE( xyz.b == 7 );
    REQUIRE( xyz.xy.x == 5 );
    REQUIRE( xyz.xy.y == 6 );

    Vec4 xyzw = { 9, 10, 11, 12 };
    REQUIRE( xyzw.x == 9 );
    REQUIRE( xyzw.y == 10 );
    REQUIRE( xyzw.z == 11 );
    REQUIRE( xyzw.w == 12 );
    REQUIRE( xyzw.r == 9 );
    REQUIRE( xyzw.g == 10 );
    REQUIRE( xyzw.b == 11 );
    REQUIRE( xyzw.a == 12 );
    REQUIRE( xyzw.xy.x == 9 );
    REQUIRE( xyzw.xy.y == 10 );
    REQUIRE( xyzw.xyz.x == 9 );
    REQUIRE( xyzw.xyz.y == 10 );
    REQUIRE( xyzw.xyz.z == 11 );
}

TEST_CASE( "vector operations", "" ) {
    Vec2 a = { 1, 2 };
    Vec2 b = { 3, 4 };
    Vec2 c = a + b;

    REQUIRE( c.x == 4 );
    REQUIRE( c.y == 6 );

    Vec3 d = { 5, 6, 7 };
    Vec3 e = { 8, 9, 10 };
    Vec3 f = d * e;

    REQUIRE( f.x == 40 );
    REQUIRE( f.y == 54 );
    REQUIRE( f.z == 70 );

    Vec4 g = { 15, 16, 17, 18 };
    Vec4 h = { 11, 12, 13, 14 };
    Vec4 i = g - h;

    REQUIRE( i.x == 4 );
    REQUIRE( i.y == 4 );
    REQUIRE( i.z == 4 );
    REQUIRE( i.w == 4 );

    Vec<5> j = { 19 * 2, 20 * 2, 21 * 2, 22 * 2, 23 * 2 };
    Vec<5> k = { 19, 20, 21, 22, 23 };
    Vec<5> l = j / k;

    REQUIRE( l[0] == 2 );
    REQUIRE( l[1] == 2 );
    REQUIRE( l[2] == 2 );
    REQUIRE( l[3] == 2 );
    REQUIRE( l[4] == 2 );

    Vec<6> m = { 19 * 2, 20 * 2, 21 * 2, 22 * 2, 23 * 2, 24 * 2 };
    float n = 2;
    Vec<6> o = m / n;

    REQUIRE( o[0] == 19 );
    REQUIRE( o[1] == 20 );
    REQUIRE( o[2] == 21 );
    REQUIRE( o[3] == 22 );
    REQUIRE( o[4] == 23 );
    REQUIRE( o[5] == 24 );

    Vec<6> p = { 19, 20, 21, 22, 23, 24 };
    float q = 2;
    Vec<6> r = p * q;

    REQUIRE( r[0] == 38 );
    REQUIRE( r[1] == 40 );
    REQUIRE( r[2] == 42 );
    REQUIRE( r[3] == 44 );
    REQUIRE( r[4] == 46 );
    REQUIRE( r[5] == 48 );
}
