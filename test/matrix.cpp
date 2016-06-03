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

TEST_CASE( "transpose", "" ) {
    Mat3 a = { 1, 2, 3
             , 4, 5, 6
             , 7, 8, 9 };

    a = transpose( a );

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

    b = transpose( b );

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

    Mat<100,50> c;
    Mat<50,100> d;

    for ( int i = 0; i < 5000; i++ ) c[i] = random_float();

    transpose( c, d );

    for ( int i = 0; i < 100; i++ ) {
        for ( int j = 0; j < 50; j++ ) {
            REQUIRE( c.m[i][j] == d.m[j][i] );
        }
    }
}

TEST_CASE( "matrix-matrix operations", "" ) {
    Mat4 a = identity<4>();
    Mat4 b = { 1  , 2  , 3  , 4
             , 5  , 6  , 7  , 8
             , 9  , 10 , 11 , 12
             , 13 , 14 , 15 , 16 };

    Mat4 axb = a * b;
    REQUIRE( axb.m00 == 1 );
    REQUIRE( axb.m01 == 2 );
    REQUIRE( axb.m02 == 3 );
    REQUIRE( axb.m03 == 4 );
    REQUIRE( axb.m10 == 5 );
    REQUIRE( axb.m11 == 6 );
    REQUIRE( axb.m12 == 7 );
    REQUIRE( axb.m13 == 8 );
    REQUIRE( axb.m20 == 9 );
    REQUIRE( axb.m21 == 10 );
    REQUIRE( axb.m22 == 11 );
    REQUIRE( axb.m23 == 12 );
    REQUIRE( axb.m30 == 13 );
    REQUIRE( axb.m31 == 14 );
    REQUIRE( axb.m32 == 15 );
    REQUIRE( axb.m33 == 16 );

    Mat4 c = { 17, 18, 19, 20
             , 21, 22, 23, 24
             , 25, 26, 27, 28
             , 29, 30, 31, 32 };

    Mat4 bxc = b * c;
    REQUIRE( bxc.m00 == 250 );
    REQUIRE( bxc.m01 == 260 );
    REQUIRE( bxc.m02 == 270 );
    REQUIRE( bxc.m03 == 280 );
    REQUIRE( bxc.m10 == 618 );
    REQUIRE( bxc.m11 == 644 );
    REQUIRE( bxc.m12 == 670 );
    REQUIRE( bxc.m13 == 696 );
    REQUIRE( bxc.m20 == 986 );
    REQUIRE( bxc.m21 == 1028 );
    REQUIRE( bxc.m22 == 1070 );
    REQUIRE( bxc.m23 == 1112 );
    REQUIRE( bxc.m30 == 1354 );
    REQUIRE( bxc.m31 == 1412 );
    REQUIRE( bxc.m32 == 1470 );
    REQUIRE( bxc.m33 == 1528 );

    Mat4 c_b = c - b;
    REQUIRE( c_b.m00 == 16 );
    REQUIRE( c_b.m01 == 16 );
    REQUIRE( c_b.m02 == 16 );
    REQUIRE( c_b.m03 == 16 );
    REQUIRE( c_b.m10 == 16 );
    REQUIRE( c_b.m11 == 16 );
    REQUIRE( c_b.m12 == 16 );
    REQUIRE( c_b.m13 == 16 );
    REQUIRE( c_b.m20 == 16 );
    REQUIRE( c_b.m21 == 16 );
    REQUIRE( c_b.m22 == 16 );
    REQUIRE( c_b.m23 == 16 );
    REQUIRE( c_b.m30 == 16 );
    REQUIRE( c_b.m31 == 16 );
    REQUIRE( c_b.m32 == 16 );
    REQUIRE( c_b.m33 == 16 );
}

TEST_CASE( "matrix-vector operations", "" ) {
    Mat<2,2> a = { 5, 6, 7, 8 };
    Vec<2>   b = { 1, 2  };

    Vec<2> axb = a * b;
    REQUIRE( axb[0] == 17 );
    REQUIRE( axb[1] == 23 );

    Vec<2> bxa = b * a;
    REQUIRE( bxa[0] == 19 );
    REQUIRE( bxa[1] == 22 );

    Mat<3,2> c = { 5, 6, 7, 8, 9, 10 };
    Vec<3> cxb = c * b;
    REQUIRE( cxb[0] == 17 );
    REQUIRE( cxb[1] == 23 );
    REQUIRE( cxb[2] == 29 );

    Mat<2,3> d = { 5, 6, 7, 8, 9, 10 };
    Vec<3> bxd = b * d;
    REQUIRE( bxd[0] == 21 );
    REQUIRE( bxd[1] == 24 );
    REQUIRE( bxd[2] == 27 );
}
