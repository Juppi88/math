/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Colour.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		RGBA colour struct.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#include "Math/Colour.h"

static __inline int8 clamp( int32 n )
{
	n = n > 255 ? 255 : n;
	return n < 0 ? 0 : (uint8)n;
}

void colour_add( colour_t* result, const colour_t* c1, const colour_t* c2 )
{
	result->r = clamp( (int32)c1->r + c2->r );
	result->g = clamp( (int32)c1->g + c2->g );
	result->b = clamp( (int32)c1->b + c2->b );
	result->a = clamp( (int32)c1->a + c2->a );
}

void colour_subtract( colour_t* result, const colour_t* c1, const colour_t* c2 )
{
	result->r = clamp( (int32)c1->r - c2->r );
	result->g = clamp( (int32)c1->g - c2->g );
	result->b = clamp( (int32)c1->b - c2->b );
	result->a = clamp( (int32)c1->a - c2->a );
}

void colour_multiply( colour_t* result, const colour_t* c, float value )
{
	result->r = clamp( (int32)( c->r * value ) );
	result->g = clamp( (int32)( c->g * value ) );
	result->b = clamp( (int32)( c->b * value ) );
	result->a = clamp( (int32)( c->a * value ) );
}

void colour_divide( colour_t* result, const colour_t* c, float value )
{
	result->r = clamp( (int32)( c->r / value ) );
	result->g = clamp( (int32)( c->g / value ) );
	result->b = clamp( (int32)( c->b / value ) );
	result->a = clamp( (int32)( c->a / value ) );
}

void colour_add_scalar( colour_t* result, const colour_t* c, float value )
{
	result->r = clamp( (int32)( c->r + value ) );
	result->g = clamp( (int32)( c->g + value ) );
	result->b = clamp( (int32)( c->b + value ) );
	result->a = clamp( (int32)( c->a + value ) );
}

void colour_subtract_scalar( colour_t* result, const colour_t* c, float value )
{
	result->r = clamp( (int32)( c->r - value ) );
	result->g = clamp( (int32)( c->g - value ) );
	result->b = clamp( (int32)( c->b - value ) );
	result->a = clamp( (int32)( c->a - value ) );
}

void colour_invert( colour_t* result, const colour_t* c )
{
	result->r = 255 - c->r;
	result->g = 255 - c->g;
	result->b = 255 - c->b;
	result->a = 255 - c->a;
}

void colour_invert_no_alpha( colour_t* result, const colour_t* c )
{
	result->r = 255 - c->r;
	result->g = 255 - c->g;
	result->b = 255 - c->b;
}

void colour_lerp( colour_t* result, const colour_t* c1, const colour_t* c2, float t )
{
	result->r = clamp( (int32)( c1->r + ( c2->r - c1->r ) * t ) );
	result->g = clamp( (int32)( c1->g + ( c2->g - c1->g ) * t ) );
	result->b = clamp( (int32)( c1->b + ( c2->b - c1->b ) * t ) );
	result->a = clamp( (int32)( c1->a + ( c2->a - c1->a ) * t ) );
}

void colour_lerp_no_alpha( colour_t* result, const colour_t* c1, const colour_t* c2, float t )
{
	result->r = clamp( (int32)( c1->r + ( c2->r - c1->r ) * t ) );
	result->g = clamp( (int32)( c1->g + ( c2->g - c1->g ) * t ) );
	result->b = clamp( (int32)( c1->b + ( c2->b - c1->b ) * t ) );
}
