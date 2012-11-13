/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Colour.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		RGBA colour struct.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_COLOUR_H
#define __MYLLY_COLOUR_H

#include "stdtypes.h"

typedef union
{
	uint32 hex;						// Hex colour
	
#ifdef MYLLY_BIG_ENDIAN
	struct { uint8 r, g, b, a; };	// RGBA colour (big endian)
#else
	struct { uint8 a, b, g, r; };	// RGBA colour (little endian)
#endif

} colour_t;

#define RGBACOL(r,g,b,a) \
	(uint32)( (r << 24) | (g << 16) | (b << 8) | a )

#define RGBCOL(r,g,b) \
	RGBACOL(r,g,b,255)

__BEGIN_DECLS

MYLLY_API void			colour_add				( colour_t* result, const colour_t* c1, const colour_t* c2 );
MYLLY_API void			colour_subtract			( colour_t* result, const colour_t* c1, const colour_t* c2 );
MYLLY_API void			colour_multiply			( colour_t* result, const colour_t* c, float value );
MYLLY_API void			colour_divide			( colour_t* result, const colour_t* c, float value );
MYLLY_API void			colour_add_scalar		( colour_t* result, const colour_t* c, float value );
MYLLY_API void			colour_subtract_scalar	( colour_t* result, const colour_t* c, float value );

MYLLY_API void			colour_invert			( colour_t* result, const colour_t* c );
MYLLY_API void			colour_invert_no_alpha	( colour_t* result, const colour_t* c );
MYLLY_API void			colour_lerp				( colour_t* result, const colour_t* c1, const colour_t* c2, float t );
MYLLY_API void			colour_lerp_no_alpha	( colour_t* result, const colour_t* c1, const colour_t* c2, float t );

__END_DECLS

#endif /* __MYLLY_COLOUR_H */
