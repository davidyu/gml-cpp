#pragma once

#include "vec.hpp"

template <int rows, int cols> struct Mat {
    union {
        float data[rows][cols];
        float flat[rows * cols];
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
        float data[4][4];
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

template <int n> void transpose( const Mat<n,n> in, Mat<n,n>& out );

void matmul( const Mat4 lhs, const Mat4 rhs, Mat4& out );
void vecmat( const Vec4 lhs, const Mat4 rhs, Vec4& out );

Mat4 fromRows( Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3 );
Mat4 fromCols( Vec4 c0, Vec4 c1, Vec4 c2, Vec4 c3 );

// usage: identity<4>() -> Mat<4,4>
template<int N> Mat<N,N> identity() {
    Mat<N, N> out;
    for ( int i = 0; i < N; i++ ) {
        out.flat[i] = 1;
    }
    return out;
}

template<int n>
void transpose( const Mat<n,n> in, Mat<n,n>& out ) {
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            out.data[i][j] = in.data[j][i];
        }
    }
}

inline Mat4 operator *( const Mat4& lhs, const Mat4& rhs ) {
    Mat4 out;
    matmul( lhs, rhs, out );
    return out;
}

inline Vec4 operator *( const Vec4& lhs, const Mat4& rhs ) {
    Vec4 out;
    vecmat( lhs, rhs, out );
    return out;
}
