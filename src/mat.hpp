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

template <int rows, int cols>     void             zero( const Mat<rows, cols>& in_out );
template <int rows, int cols>     Mat<rows, cols>  zero();
template <int rows, int cols>     void             transpose( const Mat<rows,cols>& in, Mat<cols,rows>& out );
template <int rows, int cols>     Mat<cols, rows>  transpose( const Mat<rows,cols>& in );

template <int r1, int c1, int c2> Mat<r1, c2>      operator* ( const Mat<r1, c1>& lhs    , const Mat<c1, c2>& rhs     );
template <int rows, int cols>     Vec<cols>        operator* ( const Vec<rows>& lhs      , const Mat<rows, cols>& rhs ); // row-vector * matrix
template <int rows, int cols>     Vec<rows>        operator* ( const Mat<rows, cols>& lhs, const Vec<cols>& rhs       ); // matrix * column-vector
template <int rows, int cols>     Mat<rows, cols>  operator+ ( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     Mat<rows, cols>& operator+=(       Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     Mat<rows, cols>  operator- ( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );
template <int rows, int cols>     Mat<rows, cols>& operator-=(       Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs );

// square matrix functions
template <int n> Mat<n,n> identity ();

Mat4 fromRows( Vec4 r0, Vec4 r1, Vec4 r2, Vec4 r3 );
Mat4 fromCols( Vec4 c0, Vec4 c1, Vec4 c2, Vec4 c3 );

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

template <int rows, int cols>
Mat<rows, cols>  operator+ ( const Mat<rows, cols>& lhs, const Mat<rows, cols>& rhs ) {
    Mat<rows, cols> out;
    for ( int i = 0; i < rows * cols; i++ ) {
        out[i] = lhs[i] + rhs[i];
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
