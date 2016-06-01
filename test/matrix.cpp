#include "mat.hpp"
#include "lib/catch.hpp"

static const float EPSILON = 1e-6;

TEST_CASE( "simple matrix constructors", "" ) {
    Mat<1,1> a = zero<1,1>();

    REQUIRE( a.flat[0] == 0 );

    Mat<2,3> b = zero<2,3>();

    REQUIRE( b.m[0][0] == 0 );
    REQUIRE( b.m[0][1] == 0 );
    REQUIRE( b.m[0][2] == 0 );
    REQUIRE( b.m[1][0] == 0 );
    REQUIRE( b.m[1][1] == 0 );
    REQUIRE( b.m[1][2] == 0 );

    Mat<100,100> c = zero<100,100>();
    for ( int i = 0; i < 10000; i++ ) REQUIRE( c[i] == 0 );

    Mat<3,3> d = identity<3>();
    REQUIRE( d.m[0][0] == 1 );
    REQUIRE( d.m[0][1] == 0 );
    REQUIRE( d.m[0][2] == 0 );
    REQUIRE( d.m[1][0] == 0 );
    REQUIRE( d.m[1][1] == 1 );
    REQUIRE( d.m[1][2] == 0 );
    REQUIRE( d.m[2][0] == 0 );
    REQUIRE( d.m[2][1] == 0 );
    REQUIRE( d.m[2][2] == 1 );
}

TEST_CASE( "matrix accessors", "" ) {
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
    for ( int i = 0; i < 10000; i++ ) big[i] = i;
    for ( int i = 0; i < 10000; i++ ) REQUIRE( big[i] == i );
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
    REQUIRE( a.r00 == 1 );
    REQUIRE( a.r01 == 2 );
    REQUIRE( a.r02 == 3 );
    REQUIRE( a.r10 == 4 );
    REQUIRE( a.r11 == 5 );
    REQUIRE( a.r12 == 6 );
    REQUIRE( a.r20 == 7 );
    REQUIRE( a.r21 == 8 );
    REQUIRE( a.r22 == 9 );

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
    REQUIRE( b.m00 == 1 );
    REQUIRE( b.m01 == 2 );
    REQUIRE( b.m02 == 3 );
    REQUIRE( b.tx  == 4 );
    REQUIRE( b.m10 == 5 );
    REQUIRE( b.m11 == 6 );
    REQUIRE( b.m12 == 7 );
    REQUIRE( b.ty  == 8 );
    REQUIRE( b.m20 == 9 );
    REQUIRE( b.m21 == 10 );
    REQUIRE( b.m22 == 11 );
    REQUIRE( b.tz  == 12 );
    REQUIRE( b.m30 == 13 );
    REQUIRE( b.m31 == 14 );
    REQUIRE( b.m32 == 15 );
    REQUIRE( b.m33 == 16 );
}

TEST_CASE( "transpose tests", "" ) {
    Mat3 a = { 1, 2, 3
             , 4, 5, 6
             , 7, 8, 9 };

    transpose( a, a );

    REQUIRE( a.m00 == 1 );
    REQUIRE( a.m01 == 4 );
    REQUIRE( a.m02 == 7 );
    REQUIRE( a.m10 == 2 );
    REQUIRE( a.m11 == 5 );
    REQUIRE( a.m12 == 8 );
    REQUIRE( a.m20 == 3 );
    REQUIRE( a.m21 == 6 );
    REQUIRE( a.m22 == 9 );
    REQUIRE( a.r00 == 1 );
    REQUIRE( a.r01 == 4 );
    REQUIRE( a.r02 == 7 );
    REQUIRE( a.r10 == 2 );
    REQUIRE( a.r11 == 5 );
    REQUIRE( a.r12 == 8 );
    REQUIRE( a.r20 == 3 );
    REQUIRE( a.r21 == 6 );
    REQUIRE( a.r22 == 9 );

    Mat4 b = {  1,  2,  3,  4
             ,  5,  6,  7,  8
             ,  9, 10, 11, 12
             , 13, 14, 15, 16 };

    transpose( b, b );

    REQUIRE( b.m00 == 1  );
    REQUIRE( b.m01 == 5  );
    REQUIRE( b.m02 == 9  );
    REQUIRE( b.m03 == 13 );
    REQUIRE( b.m10 == 2  );
    REQUIRE( b.m11 == 6  );
    REQUIRE( b.m12 == 10 );
    REQUIRE( b.m13 == 14 );
    REQUIRE( b.m20 == 3  );
    REQUIRE( b.m21 == 7  );
    REQUIRE( b.m22 == 11 );
    REQUIRE( b.m23 == 15 );
    REQUIRE( b.m30 == 4  );
    REQUIRE( b.m31 == 8  );
    REQUIRE( b.m32 == 12 );
    REQUIRE( b.m33 == 16 );
    REQUIRE( b.m00 == 1  );
    REQUIRE( b.m01 == 5  );
    REQUIRE( b.m02 == 9  );
    REQUIRE( b.tx  == 13 );
    REQUIRE( b.m10 == 2  );
    REQUIRE( b.m11 == 6  );
    REQUIRE( b.m12 == 10 );
    REQUIRE( b.ty  == 14 );
    REQUIRE( b.m20 == 3  );
    REQUIRE( b.m21 == 7  );
    REQUIRE( b.m22 == 11 );
    REQUIRE( b.tz  == 15 );
    REQUIRE( b.m30 == 4  );
    REQUIRE( b.m31 == 8  );
    REQUIRE( b.m32 == 12 );
    REQUIRE( b.m33 == 16 );
}
