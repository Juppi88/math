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

const float VECTOR3_EPSILON	= 0.001f;
const float VECTOR3_ERROR	= 0.000001f;

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

bool vector3_is_zero( const vector3_t* v )
{
	if ( fabsf( v->x ) < VECTOR3_ERROR &&
		fabsf( v->y ) < VECTOR3_ERROR &&
		fabsf( v->z ) < VECTOR3_ERROR )
		return true;

	return false;
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

void vector3_difference( vector3_t* result, const vector3_t* v1, const vector3_t* v2 )
{
	result->x = v1->x > v2->x ? v1->x - v2->x : v2->x - v1->x;
	result->y = v1->y > v2->y ? v1->y - v2->y : v2->y - v1->y;
	result->z = v1->z > v2->z ? v1->z - v2->z : v2->z - v1->z;
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

void vector3_transform_coord( vector3_t* result, const vector3_t* point, const matrix4_t* mat )
{
	float norm;

	norm = mat->_14 * point->x + mat->_24 * point->y + mat->_34 * point->z + mat->_44;

	result->x = ( mat->_11 * point->x + mat->_21 * point->y + mat->_31 * point->z + mat->_41 ) / norm;
	result->x = ( mat->_12 * point->x + mat->_22 * point->y + mat->_32 * point->z + mat->_42 ) / norm;
	result->x = ( mat->_13 * point->x + mat->_23 * point->y + mat->_33 * point->z + mat->_43 ) / norm;
}
