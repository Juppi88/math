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

#ifdef __cplusplus

// A colour implementation for C++
union colour_t
{
	colour_t() { r = 0; g = 0; b = 0; a = 255; }
	colour_t( uint32 i ) { hex = i; }
	colour_t( uint8 R, uint8 G, uint8 B ) { r = R; g = G; b = B; a = 255; }
	colour_t( uint8 R, uint8 G, uint8 B, uint8 A ) { r = R; g = G; b = B; a = A; }

	uint32 hex;						// Hex colour

#ifdef MYLLY_BIG_ENDIAN
	struct { uint8 r, g, b, a; };	// RGBA colour (big endian)
#else
	struct { uint8 a, b, g, r; };	// RGBA colour (little endian)
#endif
};

#else

// Pure C colour
typedef union
{
	uint32 hex;						// Hex colour
	
#ifdef MYLLY_BIG_ENDIAN
	struct { uint8 r, g, b, a; };	// RGBA colour (big endian)
#else
	struct { uint8 a, b, g, r; };	// RGBA colour (little endian)
#endif

} colour_t;

#endif

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
