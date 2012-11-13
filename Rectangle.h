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

typedef union {
	struct {
		uint16 x, y, w, h;
	};
	struct {
		vectorscreen_t pos;
		vectorscreen_t size;
	};
} rectangle_t;

__BEGIN_DECLS

MYLLY_API bool			rect_is_point_in		( const rectangle_t* r, uint16 x, uint16 y );
MYLLY_API bool			rect_is_in				( const rectangle_t* r1, const rectangle_t* r2 );
MYLLY_API bool			rect_equals				( const rectangle_t* r1, const rectangle_t* r2 );

__END_DECLS

#endif /* __MYLLY_RECTANGLE_H */
