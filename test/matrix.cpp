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
    Mat4 x = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    REQUIRE( x.m00 == 1 );
    REQUIRE( x.m01 == 2 );
    REQUIRE( x.m02 == 3 );
    REQUIRE( x.m03 == 4 );
    REQUIRE( x.m10 == 5 );
    REQUIRE( x.m11 == 6 );
    REQUIRE( x.m12 == 7 );
    REQUIRE( x.m13 == 8 );
    REQUIRE( x.m20 == 9 );
    REQUIRE( x.m21 == 10 );
    REQUIRE( x.m22 == 11 );
    REQUIRE( x.m23 == 12 );
    REQUIRE( x.m30 == 13 );
    REQUIRE( x.m31 == 14 );
    REQUIRE( x.m32 == 15 );
    REQUIRE( x.m33 == 16 );
}
