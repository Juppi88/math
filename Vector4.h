/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Vector4.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 4D vector structure and functions to manipulate them.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_VECTOR4_H
#define __MYLLY_VECTOR4_H

#include "stdtypes.h"

typedef union
{
	struct {
		float x;
		float y;
		float z;
		float w;
	};
	float coords[4];
} vector4_t;

__BEGIN_DECLS

MYLLY_API void			vector4_add				( vector4_t* result, const vector4_t* v1, const vector4_t* v2 );
MYLLY_API void			vector4_subtract		( vector4_t* result, const vector4_t* v1, const vector4_t* v2 );
MYLLY_API void			vector4_multiply		( vector4_t* result, const vector4_t* v, float value );
MYLLY_API void			vector4_divide			( vector4_t* result, const vector4_t* v, float value );
MYLLY_API void			vector4_add_scalar		( vector4_t* result, const vector4_t* v, float value );
MYLLY_API void			vector4_subtract_scalar	( vector4_t* result, const vector4_t* v, float value );

MYLLY_API float			vector4_dot				( const vector4_t* v1, const vector4_t* v2 );
MYLLY_API float			vector4_angle			( const vector4_t* v1, const vector4_t* v2 );

MYLLY_API float			vector4_length			( const vector4_t* v );
MYLLY_API float			vector4_length_sq		( const vector4_t* v );
MYLLY_API float			vector4_distance		( const vector4_t* v1, const vector4_t* v2 );
MYLLY_API float			vector4_distance_sq		( const vector4_t* v1, const vector4_t* v2 );
MYLLY_API void			vector4_normalize		( vector4_t* v );

MYLLY_API void			vector4_lerp			( vector4_t* result, const vector4_t* v1, const vector4_t* v2, float t );

__END_DECLS

#endif /* __MYLLY_VECTOR4_H */
