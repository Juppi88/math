/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		VectorScreen.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		A vector structure for an absolute point on screen.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_VECTORSCREEN_H
#define __MYLLY_VECTORSCREEN_H

#include "stdtypes.h"

#ifdef __cplusplus

// A vector implementation for C++
union vectorscreen_t
{
	vectorscreen_t() { x = 0; y = 0; }
	vectorscreen_t( int16 X, int16 Y ) { x = X; y = Y; }

	struct { int16 x, y; };
	struct { uint16 w, h; };
	struct { uint16 ux, uy; };
	uint16 coords[2];
};

#else

// Pure C version of the struct
typedef union
{
	struct { int16 x, y; };
	struct { uint16 w, h; };
	struct { uint16 ux, uy; };
	uint16 coords[2];
} vectorscreen_t;

#endif

typedef vectorscreen_t VectorScreen;

__BEGIN_DECLS

MYLLY_API void			vectorscreen_add				( vectorscreen_t* result, const vectorscreen_t* v1, const vectorscreen_t* v2 );
MYLLY_API void			vectorscreen_subtract			( vectorscreen_t* result, const vectorscreen_t* v1, const vectorscreen_t* v2 );
MYLLY_API void			vectorscreen_multiply			( vectorscreen_t* result, const vectorscreen_t* v, float value );
MYLLY_API void			vectorscreen_divide				( vectorscreen_t* result, const vectorscreen_t* v, float value );
MYLLY_API void			vectorscreen_add_scalar			( vectorscreen_t* result, const vectorscreen_t* v, float value );
MYLLY_API void			vectorscreen_subtract_scalar	( vectorscreen_t* result, const vectorscreen_t* v, float value );

MYLLY_API float			vectorscreen_dot				( const vectorscreen_t* v1, const vectorscreen_t* v2 );
MYLLY_API float			vectorscreen_angle				( const vectorscreen_t* v1, const vectorscreen_t* v2 );

MYLLY_API float			vectorscreen_length				( const vectorscreen_t* v );
MYLLY_API float			vectorscreen_length_sq			( const vectorscreen_t* v );
MYLLY_API float			vectorscreen_distance			( const vectorscreen_t* v1, const vectorscreen_t* v2 );
MYLLY_API float			vectorscreen_distance_sq		( const vectorscreen_t* v1, const vectorscreen_t* v2 );
MYLLY_API void			vectorscreen_normalize			( vectorscreen_t* v );

MYLLY_API void			vectorscreen_lerp				( vectorscreen_t* result, const vectorscreen_t* v1, const vectorscreen_t* v2, float t );

__END_DECLS

#endif /* __MYLLY_VECTORSCREEN_H */
