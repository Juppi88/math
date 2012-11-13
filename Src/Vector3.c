/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Vector3.c
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 3D vector structure and functions to manipulate them.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#include "Math/Vector3.h"
#include <math.h>

#define VECTOR3_EPSILON 0.001f

void vector3_add( vector3_t* result, const vector3_t* v1, const vector3_t* v2 )
{
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
}

void vector3_subtract( vector3_t* result, const vector3_t* v1, const vector3_t* v2 )
{
	result->x = v1->x - v2->x;
	result->y = v1->y - v2->y;
	result->z = v1->z - v2->z;
}

void vector3_multiply( vector3_t* result, const vector3_t* v, float value )
{
	result->x = v->x * value;
	result->y = v->y * value;
	result->z = v->z * value;
}

void vector3_divide( vector3_t* result, const vector3_t* v, float value )
{
	result->x = v->x / value;
	result->y = v->y / value;
	result->z = v->z / value;
}

void vector3_add_scalar( vector3_t* result, const vector3_t* v, float value )
{
	result->x = v->x + value;
	result->y = v->y + value;
	result->z = v->z + value;
}

void vector3_subtract_scalar( vector3_t* result, const vector3_t* v, float value )
{
	result->x = v->x - value;
	result->y = v->y - value;
	result->z = v->z - value;
}

float vector3_dot( const vector3_t* v1, const vector3_t* v2 )
{
	return v1->x*v2->x + v1->y*v2->y + v1->z*v2->z;
}

void vector3_cross( vector3_t* result, const vector3_t* v1, const vector3_t* v2 )
{
	result->x = v1->y*v2->z - v1->z*v2->y;
	result->y = v1->z*v2->x - v1->x*v2->z;
	result->z = v1->x*v2->y - v1->y*v2->x;
}

float vector3_angle( const vector3_t* v1, const vector3_t* v2 )
{
	return acosf( vector3_dot( v1, v2 ) / vector3_length( v1 ) / vector3_length( v2 ) );
}

float vector3_length( const vector3_t* v )
{
	return sqrtf( v->x*v->x + v->y*v->y + v->z*v->z );
}

float vector3_length_sq( const vector3_t* v )
{
	return v->x*v->x + v->y*v->y + v->z*v->z;
}

float vector3_distance( const vector3_t* v1, const vector3_t* v2 )
{
	float x, y, z;

	x = v2->x - v1->x;
	y = v2->y - v1->y;
	z = v2->z - v1->z;

	return sqrtf( x*x + y*y + z*z );
}

float vector3_distance_sq( const vector3_t* v1, const vector3_t* v2 )
{
	float x, y, z;

	x = v2->x - v1->x;
	y = v2->y - v1->y;
	z = v2->z - v1->z;

	return x*x + y*y + z*z;
}

void vector3_normalize( vector3_t* v )
{
	float factor = sqrtf( v->x*v->x + v->y*v->y + v->z*v->z );

	if ( factor < VECTOR3_EPSILON ) return;

	v->x /= factor;
	v->y /= factor;
	v->z /= factor;
}

void vector3_lerp( vector3_t* result, const vector3_t* v1, const vector3_t* v2, float t )
{
	result->x = v1->x + ( v2->x - v1->x ) * t;
	result->y = v1->y + ( v2->y - v1->y ) * t;
	result->z = v1->z + ( v2->z - v1->z ) * t;
}
