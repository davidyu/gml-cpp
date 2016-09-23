#pragma once

#include "vec.hpp"
#include "mat.hpp"
#include "primitives.hpp"

Plane get_frustum_near_plane  ( const Mat4& projection );
Plane get_frustum_far_plane   ( const Mat4& projection );
Plane get_frustum_left_plane  ( const Mat4& projection );
Plane get_frustum_right_plane ( const Mat4& projection );
Plane get_frustum_top_plane   ( const Mat4& projection );
Plane get_frustum_bottom_plane( const Mat4& projection );

Plane get_frustum_near_plane  ( const Mat4& projection ) {
    return Plane( get_row3( projection ) + get_row2( projection ) );
}

Plane get_frustum_far_plane   ( const Mat4& projection ) {
    return Plane( get_row3( projection ) - get_row2( projection ) );
}

Plane get_frustum_left_plane  ( const Mat4& projection ) {
    return Plane( get_row3( projection ) + get_row0( projection ) );
}

Plane get_frustum_right_plane ( const Mat4& projection ) {
    return Plane( get_row3( projection ) - get_row0( projection ) );
}

Plane get_frustum_top_plane   ( const Mat4& projection ) {
    return Plane( get_row3( projection ) - get_row1( projection ) );
}

Plane get_frustum_bottom_plane( const Mat4& projection ) {
    return Plane( get_row3( projection ) + get_row1( projection ) );
}
