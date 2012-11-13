/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Rectangle.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 2D rectangle.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#include "Math/Rectangle.h"

bool rect_is_point_in( const rectangle_t* r, uint16 x, uint16 y )
{
	return ( x >= r->x &&
			 y >= r->y &&
			 x <= r->x + r->w &&
			 y <= r->y + r->h ) ? true : false;
}

bool rect_is_in( const rectangle_t* r1, const rectangle_t* r2 )
{
	return ( r1->x <= r2->x &&
			 r1->y <= r2->y &&
			 (r1->x+r1->w) >= (r2->x+r2->w) &&
			 (r1->y+r1->h) >= (r2->y+r2->h) ) ? true : false;
}

bool rect_equals( const rectangle_t* r1, const rectangle_t* r2 )
{
	return ( r1->x == r2->x && r1->y == r2->y && r1->w == r2->w && r1->h == r2->h );
}
