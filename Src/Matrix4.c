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

#include "Math/Matrix4.h"

#define SM (8 / sizeof(float))
#define MATRIX4_EPSILON 0.0001f

void matrix4_add( matrix4_t* result, const matrix4_t* mat1, const matrix4_t* mat2 )
{
	int32 i;

	for ( i = 0; i < 4; i++ )
	{
		result->m[i][0] = mat1->m[i][0] + mat2->m[i][0];
		result->m[i][1] = mat1->m[i][1] + mat2->m[i][1];
		result->m[i][2] = mat1->m[i][2] + mat2->m[i][2];
		result->m[i][3] = mat1->m[i][3] + mat2->m[i][3];
	}
}

void matrix4_subtract( matrix4_t* result, const matrix4_t* mat1, const matrix4_t* mat2 )
{
	int32 i;

	for ( i = 0; i < 4; i++ )
	{
		result->m[i][0] = mat1->m[i][0] - mat2->m[i][0];
		result->m[i][1] = mat1->m[i][1] - mat2->m[i][1];
		result->m[i][2] = mat1->m[i][2] - mat2->m[i][2];
		result->m[i][3] = mat1->m[i][3] - mat2->m[i][3];
	}
}

void matrix4_multiply( matrix4_t* result, const matrix4_t* mat1, const matrix4_t* mat2 )
{
	// An optimised version found on http://www.akkadia.org/drepper/cpumemory.pdf page 50.

	uint32 i, j, k, i2, j2, k2;
	float *pres, *pmat1, *pmat2;

	for ( i = 0; i < 4; i += SM )
		for ( j = 0; j < 4; j += SM )
			for ( k = 0; k < 4; k += SM )
				for ( i2 = 0, pres = (float*)&result->m[i][j], pmat1 = (float*)&mat1->m[i][k]; i2 < SM; ++i2, pres += 4, pmat1 += 4 )
					for ( k2 = 0, pmat2 = (float*)&mat2->m[k][j]; k2 < SM; ++k2, pmat2 += 4 )
						for ( j2 = 0; j2 < SM; ++j2 )
							pres[j2] += pmat1[k2] * pmat2[j2];
}

void matrix4_add_scalar( matrix4_t* result, const matrix4_t* mat, float f )
{
	int32 i;

	for ( i = 0; i < 4; i++ )
	{
		result->m[i][0] = mat->m[i][0] + f;
		result->m[i][1] = mat->m[i][1] + f;
		result->m[i][2] = mat->m[i][2] + f;
		result->m[i][3] = mat->m[i][3] + f;
	}
}

void matrix4_subtract_scalar( matrix4_t* result, const matrix4_t* mat, float f )
{
	int32 i;

	for ( i = 0; i < 4; i++ )
	{
		result->m[i][0] = mat->m[i][0] - f;
		result->m[i][1] = mat->m[i][1] - f;
		result->m[i][2] = mat->m[i][2] - f;
		result->m[i][3] = mat->m[i][3] - f;
	}
}

void matrix4_multiply_scalar( matrix4_t* result, const matrix4_t* mat, float f )
{
	int32 i;

	for ( i = 0; i < 4; i++ )
	{
		result->m[i][0] = mat->m[i][0] * f;
		result->m[i][1] = mat->m[i][1] * f;
		result->m[i][2] = mat->m[i][2] * f;
		result->m[i][3] = mat->m[i][3] * f;
	}
}

void matrix4_divide_scalar( matrix4_t* result, const matrix4_t* mat, float f )
{
	int32 i;

	if ( f < MATRIX4_EPSILON ) return;

	for ( i = 0; i < 4; i++ )
	{
		result->m[i][0] = mat->m[i][0] / f;
		result->m[i][1] = mat->m[i][1] / f;
		result->m[i][2] = mat->m[i][2] / f;
		result->m[i][3] = mat->m[i][3] / f;
	}
}

void matrix4_identity( matrix4_t* mat )
{
	mat->_12 = mat->_13 = mat->_14 =
	mat->_21 = mat->_23 = mat->_24 =
	mat->_31 = mat->_32 = mat->_34 =
	mat->_41 = mat->_42 = mat->_43 = 0.0f;

	mat->_11 = mat->_22 = mat->_33 = mat->_44 = 1.0f;
}

void matrix4_transpose( matrix4_t* result, const matrix4_t* mat )
{
	int32 i, j;
	float tmp;

	for ( i = 0; i < 4; i++ )
	{
		for ( j = 0; j < 4; j++ )
		{
			tmp = mat->m[i][j];
			result->m[i][j] = mat->m[j][i];
			result->m[j][i] = tmp;
		}
	}
}
