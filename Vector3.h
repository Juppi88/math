/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Vector3.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 3D vector structure and functions to manipulate them.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_VECTOR3_H
#define __MYLLY_VECTOR3_H

#include "stdtypes.h"

typedef union
{
	struct {
		float x;
		float y;
		float z;
	};
	float coords[3];
} vector3_t;

__BEGIN_DECLS

MYLLY_API void			vector3_add				( vector3_t* result, const vector3_t* v1, const vector3_t* v2 );
MYLLY_API void			vector3_subtract		( vector3_t* result, const vector3_t* v1, const vector3_t* v2 );
MYLLY_API void			vector3_multiply		( vector3_t* result, const vector3_t* v, float value );
MYLLY_API void			vector3_divide			( vector3_t* result, const vector3_t* v, float value );
MYLLY_API void			vector3_add_scalar		( vector3_t* result, const vector3_t* v, float value );
MYLLY_API void			vector3_subtract_scalar	( vector3_t* result, const vector3_t* v, float value );

MYLLY_API float			vector3_dot				( const vector3_t* v1, const vector3_t* v2 );
MYLLY_API void			vector3_cross			( vector3_t* result, const vector3_t* v1, const vector3_t* v2 );
MYLLY_API float			vector3_angle			( const vector3_t* v1, const vector3_t* v2 );

MYLLY_API float			vector3_length			( const vector3_t* v );
MYLLY_API float			vector3_length_sq		( const vector3_t* v );
MYLLY_API float			vector3_distance		( const vector3_t* v1, const vector3_t* v2 );
MYLLY_API float			vector3_distance_sq		( const vector3_t* v1, const vector3_t* v2 );
MYLLY_API void			vector3_normalize		( vector3_t* v );

MYLLY_API void			vector3_lerp			( vector3_t* result, const vector3_t* v1, const vector3_t* v2, float t );

__END_DECLS

#endif /* __MYLLY_VECTOR3_H */
