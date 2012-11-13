/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Vector2.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 2D vector structure and functions to manipulate them.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#include "Math/Vector2.h"
#include <math.h>

#define VECTOR2_EPSILON 0.001f

void vector2_add( vector2_t* result, const vector2_t* v1, const vector2_t* v2 )
{
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
}

void vector2_subtract( vector2_t* result, const vector2_t* v1, const vector2_t* v2 )
{
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
}

void vector2_multiply( vector2_t* result, const vector2_t* v, float value )
{
	result->x = v->x * value;
	result->y = v->y * value;
}

void vector2_divide( vector2_t* result, const vector2_t* v, float value )
{
	result->x = v->x / value;
	result->y = v->y / value;
}

void vector2_add_scalar( vector2_t* result, const vector2_t* v, float value )
{
	result->x = v->x + value;
	result->y = v->y + value;
}

void vector2_subtract_scalar( vector2_t* result, const vector2_t* v, float value )
{
	result->x = v->x - value;
	result->y = v->y - value;
}

float vector2_dot( const vector2_t* v1, const vector2_t* v2 )
{
	return v1->x*v2->x + v1->y*v2->y;
}

float vector2_angle( const vector2_t* v1, const vector2_t* v2 )
{
	return acosf( vector2_dot( v1, v2 ) / vector2_length( v1 ) / vector2_length( v2 ) );
}

float vector2_length( const vector2_t* v )
{
	return sqrtf( v->x*v->x + v->y*v->y );
}

float vector2_length_sq( const vector2_t* v )
{
	return v->x*v->x + v->y*v->y;
}

float vector2_distance( const vector2_t* v1, const vector2_t* v2 )
{
	float x, y;

	x = v2->x - v1->x;
	y = v2->y - v1->y;

	return sqrtf( x*x + y*y );
}

float vector2_distance_sq( const vector2_t* v1, const vector2_t* v2 )
{
	float x, y;

	x = v2->x - v1->x;
	y = v2->y - v1->y;

	return x*x + y*y;
}

void vector2_normalize( vector2_t* v )
{
	float factor = sqrtf( v->x*v->x + v->y*v->y );

	if ( factor < VECTOR2_EPSILON ) return;

	v->x /= factor;
	v->y /= factor;
}

void vector2_lerp( vector2_t* result, const vector2_t* v1, const vector2_t* v2, float t )
{
	result->x = v1->x + ( v2->x - v1->x ) * t;
	result->y = v1->y + ( v2->y - v1->y ) * t;
}
