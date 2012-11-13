/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Vector2.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 2D vector structure and functions to manipulate them.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_VECTOR2_H
#define __MYLLY_VECTOR2_H

#include "stdtypes.h"

typedef union
{
	struct {
		float x;
		float y;
	};
	float coords[2];
} vector2_t;

__BEGIN_DECLS

MYLLY_API void			vector2_add				( vector2_t* result, const vector2_t* v1, const vector2_t* v2 );
MYLLY_API void			vector2_subtract		( vector2_t* result, const vector2_t* v1, const vector2_t* v2 );
MYLLY_API void			vector2_multiply		( vector2_t* result, const vector2_t* v, float value );
MYLLY_API void			vector2_divide			( vector2_t* result, const vector2_t* v, float value );
MYLLY_API void			vector2_add_scalar		( vector2_t* result, const vector2_t* v, float value );
MYLLY_API void			vector2_subtract_scalar	( vector2_t* result, const vector2_t* v, float value );

MYLLY_API float			vector2_dot				( const vector2_t* v1, const vector2_t* v2 );
MYLLY_API float			vector2_angle			( const vector2_t* v1, const vector2_t* v2 );

MYLLY_API float			vector2_length			( const vector2_t* v );
MYLLY_API float			vector2_length_sq		( const vector2_t* v );
MYLLY_API float			vector2_distance		( const vector2_t* v1, const vector2_t* v2 );
MYLLY_API float			vector2_distance_sq		( const vector2_t* v1, const vector2_t* v2 );
MYLLY_API void			vector2_normalize		( vector2_t* v );

MYLLY_API void			vector2_lerp			( vector2_t* result, const vector2_t* v1, const vector2_t* v2, float t );

__END_DECLS

#endif /* __MYLLY_VECTOR2_H */
