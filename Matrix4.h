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

__END_DECLS

#endif /* __MYLLY_MATRIX4_H */
