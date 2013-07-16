/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Rectangle.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 2D rectangle.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_RECTANGLE_H
#define __MYLLY_RECTANGLE_H

#include "stdtypes.h"
#include "Math/VectorScreen.h"

#ifdef __cplusplus

// A rectangle implementation for C++
union rectangle_t
{
	rectangle_t() { x = 0; y = 0; w = 0; h = 0; }
	rectangle_t( int16 X, int16 Y, uint16 W, uint16 H ) { x = X; y = Y; w = W; h = H; }

	struct {
		int16 x, y;
		uint16 w, h;
	};
	struct {
		uint16 ux, uy, uw, uh;
	};
};

#else

// Pure C version of the struct
typedef union
{
	struct {
		int16 x, y, w, h;
	};
	struct {
		uint16 ux, uy, uw, uh;
	};
	struct {
		vectorscreen_t pos;
		vectorscreen_t size;
	};
} rectangle_t;

#endif

__BEGIN_DECLS

MYLLY_API bool			rect_is_point_in		( const rectangle_t* r, uint16 x, uint16 y );
MYLLY_API bool			rect_is_in				( const rectangle_t* r1, const rectangle_t* r2 );
MYLLY_API bool			rect_equals				( const rectangle_t* r1, const rectangle_t* r2 );

__END_DECLS

#endif /* __MYLLY_RECTANGLE_H */
