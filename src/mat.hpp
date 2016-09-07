/***************************************************************
 * 
 * TEMPLATIZED MULTIDIMENSIONAL MATRICES
 *
 * Usage example:
 *
 *  Mat4 id = { 1, 0, 0, 0
 *            , 0, 1, 0, 0
 *            , 0, 0, 1, 0
 *            , 0, 0, 0, 1 };
 *
 *  id *= 1;
 *
 *  Vec4 pos = { 0, 0, 0, 1 };
 *  pos = id * pos;
 *
 *  id = transpose( id );
 *
 **************************************************************/

#pragma once

#include "vec.hpp"

template <int rows, int cols> struct Mat {
    union {
        float m[rows][cols];
        float flat[rows * cols];
    };

    float& operator[]( const int i ) {
        return this->flat[i];
    }

    const float& operator[]( const int i ) const {
        return this->flat[i];
    }
};

template<> struct Mat<3,3> {
    union {
        float m[3][3];
        float flat[9];
        struct { float m00, m01, m02, m10, m11, m12, m20, m21, m22; };
        struct { float r00, r01, r02, r10, r11, r12, r20, r21, r22; };
    };

    float& operator[]( const int i ) {
        return this->flat[i];
    }

    const float& operator[]( const int i ) const {
        return this->flat[i];
    }
};


template<> struct Mat<4,4> {
    union {
        float m[4][4];
        float flat[16];
        struct { float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33; };
        struct { float r00, r01, r02,  tx, r10, r11, r12,  ty, r20, r21, r22,  tz; };
    };

    float& operator[]( const int i ) {
        return this->flat[i];
    }

    const float& operator[]( const int i ) const {
        return this->flat[i];
    }
};

typedef Mat<3,3> Mat3;
typedef Mat<4,4> Mat4;

Mat3                                               construct_mat3_from_rows( Vec3 r0, Vec3 r1, Vec3 r2 );
Mat3                                               construct_mat3_from_cols( Vec3 c0, Vec3 c1, Vec3 c2 );
Mat4                                               construct_mat4_from_rows( Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3 );
Mat4                                               construct_mat4_from_cols( Vec4 c0, Vec4 c1, Vec4 c2, Vec4 c3 );

float                                              determinant( const Mat3& m );
float                                              determinant( const Mat4& m );
Mat4                                               invert     ( const Mat4& m );
Mat3                                               invert     ( const Mat3& m );

Vec3                                               get_row0( const Mat3& m );
Vec3                                               get_row1( const Mat3& m );
Vec3                                               get_row2( const Mat3& m );
Vec3                                               get_col0( const Mat3& m );
Vec3                                               get_col1( const Mat3& m );
Vec3                                               get_col2( const Mat3& m );

Vec4                                               get_row0( const Mat4& m );
Vec4                                               get_row1( const Mat4& m );
Vec4                                               get_row2( const Mat4& m );
Vec4                                               get_row3( const Mat4& m );
Vec4                                               get_col0( const Mat4& m );
Vec4                                               get_col1( const Mat4& m );
Vec4                                               get_col2( const Mat4& m );
Vec4                                               get_col3( const Mat4& m );

template <int rows, int cols>     void             zero( const Mat<rows, cols>& in_out );
template <int rows, int cols>     Mat<rows, cols>  zero();
template <int rows, int cols>     void             transpose( const Mat<rows,cols>& in, Mat<cols,rows>& out );
template <int rows, int cols>     Mat<cols, rows>  transpose( const Mat<rows,cols>& in );

template <int r1, int c1, int c2> Mat<r1, c2>      operator* ( const Mat<r1, c1>& lhs    , const Mat<c1, c2>& rhs     );
template <int rows, int cols>     Vec<cols>        operator* ( const Vec<rows>& lhs      , const Mat<rows, cols>& rhs ); // row-vector * matrix
template <int rows, int cols>     Vec<rows>        operator* ( const Mat<rows, cols>& lhs, const Vec<cols>& rhs       ); // matrix * column-vector
template <int rows, int cols>     Mat<rows, cols>  operator* ( const Mat<rows, cols>& lhs, const float rhs            ); // matrix * scalar
template <int rows, int cols>     Mat<rows, cols>  operator* ( const float lhs           , const Mat<rows, cols>& rhs ); // scalar * matrix
template <int rows, int cols>     Mat<rows, cols>  operator+ ( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     Mat<rows, cols>& operator+=(       Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     Mat<rows, cols>  operator- ( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     Mat<rows, cols>& operator-=(       Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     bool             operator==( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     bool             operator!=( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );

// scale
// rotate
// translate

// square matrix functions
template <int n> Mat<n,n> identity ();

Mat3 construct_mat3_from_rows( Vec3 r0, Vec3 r1, Vec3 r2 ) {
    return { r0.v[0], r0.v[1], r0.v[2]
           , r1.v[0], r1.v[1], r1.v[2]
           , r2.v[0], r2.v[1], r2.v[2] };
}

Mat3 construct_mat3_from_cols( Vec3 c0, Vec3 c1, Vec3 c2 ) {
    return { c0.v[0], c1.v[0], c2.v[0]
           , c0.v[1], c1.v[1], c2.v[1]
           , c0.v[2], c1.v[2], c2.v[2] };
}

Mat4 construct_mat4_from_rows( Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3 ) {
    return { r0.v[0], r0.v[1], r0.v[2], r0.v[3]
           , r1.v[0], r1.v[1], r1.v[2], r1.v[3]
           , r2.v[0], r2.v[1], r2.v[2], r2.v[3]
           , r3.v[0], r3.v[1], r3.v[2], r3.v[3] };
}

Mat4 construct_mat4_from_cols( Vec4 c0, Vec4 c1, Vec4 c2, Vec4 c3 ) {
    return { c0.v[0], c1.v[0], c2.v[0], c3.v[0]
           , c0.v[1], c1.v[1], c2.v[1], c3.v[1]
           , c0.v[2], c1.v[2], c2.v[2], c3.v[2]
           , c0.v[3], c1.v[3], c2.v[3], c3.v[3] };
}

Vec3 get_row0( const Mat3& m ) {
    return { m.m00, m.m01, m.m02 };
}

Vec3 get_row1( const Mat3& m ) {
    return { m.m10, m.m11, m.m12 };
}

Vec3 get_row2( const Mat3& m ) {
    return { m.m20, m.m21, m.m22 };
}

Vec3 get_col0( const Mat3& m ) {
    return { m.m00, m.m10, m.m20 };
}

Vec3 get_col1( const Mat3& m ) {
    return { m.m01, m.m11, m.m21 };
}

Vec3 get_col2( const Mat3& m ) {
    return { m.m02, m.m12, m.m22 };
}

Vec4 get_row0( const Mat4& m ) {
    return { m.m00, m.m01, m.m02, m.m03 };
}

Vec4 get_row1( const Mat4& m ) {
    return { m.m10, m.m11, m.m12, m.m13 };
}

Vec4 get_row2( const Mat4& m ) {
    return { m.m20, m.m21, m.m22, m.m23 };
}

Vec4 get_row3( const Mat4& m ) {
    return { m.m30, m.m31, m.m32, m.m33 };
}

Vec4 get_col0( const Mat4& m ) {
    return { m.m00, m.m10, m.m20, m.m30 };
}

Vec4 get_col1( const Mat4& m ) {
    return { m.m01, m.m11, m.m21, m.m31 };
}

Vec4 get_col2( const Mat4& m ) {
    return { m.m02, m.m12, m.m22, m.m32 };
}

Vec4 get_col3( const Mat4& m ) {
    return { m.m03, m.m13, m.m23, m.m33 };
}

Mat3 invert( const Mat3& m ) {
    float det = m.m00 * ( m.m11 * m.m22 - m.m12 * m.m21 ) - m.m01 * ( m.m10 * m.m22 - m.m12 * m.m20 ) + m.m02 * ( m.m10 * m.m21 - m.m11 * m.m20 );
    if ( det == 0 ) return identity<3>(); // fail
    float f = 1 / det;

    return { f * ( m.m11 * m.m22 - m.m12 * m.m21 )
           , f * ( m.m02 * m.m21 - m.m01 * m.m22 )
           , f * ( m.m02 * m.m12 - m.m02 * m.m11 )
           
           , f * ( m.m12 * m.m20 - m.m10 * m.m22 )
           , f * ( m.m00 * m.m22 - m.m02 * m.m20 )
           , f * ( m.m02 * m.m10 - m.m00 * m.m12 )

           , f * ( m.m10 * m.m21 - m.m11 * m.m20 )
           , f * ( m.m01 * m.m20 - m.m00 * m.m21 )
           , f * ( m.m00 * m.m11 - m.m01 * m.m10 ) };
}

float determinant( const Mat3& m ) {

   /* use Sarrus's rule and factor out common terms to arrive at:
    *
    * m00 * ( m11 * m22 - m12 * m21 ) - m01 * ( m10 * m22 - m12 * m20 ) + m02 * ( m10 * m21 - m11 * m20 )
    */

    return m.m00 * ( m.m11 * m.m22 - m.m12 * m.m21 ) - m.m01 * ( m.m10 * m.m22 - m.m12 * m.m20 ) + m.m02 * ( m.m10 * m.m21 - m.m11 * m.m20 );
}

Mat4 invert( const Mat4& m ) {
    float a00 = m.m03 * m.m11 - m.m01 * m.m13;
    float a01 = m.m20 * m.m32 - m.m22 * m.m30;
    float a02 = m.m00 * m.m13 - m.m03 * m.m10;
    float a03 = m.m21 * m.m32 - m.m22 * m.m31;
    float a04 = m.m02 * m.m10 - m.m00 * m.m12;
    float a05 = m.m21 * m.m33 - m.m23 * m.m31;
    float a06 = m.m00 * m.m11 - m.m01 * m.m10;
    float a07 = m.m22 * m.m33 - m.m23 * m.m32;
    float a08 = m.m02 * m.m11 - m.m01 * m.m12;
    float a09 = m.m23 * m.m30 - m.m20 * m.m33;
    float a10 = m.m03 * m.m12 - m.m02 * m.m13;
    float a11 = m.m21 * m.m30 - m.m20 * m.m31;

    float det = a00 * a01 + a02 * a03 + a04 * a05 + a06 * a07 + a08 * a09 + a10 * a11;
    if ( det == 0 ) return identity<4>(); // fail
    float f = 1 / det;

   /* given the expanded form of the 4x4 inverse:
    *
    *    ( f * ( -m13 * m22 * m31 + m12 * m23 * m31 + m13 * m21 * m32 - m11 * m23 * m32 - m12 * m21 * m33 + m11 * m22 * m33 )
    *    , f * (  m03 * m22 * m31 - m02 * m23 * m31 - m03 * m21 * m32 + m01 * m23 * m32 + m02 * m21 * m33 - m01 * m22 * m33 )
    *    , f * ( -m03 * m12 * m31 + m02 * m13 * m31 + m03 * m11 * m32 - m01 * m13 * m32 - m02 * m11 * m33 + m01 * m12 * m33 )
    *    , f * (  m03 * m12 * m21 - m02 * m13 * m21 - m03 * m11 * m22 + m01 * m13 * m22 + m02 * m11 * m23 - m01 * m12 * m23 )
    *
    *    , f * (  m13 * m22 * m30 - m12 * m23 * m30 - m13 * m20 * m32 + m10 * m23 * m32 + m12 * m20 * m33 - m10 * m22 * m33 )
    *    , f * ( -m03 * m22 * m30 + m02 * m23 * m30 + m03 * m20 * m32 - m00 * m23 * m32 - m02 * m20 * m33 + m00 * m22 * m33 )
    *    , f * (  m03 * m12 * m30 - m02 * m13 * m30 - m03 * m10 * m32 + m00 * m13 * m32 + m02 * m10 * m33 - m00 * m12 * m33 )
    *    , f * ( -m03 * m12 * m20 + m02 * m13 * m20 + m03 * m10 * m22 - m00 * m13 * m22 - m02 * m10 * m23 + m00 * m12 * m23 )
    *
    *    , f * ( -m13 * m21 * m30 + m11 * m23 * m30 + m13 * m20 * m31 - m10 * m23 * m31 - m11 * m20 * m33 + m10 * m21 * m33 )
    *    , f * (  m03 * m21 * m30 - m01 * m23 * m30 - m03 * m20 * m31 + m00 * m23 * m31 + m01 * m20 * m33 - m00 * m21 * m33 )
    *    , f * ( -m03 * m11 * m30 + m01 * m13 * m30 + m03 * m10 * m31 - m00 * m13 * m31 - m01 * m10 * m33 + m00 * m11 * m33 )
    *    , f * (  m03 * m11 * m20 - m01 * m13 * m20 - m03 * m10 * m21 + m00 * m13 * m21 + m01 * m10 * m23 - m00 * m11 * m23 )
    *
    *    , f * (  m12 * m21 * m30 - m11 * m22 * m30 - m12 * m20 * m31 + m10 * m22 * m31 + m11 * m20 * m32 - m10 * m21 * m32 )
    *    , f * ( -m02 * m21 * m30 + m01 * m22 * m30 + m02 * m20 * m31 - m00 * m22 * m31 - m01 * m20 * m32 + m00 * m21 * m32 )
    *    , f * (  m02 * m11 * m30 - m01 * m12 * m30 - m02 * m10 * m31 + m00 * m12 * m31 + m01 * m10 * m32 - m00 * m11 * m32 )
    *    , f * ( -m02 * m11 * m20 + m01 * m12 * m20 + m02 * m10 * m21 - m00 * m12 * m21 - m01 * m10 * m22 + m00 * m11 * m22 ) )
    *
    * rearrange to match terms a00-a11 from determinant computation:
    *
    *    ( f * (  m13 * m21 * m32 - m13 * m22 * m31 - m12 * m21 * m33 + m12 * m23 * m31 + m11 * m22 * m33 - m11 * m23 * m32 )
    *    , f * ( -m03 * m21 * m32 + m03 * m22 * m31 + m02 * m21 * m33 - m02 * m23 * m31 - m01 * m22 * m33 + m01 * m23 * m32 )
    *    , f * ( -m31 * m03 * m12 + m31 * m02 * m13 + m32 * m03 * m11 - m32 * m01 * m13 - m33 * m02 * m11 + m33 * m01 * m12 )
    *    , f * (  m21 * m03 * m12 - m21 * m02 * m13 - m22 * m03 * m11 + m22 * m01 * m13 + m23 * m02 * m11 - m23 * m01 * m12 )
    *
    *    , f * ( -m13 * m20 * m32 + m13 * m22 * m30 - m12 * m23 * m30 + m12 * m20 * m33 + m10 * m23 * m32 - m10 * m22 * m33 )
    *    , f * (  m03 * m20 * m32 - m03 * m22 * m30 + m02 * m23 * m30 - m02 * m20 * m33 - m00 * m23 * m32 + m00 * m22 * m33 )
    *    , f * (  m30 * m03 * m12 - m30 * m02 * m13 + m32 * m00 * m13 - m32 * m03 * m10 + m33 * m02 * m10 - m33 * m00 * m12 )
    *    , f * ( -m20 * m03 * m12 + m20 * m02 * m13 - m22 * m00 * m13 + m22 * m03 * m10 - m23 * m02 * m10 + m23 * m00 * m12 )
    *
    *    , f * ( -m13 * m21 * m30 + m13 * m20 * m31 + m11 * m23 * m30 - m11 * m20 * m33 + m10 * m21 * m33 - m10 * m23 * m31 )
    *    , f * (  m03 * m21 * m30 - m03 * m20 * m31 - m01 * m23 * m30 + m01 * m20 * m33 - m00 * m21 * m33 + m00 * m23 * m31 )
    *    , f * ( -m30 * m03 * m11 + m30 * m01 * m13 - m31 * m00 * m13 + m31 * m03 * m10 + m33 * m00 * m11 - m33 * m01 * m10 )
    *    , f * (  m20 * m03 * m11 - m20 * m01 * m13 + m21 * m00 * m13 - m21 * m03 * m10 - m23 * m00 * m11 + m23 * m01 * m10 )
    *
    *    , f * (  m12 * m21 * m30 - m12 * m20 * m31 + m11 * m20 * m32 - m11 * m22 * m30 - m10 * m21 * m32 + m10 * m22 * m31 )
    *    , f * ( -m02 * m21 * m30 + m02 * m20 * m31 - m01 * m20 * m32 + m01 * m22 * m30 + m00 * m21 * m32 - m00 * m22 * m31 )
    *    , f * (  m30 * m02 * m11 - m30 * m01 * m12 - m31 * m02 * m10 + m31 * m00 * m12 - m32 * m00 * m11 + m32 * m01 * m10 )
    *    , f * ( -m20 * m02 * m11 + m20 * m01 * m12 + m21 * m02 * m10 - m21 * m00 * m12 + m22 * m00 * m11 - m22 * m01 * m10 ) );
    *
    * then factor:
    *
    *    ( f * (  m13 * ( m21 * m32 - m22 * m31 ) - m12 * ( m21 * m33 - m23 * m31 ) + m11 * ( m22 * m33 - m23 * m32 ) )
    *    , f * ( -m03 * ( m21 * m32 - m22 * m31 ) + m02 * ( m21 * m33 - m23 * m31 ) - m01 * ( m22 * m33 - m23 * m32 ) )
    *    , f * ( -m31 * ( m03 * m12 - m02 * m13 ) + m32 * ( m03 * m11 - m01 * m13 ) - m33 * ( m02 * m11 - m01 * m12 ) )
    *    , f * (  m21 * ( m03 * m12 - m02 * m13 ) - m22 * ( m03 * m11 - m01 * m13 ) + m23 * ( m02 * m11 - m01 * m12 ) )
    *
    *    , f * ( -m13 * ( m20 * m32 - m22 * m30 ) - m12 * ( m23 * m30 - m20 * m33 ) + m10 * ( m23 * m32 - m22 * m33 ) )
    *    , f * (  m03 * ( m20 * m32 - m22 * m30 ) + m02 * ( m23 * m30 - m20 * m33 ) - m00 * ( m23 * m32 - m22 * m33 ) )
    *    , f * (  m30 * ( m03 * m12 - m02 * m13 ) + m32 * ( m00 * m13 - m03 * m10 ) + m33 * ( m02 * m10 - m00 * m12 ) )
    *    , f * ( -m20 * ( m03 * m12 - m02 * m13 ) - m22 * ( m00 * m13 - m03 * m10 ) - m23 * ( m02 * m10 - m00 * m12 ) )
    *
    *    , f * ( -m13 * ( m21 * m30 - m20 * m31 ) + m11 * ( m23 * m30 - m20 * m33 ) + m10 * ( m21 * m33 - m23 * m31 ) )
    *    , f * (  m03 * ( m21 * m30 - m20 * m31 ) - m01 * ( m23 * m30 - m20 * m33 ) - m00 * ( m21 * m33 - m23 * m31 ) )
    *    , f * ( -m30 * ( m03 * m11 - m01 * m13 ) - m31 * ( m00 * m13 - m03 * m10 ) + m33 * ( m00 * m11 - m01 * m10 ) )
    *    , f * (  m20 * ( m03 * m11 - m01 * m13 ) + m21 * ( m00 * m13 - m03 * m10 ) - m23 * ( m00 * m11 - m01 * m10 ) )
    *
    *    , f * (  m12 * ( m21 * m30 - m20 * m31 ) + m11 * ( m20 * m32 - m22 * m30 ) - m10 * ( m21 * m32 - m22 * m31 ) )
    *    , f * ( -m02 * ( m21 * m30 - m20 * m31 ) - m01 * ( m20 * m32 - m22 * m30 ) + m00 * ( m21 * m32 - m22 * m31 ) )
    *    , f * (  m30 * ( m02 * m11 - m01 * m12 ) - m31 * ( m02 * m10 - m00 * m12 ) - m32 * ( m00 * m11 - m01 * m10 ) )
    *    , f * ( -m20 * ( m02 * m11 - m01 * m12 ) + m21 * ( m02 * m10 - m00 * m12 ) + m22 * ( m00 * m11 - m01 * m10 ) ) );
    *
    * and finally, substitute terms to arrive at the result:
    */

    return { f * (  m.m13 * a03 - m.m12 * a05 + m.m11 * a07 )
           , f * ( -m.m03 * a03 + m.m02 * a05 - m.m01 * a07 )
           , f * ( -m.m31 * a10 + m.m32 * a00 - m.m33 * a08 )
           , f * (  m.m21 * a10 - m.m22 * a00 + m.m23 * a08 )

           , f * ( -m.m13 * a01 - m.m12 * a09 - m.m10 * a07 )
           , f * (  m.m03 * a01 + m.m02 * a09 + m.m00 * a07 )
           , f * (  m.m30 * a10 + m.m32 * a02 + m.m33 * a04 )
           , f * ( -m.m20 * a10 - m.m22 * a02 - m.m23 * a04 )

           , f * ( -m.m13 * a11 + m.m11 * a09 + m.m10 * a05 )
           , f * (  m.m03 * a11 - m.m01 * a09 - m.m00 * a05 )
           , f * ( -m.m30 * a00 - m.m31 * a02 + m.m33 * a06 )
           , f * (  m.m20 * a00 + m.m21 * a02 - m.m23 * a06 )

           , f * (  m.m12 * a11 + m.m11 * a01 - m.m10 * a03 )
           , f * ( -m.m02 * a11 - m.m01 * a01 + m.m00 * a03 )
           , f * (  m.m30 * a08 - m.m31 * a04 - m.m32 * a06 )
           , f * ( -m.m20 * a08 + m.m21 * a04 + m.m22 * a06 ) };
}

float determinant( const Mat4& m ) {

   /* to derive: 
    * expand the Leibniz formula (or Sarrus's rule) to arrive at the following closed form:
    *
    *     m03 * m12 * m21 * m30 - m02 * m13 * m21 * m30 - m03 * m11 * m22 * m30 + m01 * m13 * m22 * m30 +
    *     m02 * m11 * m23 * m30 - m01 * m12 * m23 * m30 - m03 * m12 * m20 * m31 + m02 * m13 * m20 * m31 +
    *     m03 * m10 * m22 * m31 - m00 * m13 * m22 * m31 - m02 * m10 * m23 * m31 + m00 * m12 * m23 * m31 +
    *     m03 * m11 * m20 * m32 - m01 * m13 * m20 * m32 - m03 * m10 * m21 * m32 + m00 * m13 * m21 * m32 +
    *     m01 * m10 * m23 * m32 - m00 * m11 * m23 * m32 - m02 * m11 * m20 * m33 + m01 * m12 * m20 * m33 +
    *     m02 * m10 * m21 * m33 - m00 * m12 * m21 * m33 - m01 * m10 * m22 * m33 + m00 * m11 * m22 * m33;
    *
    * then factor out common pairs:
    *
    *      m03 * m11 * ( m20 * m32 - m22 * m30 )
    *      m01 * m13 * ( m22 * m30 - m20 * m32 )
    *      m00 * m13 * ( m21 * m32 - m22 * m31 )
    *      m03 * m10 * ( m22 * m31 - m21 * m32 )
    *      m02 * m10 * ( m21 * m33 - m23 * m31 )
    *      m00 * m12 * ( m23 * m31 - m21 * m33 )
    *      m00 * m11 * ( m22 * m33 - m23 * m32 )
    *      m02 * m11 * ( m23 * m30 - m20 * m33 )
    *      m01 * m12 * ( m20 * m33 - m23 * m30 )
    *      m03 * m12 * ( m21 * m30 - m20 * m31 )
    *      m02 * m13 * ( m20 * m31 - m21 * m30 )
    *      m01 * m10 * ( m23 * m32 - m22 * m33 )
    *
    * one more time, and voila:
    *
    *     ( m03 * m11 - m01 * m13 ) * ( m20 * m32 - m22 * m30 )
    *     ( m00 * m13 - m03 * m10 ) * ( m21 * m32 - m22 * m31 )
    *     ( m02 * m10 - m00 * m12 ) * ( m21 * m33 - m23 * m31 )
    *     ( m00 * m11 - m01 * m10 ) * ( m22 * m33 - m23 * m32 )
    *     ( m02 * m11 - m01 * m12 ) * ( m23 * m30 - m20 * m33 )
    *     ( m03 * m12 - m02 * m13 ) * ( m21 * m30 - m20 * m31 )
    */

    float a00 = m.m03 * m.m11 - m.m01 * m.m13;
    float a01 = m.m20 * m.m32 - m.m22 * m.m30;
    float a02 = m.m00 * m.m13 - m.m03 * m.m10;
    float a03 = m.m21 * m.m32 - m.m22 * m.m31;
    float a04 = m.m02 * m.m10 - m.m00 * m.m12;
    float a05 = m.m21 * m.m33 - m.m23 * m.m31;
    float a06 = m.m00 * m.m11 - m.m01 * m.m10;
    float a07 = m.m22 * m.m33 - m.m23 * m.m32;
    float a08 = m.m02 * m.m11 - m.m01 * m.m12;
    float a09 = m.m23 * m.m30 - m.m20 * m.m33;
    float a10 = m.m03 * m.m12 - m.m02 * m.m13;
    float a11 = m.m21 * m.m30 - m.m20 * m.m31;
    return a00 * a01 + a02 * a03 + a04 * a05 + a06 * a07 + a08 * a09 + a10 * a11;
}

template <int rows, int cols> void zero( Mat<rows, cols>& in_out ) {
    for ( int i = 0; i < rows * cols; i++ ) {
        in_out[i] = 0;
    }
}

template <int rows, int cols> Mat<rows,cols> zero() {
    Mat<rows, cols> out;
    for ( int i = 0; i < rows * cols; i++ ) {
        out[i] = 0;
    }
    return out;
}

template<int n>
Mat<n,n> identity() {
    Mat<n, n> out;
    for ( int i = 0; i < n * n; i++ ) out.flat[i] = 0;
    for ( int i = 0; i < n; i++ )     out.m[i][i] = 1;
    return out;
}

template<int rows, int cols>
void transpose( const Mat<rows,cols>& in, Mat<cols,rows>& out ) {
    for ( int i = 0; i < cols; i++ ) {
        for ( int j = 0; j < rows; j++ ) {
            out.m[i][j] = in.m[j][i];
        }
    }
}

template<int rows, int cols>
Mat<cols, rows> transpose( const Mat<rows,cols>& in ) {
    Mat<cols, rows> out;
    for ( int i = 0; i < cols; i++ ) {
        for ( int j = 0; j < rows; j++ ) {
            out.m[i][j] = in.m[j][i];
        }
    }
    return out;
}

template<int r1, int c1, int c2>
Mat<r1, c2> operator*( const Mat<r1, c1>& lhs, const Mat<c1, c2>& rhs ) {
    Mat<r1, c2> out;
    for ( int i = 0; i < r1; i++ ) {
        for ( int j = 0; j < c2; j++ ) {
            float sum = 0;
            for ( int k = 0; k < c1; k++ ) {
                sum += lhs.m[i][k] * rhs.m[k][j];
            }
            out.m[i][j] = sum;
        }
    }
    return out;
}

template<int rows, int cols>
Vec<cols> operator*( const Vec<rows>& lhs, const Mat<rows, cols>& rhs ) {
    Vec<cols> out;
    for ( int i = 0; i < cols; i++ ) {
       float sum = 0;
       for ( int j = 0; j < rows; j++ ) {
           sum += lhs.v[j] * rhs.m[j][i];
       }
       out.v[i] = sum;
    }
    return out;
}

template<int rows, int cols>
Vec<rows> operator*( const Mat<rows, cols>& lhs, const Vec<cols>& rhs ) {
    Vec<rows> out;
    for ( int i = 0; i < rows; i++ ) {
       float sum = 0;
       for ( int j = 0; j < cols; j++ ) {
           sum += lhs.m[i][j] * rhs.v[j];
       }
       out.v[i] = sum;
    }
    return out;
}

template<int rows, int cols>
Mat<rows, cols> operator*( const Mat<rows, cols>& lhs, const float rhs ) {
    Mat<rows, cols> out;
    for ( int i = 0; i < rows * cols; i++ ) {
       out.flat[i] = lhs.flat[i] * rhs;
    }
    return out;
}

template <int rows, int cols>
Mat<rows, cols>  operator+ ( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs ) {
    Mat<rows, cols> out;
    for ( int i = 0; i < rows * cols; i++ ) {
        out.flat[i] = lhs.flat[i] + rhs.flat[i];
    }
    return out;
}

template <int rows, int cols>
Mat<rows, cols> operator*( const float lhs, const Mat<rows, cols>& rhs ) {
    Mat<rows, cols> out;
    for ( int i = 0; i < rows * cols; i++ ) {
        out.flat[i] = lhs * rhs.flat[i];
    }
    return out;
}

template <int rows, int cols>
Mat<rows, cols>& operator+=( Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs ) {
    for ( int i = 0; i < rows * cols; i++ ) {
        lhs[i] += rhs[i];
    }
    return lhs;
}

template <int rows, int cols>
Mat<rows, cols>  operator- ( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs ) {
    Mat<rows, cols> out;
    for ( int i = 0; i < rows * cols; i++ ) {
        out[i] = lhs[i] - rhs[i];
    }
    return out;
}

template <int rows, int cols>
Mat<rows, cols>& operator-=( Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs ) {
    for ( int i = 0; i < rows * cols; i++ ) {
        lhs[i] -= rhs[i];
    }
    return lhs;
}

template <int rows, int cols>
bool operator==( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs ) {
    for ( int i = 0; i < rows * cols; i++ ) {
        if ( fabs( lhs[i] - rhs[i] ) > ERROR_EPSILON ) return false;
    }
    return true;
}

template <int rows, int cols>
bool operator!=( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs ) {
    for ( int i = 0; i < rows * cols; i++ ) {
        if ( fabs( lhs[i] - rhs[i] ) > ERROR_EPSILON ) return true;
    }
    return false;
}
