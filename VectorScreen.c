/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		VectorScreen.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A vector structure for an absolute point on screen.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#include "Math/VectorScreen.h"
#include <math.h>

#define VECTORSCREEN_EPSILON 0.001f

static __inline uint16 clamp( int32 n )
{
	return n < 0 ? 0 : (uint16)n;
}

void vectorscreen_add( vectorscreen_t* result, const vectorscreen_t* v1, const vectorscreen_t* v2 )
{
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
}

void vectorscreen_subtract( vectorscreen_t* result, const vectorscreen_t* v1, const vectorscreen_t* v2 )
{
	result->x = clamp( (int32)v1->x - v2->x );
	result->y = clamp( (int32)v1->y - v2->y );
}

void vectorscreen_multiply( vectorscreen_t* result, const vectorscreen_t* v, float value )
{
	result->x = (uint16)( v->x * value );
	result->y = (uint16)( v->y * value );
}

void vectorscreen_divide( vectorscreen_t* result, const vectorscreen_t* v, float value )
{
	result->x = (uint16)( v->x / value );
	result->y = (uint16)( v->y / value );
}

void vectorscreen_add_scalar( vectorscreen_t* result, const vectorscreen_t* v, float value )
{
	result->x = (uint16)( v->x + value );
	result->y = (uint16)( v->y + value );
}

void vectorscreen_subtract_scalar( vectorscreen_t* result, const vectorscreen_t* v, float value )
{
	result->x = clamp( (int32)( v->x + value ) );
	result->y = clamp( (int32)( v->y + value ) );
}

float vectorscreen_dot( const vectorscreen_t* v1, const vectorscreen_t* v2 )
{
	return (float)( v1->x*v2->x + v1->y*v2->y );
}

float vectorscreen_angle( const vectorscreen_t* v1, const vectorscreen_t* v2 )
{
	return acosf( vectorscreen_dot( v1, v2 ) / vectorscreen_length( v1 ) / vectorscreen_length( v2 ) );
}

float vectorscreen_length( const vectorscreen_t* v )
{
	return sqrtf( v->x*v->x + v->y*v->y );
}

float vectorscreen_length_sq( const vectorscreen_t* v )
{
	return (float)( v->x*v->x + v->y*v->y );
}

float vectorscreen_distance( const vectorscreen_t* v1, const vectorscreen_t* v2 )
{
	int32 x, y;

	x = v2->x - v1->x;
	y = v2->y - v1->y;

	return sqrtf( x*x + y*y );
}

float vectorscreen_distance_sq( const vectorscreen_t* v1, const vectorscreen_t* v2 )
{
	int32 x, y;

	x = v2->x - v1->x;
	y = v2->y - v1->y;

	return (float)( x*x + y*y );
}

void vectorscreen_normalize( vectorscreen_t* v )
{
	float factor = sqrtf( v->x*v->x + v->y*v->y );

	if ( factor < VECTORSCREEN_EPSILON ) return;

	v->x = (uint16)( v->x / factor );
	v->y = (uint16)( v->y / factor );
}

void vectorscreen_lerp( vectorscreen_t* result, const vectorscreen_t* v1, const vectorscreen_t* v2, float t )
{
	result->x = clamp( (int32)( v1->x + ( v2->x - v1->x ) * t ) );
	result->y = clamp( (int32)( v1->y + ( v2->y - v1->y ) * t ) );
}
