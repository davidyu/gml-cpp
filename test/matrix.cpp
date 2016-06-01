#include "mat.hpp"
#include "lib/catch.hpp"

static const float EPSILON = 1e-6;

TEST_CASE( "base matrix accessors", "" ) {
    Mat<1,1> x = { 5 };
    REQUIRE( x[0] == 5 );
    x[0] = 9;
    REQUIRE( x[0] == 9 );

    Mat<2,2> xy = { 1, 2, 3, 4 };
    REQUIRE( xy[0] == 1 );
    REQUIRE( xy[1] == 2 );
    REQUIRE( xy[2] == 3 );
    REQUIRE( xy[3] == 4 );

    Mat<100,100> big;
    for ( int i = 0; i < 100; i++ ) big[i] = i;
    for ( int i = 0; i < 100; i++ ) REQUIRE( big[i] == i );
}

TEST_CASE( "structured matrix accessors", "" ) {
    Mat3 a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    REQUIRE( a.m00 == 1 );
    REQUIRE( a.m01 == 2 );
    REQUIRE( a.m02 == 3 );
    REQUIRE( a.m10 == 4 );
    REQUIRE( a.m11 == 5 );
    REQUIRE( a.m12 == 6 );
    REQUIRE( a.m20 == 7 );
    REQUIRE( a.m21 == 8 );
    REQUIRE( a.m22 == 9 );

    Mat4 b = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    REQUIRE( b.m00 == 1 );
    REQUIRE( b.m01 == 2 );
    REQUIRE( b.m02 == 3 );
    REQUIRE( b.m03 == 4 );
    REQUIRE( b.m10 == 5 );
    REQUIRE( b.m11 == 6 );
    REQUIRE( b.m12 == 7 );
    REQUIRE( b.m13 == 8 );
    REQUIRE( b.m20 == 9 );
    REQUIRE( b.m21 == 10 );
    REQUIRE( b.m22 == 11 );
    REQUIRE( b.m23 == 12 );
    REQUIRE( b.m30 == 13 );
    REQUIRE( b.m31 == 14 );
    REQUIRE( b.m32 == 15 );
    REQUIRE( b.m33 == 16 );
}
