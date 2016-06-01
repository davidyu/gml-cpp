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

typedef Mat<4,4> Mat4;
typedef Mat<3,3> Mat3;

template <int rows, int cols>     Mat<rows, cols> zero();
template <int r1, int c1, int c2> Mat<r1, c2>     operator *( const Mat<r1, c1>& lhs, const Mat<c1, c2>& rhs );

// square matrix functions
template <int n> void     transpose( const Mat<n,n> in, Mat<n,n>& out );
template <int n> Mat<n,n> identity();

void matmul( const Mat4 lhs, const Mat4 rhs, Mat4& out );
void vecmat( const Vec4 lhs, const Mat4 rhs, Vec4& out );

Mat4 fromRows( Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3 );
Mat4 fromCols( Vec4 c0, Vec4 c1, Vec4 c2, Vec4 c3 );

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

template<int n>
void transpose( const Mat<n,n> in, Mat<n,n>& out ) {
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            out.m[i][j] = in.m[j][i];
        }
    }
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

inline Vec4 operator *( const Vec4& lhs, const Mat4& rhs ) {
    Vec4 out;
    vecmat( lhs, rhs, out );
    return out;
}
