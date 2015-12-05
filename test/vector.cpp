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
