/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		Matrix4.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		A 4x4 matrix structure and functions to manipulate them.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_MATRIX4_H
#define __MYLLY_MATRIX4_H

#include "stdtypes.h"

#ifdef __cplusplus

// A vector implementation for C++
union matrix4_t
{
public:
	matrix4_t()
	{
		_11 = _12 = _13 = _14 = 0.0f;
		_21 = _22 = _23 = _24 = 0.0f;
		_31 = _32 = _33 = _34 = 0.0f;
		_41 = _42 = _43 = _44 = 0.0f;
	}

	matrix4_t( const matrix4_t& other )
	{
		_11 = other._11; _12 = other._12; _13 = other._13; _14 = other._14;
		_21 = other._21; _22 = other._22; _23 = other._23; _24 = other._24;
		_31 = other._31; _32 = other._32; _33 = other._33; _34 = other._34;
		_41 = other._41; _42 = other._42; _43 = other._43; _44 = other._44;
	}

public:
	struct {
		float _11, _12, _13, _14;
		float _21, _22, _23, _24;
		float _31, _32, _33, _34;
		float _41, _42, _43, _44;
	};
	float m[4][4];
	float mat[16];
};

#else

// Pure C version of the struct

typedef union
{
	struct {
		float _11, _12, _13, _14;
		float _21, _22, _23, _24;
		float _31, _32, _33, _34;
		float _41, _42, _43, _44;
	};
	float m[4][4];
	float mat[16];
} matrix4_t;

#endif

typedef matrix4_t Matrix4;

__BEGIN_DECLS

void		matrix4_add				( matrix4_t* result, const matrix4_t* mat1, const matrix4_t* mat2 );
void		matrix4_subtract		( matrix4_t* result, const matrix4_t* mat1, const matrix4_t* mat2 );
void		matrix4_multiply		( matrix4_t* result, const matrix4_t* mat1, const matrix4_t* mat2 );

void		matrix4_add_scalar		( matrix4_t* result, const matrix4_t* mat, float f );
void		matrix4_subtract_scalar	( matrix4_t* result, const matrix4_t* mat, float f );
void		matrix4_multiply_scalar	( matrix4_t* result, const matrix4_t* mat, float f );
void		matrix4_divide_scalar	( matrix4_t* result, const matrix4_t* mat, float f );

void		matrix4_identity		( matrix4_t* mat );
void		matrix4_transpose		( matrix4_t* result, const matrix4_t* mat );
float		matrix4_inverse			( matrix4_t* result, const matrix4_t* mat );
float		matrix4_determinant		( const matrix4_t* mat );

void		matrix4_translation		( matrix4_t* mat, float x, float y, float z );
void		matrix4_rotation_x		( matrix4_t* mat, float rad );
void		matrix4_rotation_y		( matrix4_t* mat, float rad );
void		matrix4_rotation_z		( matrix4_t* mat, float rad );
void		matrix4_scale			( matrix4_t* mat, float x_scale, float y_scale, float z_scale );

__END_DECLS

#endif /* __MYLLY_MATRIX4_H */
