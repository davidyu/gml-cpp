#pragma once

#include <math.h>

template <int n> struct Vec {
    float v[n];

    float& operator[]( const int i ) {
        return this->v[i];
    }

    float lensq() {
        float sum = 0.f;
        for ( int i = 0; i < n; i++ ) {
            sum += this->v[i] * this->v[i];
        }
        return sum;
    }

    float len() {
        return sqrt( this->lensq() );
    }
};

template <int n>
Vec<n> operator+ ( Vec<n> lhs, Vec<n> rhs ) {
    Vec<n> sum;
    for ( int i = 0; i < n; i++ ) {
        sum[i] = lhs[i] + rhs[i];
    }
    return sum;
}

template <int n>
Vec<n> operator- ( Vec<n> lhs, Vec<n> rhs ) {
    Vec<n> difference;
    for ( int i = 0; i < n; i++ ) {
        difference[i] = lhs[i] - rhs[i];
    }
    return difference;
}

template <int n>
Vec<n> operator* ( Vec<n> lhs, Vec<n> rhs ) {
    Vec<n> product;
    for ( int i = 0; i < n; i++ ) {
        product[i] = lhs[i] * rhs[i];
    }
    return product;
}

template <int n>
Vec<n> operator* ( Vec<n> lhs, float rhs ) {
    Vec<n> scaled;
    for ( int i = 0; i < n; i++ ) {
        scaled[i] = lhs[i] * rhs;
    }
    return scaled;
}

template <int n>
Vec<n> operator* ( float lhs, Vec<n> rhs ) {
    return operator*( rhs, lhs );
}

template <int n>
Vec<n> operator/ ( Vec<n> lhs, Vec<n> rhs ) {
    Vec<n> quotient;
    for ( int i = 0; i < n; i++ ) {
        quotient[i] = lhs[i] / rhs[i];
    }
    return quotient;
}

template <int n>
Vec<n> operator/ ( Vec<n> lhs, float rhs ) {
    Vec<n> scaled;
    for ( int i = 0; i < n; i++ ) {
        scaled[i] = lhs[i] / rhs;
    }
    return scaled;
}

template<> struct Vec<2> {
    union {
        float v[2];
        struct { float x, y; };
        struct { float r, g; };
    };

    Vec( float x, float y ) {
        this->x = x;
        this->y = y;
    }

    Vec() {
        this->x = 0;
        this->y = 0;
    }

    float& operator[]( const int i ) {
        return this->v[i];
    }

    float lensq() {
        return this->x * this->x + this->y * this->y;
    }

    float len() {
        return sqrt( this->lensq() );
    }
};

template<> struct Vec<3> {
    union {
        float v[3];
        struct { float x, y, z; };
        struct { float r, g, b; };
        Vec<2> xy;
    };

    Vec( float x, float y, float z ) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    float& operator[]( const int i ) {
        return this->v[i];
    }

    float lensq() {
        return this->x * this->x + this->y * this->y + this->z * this->z;
    }

    float len() {
        return sqrt( this->lensq() );
    }
};

template<> struct Vec<4> {
    union {
        float v[4];
        struct { float x, y, z, w; };
        struct { float r, g, b, a; };
        Vec<2> xy;
        Vec<3> xyz;
        Vec<3> rgb;
    };

    Vec( float x, float y, float z, float w ) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vec() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }

    float& operator[]( const int i ) {
        return this->v[i];
    }

    float lensq() {
        return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
    }

    float len() {
        return sqrt( this->lensq() );
    }
};

typedef Vec<2> Vec2;
typedef Vec<3> Vec3;
typedef Vec<4> Vec4;
typedef Vec<4> Color;
