/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Vector4.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 3D vector structure and functions to manipulate them.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#include "Math/Vector4.h"
#include <math.h>

#define VECTOR4_EPSILON 0.001f

void vector4_add( vector4_t* result, const vector4_t* v1, const vector4_t* v2 )
{
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
	result->w = v1->w + v2->w;
}

void vector4_subtract( vector4_t* result, const vector4_t* v1, const vector4_t* v2 )
{
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
	result->z = v1->z - v2->z;
	result->w = v1->w - v2->w;
}

void vector4_multiply( vector4_t* result, const vector4_t* v, float value )
{
	result->x = v->x * value;
	result->y = v->y * value;
	result->z = v->z * value;
	result->w = v->w * value;
}

void vector4_divide( vector4_t* result, const vector4_t* v, float value )
{
	result->x = v->x / value;
	result->y = v->y / value;
	result->z = v->z / value;
	result->w = v->w / value;
}

void vector4_add_scalar( vector4_t* result, const vector4_t* v, float value )
{
	result->x = v->x + value;
	result->y = v->y + value;
	result->z = v->z + value;
	result->w = v->w + value;
}

void vector4_subtract_scalar( vector4_t* result, const vector4_t* v, float value )
{
	result->x = v->x - value;
	result->y = v->y - value;
	result->z = v->z - value;
	result->w = v->w - value;
}

float vector4_dot( const vector4_t* v1, const vector4_t* v2 )
{
	return v1->x*v2->x + v1->y*v2->y + v1->z*v2->z + v1->w*v2->w;
}

float vector4_angle( const vector4_t* v1, const vector4_t* v2 )
{
	return acosf( vector4_dot( v1, v2 ) / vector4_length( v1 ) / vector4_length( v2 ) );
}

float vector4_length( const vector4_t* v )
{
	return sqrtf( v->x*v->x + v->y*v->y + v->z*v->z + v->w*v->w );
}

float vector4_length_sq( const vector4_t* v )
{
	return v->x*v->x + v->y*v->y + v->z*v->z + v->w*v->w;
}

float vector4_distance( const vector4_t* v1, const vector4_t* v2 )
{
	float x, y, z, w;

	x = v2->x - v1->x;
	y = v2->y - v1->y;
	z = v2->z - v1->z;
	w = v2->w - v1->w;

	return sqrtf( x*x + y*y + z*z + w*w );
}

float vector4_distance_sq( const vector4_t* v1, const vector4_t* v2 )
{
	float x, y, z, w;

	x = v2->x - v1->x;
	y = v2->y - v1->y;
	z = v2->z - v1->z;
	w = v2->w - v1->w;

	return x*x + y*y + z*z + w*w;
}

void vector4_normalize( vector4_t* v )
{
	float factor = sqrtf( v->x*v->x + v->y*v->y + v->z*v->z + v->w*v->w );

	if ( factor < VECTOR4_EPSILON ) return;

	v->x /= factor;
	v->y /= factor;
	v->z /= factor;
	v->w /= factor;
}

void vector4_lerp( vector4_t* result, const vector4_t* v1, const vector4_t* v2, float t )
{
	result->x = v1->x + ( v2->x - v1->x ) * t;
	result->y = v1->y + ( v2->y - v1->y ) * t;
	result->z = v1->z + ( v2->z - v1->z ) * t;
	result->w = v1->w + ( v2->w - v1->w ) * t;
}
