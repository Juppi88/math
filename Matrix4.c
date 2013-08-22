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
#include "Math/MathUtils.h"

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
	if ( result == NULL || mat1 == NULL || mat2 == NULL ) return;

	result->_11 = mat1->_11*mat2->_11 + mat1->_12*mat2->_21 + mat1->_13*mat2->_31 + mat1->_14*mat2->_41;
	result->_12 = mat1->_11*mat2->_12 + mat1->_12*mat2->_22 + mat1->_13*mat2->_32 + mat1->_14*mat2->_42;
	result->_13 = mat1->_11*mat2->_13 + mat1->_12*mat2->_23 + mat1->_13*mat2->_33 + mat1->_14*mat2->_43;
	result->_14 = mat1->_11*mat2->_14 + mat1->_12*mat2->_24 + mat1->_13*mat2->_34 + mat1->_14*mat2->_44;

	result->_21 = mat1->_21*mat2->_11 + mat1->_22*mat2->_21 + mat1->_23*mat2->_31 + mat1->_24*mat2->_41;
	result->_22 = mat1->_21*mat2->_12 + mat1->_22*mat2->_22 + mat1->_23*mat2->_32 + mat1->_24*mat2->_42;
	result->_23 = mat1->_21*mat2->_13 + mat1->_22*mat2->_23 + mat1->_23*mat2->_33 + mat1->_24*mat2->_43;
	result->_24 = mat1->_21*mat2->_14 + mat1->_22*mat2->_24 + mat1->_23*mat2->_34 + mat1->_24*mat2->_44;

	result->_31 = mat1->_31*mat2->_11 + mat1->_32*mat2->_21 + mat1->_33*mat2->_31 + mat1->_34*mat2->_41;
	result->_32 = mat1->_31*mat2->_12 + mat1->_32*mat2->_22 + mat1->_33*mat2->_32 + mat1->_34*mat2->_42;
	result->_33 = mat1->_31*mat2->_13 + mat1->_32*mat2->_23 + mat1->_33*mat2->_33 + mat1->_34*mat2->_43;
	result->_34 = mat1->_31*mat2->_14 + mat1->_32*mat2->_24 + mat1->_33*mat2->_34 + mat1->_34*mat2->_44;

	result->_41 = mat1->_41*mat2->_11 + mat1->_42*mat2->_21 + mat1->_43*mat2->_31 + mat1->_44*mat2->_41;
	result->_42 = mat1->_41*mat2->_12 + mat1->_42*mat2->_22 + mat1->_43*mat2->_32 + mat1->_44*mat2->_42;
	result->_43 = mat1->_41*mat2->_13 + mat1->_42*mat2->_23 + mat1->_43*mat2->_33 + mat1->_44*mat2->_43;
	result->_44 = mat1->_41*mat2->_14 + mat1->_42*mat2->_24 + mat1->_43*mat2->_34 + mat1->_44*mat2->_44;

	/*// An optimised version found on http://www.akkadia.org/drepper/cpumemory.pdf page 50.

	uint32 i, j, k, i2, j2, k2;
	float *pres, *pmat1, *pmat2;

	for ( i = 0; i < 4; i += SM )
		for ( j = 0; j < 4; j += SM )
			for ( k = 0; k < 4; k += SM )
				for ( i2 = 0, pres = (float*)&result->m[i][j], pmat1 = (float*)&mat1->m[i][k]; i2 < SM; ++i2, pres += 4, pmat1 += 4 )
					for ( k2 = 0, pmat2 = (float*)&mat2->m[k][j]; k2 < SM; ++k2, pmat2 += 4 )
						for ( j2 = 0; j2 < SM; ++j2 )
							pres[j2] += pmat1[k2] * pmat2[j2];*/
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

float matrix4_inverse( matrix4_t* result, const matrix4_t* mat )
{
	float det, retn, t[3], v[16];
	uint32 i, j;

	if ( result == NULL || mat == NULL ) return 0;

	// Calculate the determinant
	t[0] = mat->_33 * mat->_44 - mat->_34 * mat->_43;
	t[1] = mat->_32 * mat->_44 - mat->_24 * mat->_43;
	t[2] = mat->_23 * mat->_34 - mat->_24 * mat->_33;
	v[0] = mat->_22 * t[0] - mat->_32 * t[1] + mat->_42 * t[2];
	v[4] = -mat->_21 * t[0] + mat->_31 * t[1] - mat->_41 * t[2];

	t[0] = mat->_21 * mat->_32 - mat->_31 * mat->_22;
	t[1] = mat->_21 * mat->_42 - mat->_41 * mat->_22;
	t[2] = mat->_31 * mat->_42 - mat->_41 * mat->_32;
	v[8] = mat->_44 * t[0] - mat->_34 * t[1] + mat->_24 * t[2];
	v[12] = -mat->_43 * t[0] + mat->_33 * t[1] - mat->_23 * t[2];

	retn = det = mat->_11 * v[0] + mat->_12 * v[4] + mat->_13 * v[8] + mat->_14 * v[12];

	// This matrix can't be inverted
	if ( det == 0.0f ) return retn;

	t[0] = mat->_33 * mat->_44 - mat->_34 * mat->_43;
	t[1] = mat->_13 * mat->_44 - mat->_14 * mat->_43;
	t[2] = mat->_13 * mat->_34 - mat->_14 * mat->_33;
	v[1] = -mat->_12 * t[0] + mat->_32 * t[1] - mat->_42 * t[2];
	v[5] = mat->_11 * t[0] - mat->_31 * t[1] + mat->_41 * t[2];

	t[0] = mat->_11 * mat->_32 - mat->_31 * mat->_12;
	t[1] = mat->_41 * mat->_12 - mat->_11 * mat->_42;
	t[2] = mat->_31 * mat->_42 - mat->_41 * mat->_32;
	v[9] = -mat->_44 * t[0] - mat->_34 * t[1]- mat->_14 * t[2];
	v[13] = mat->_43 * t[0] + mat->_33 * t[1] + mat->_13 * t[2];

	t[0] = mat->_23 * mat->_44 - mat->_24 * mat->_43;
	t[1] = mat->_13 * mat->_44 - mat->_14 * mat->_43;
	t[2] = mat->_13 * mat->_24 - mat->_14 * mat->_23;
	v[2] = mat->_12 * t[0] - mat->_22 * t[1] + mat->_42 * t[2];
	v[6] = -mat->_11 * t[0] + mat->_21 * t[1] - mat->_41 * t[2];

	t[0] = mat->_11 * mat->_22 - mat->_21 * mat->_12;
	t[1] = mat->_41 * mat->_12 - mat->_11 * mat->_42;
	t[2] = mat->_21 * mat->_42 - mat->_41 * mat->_22;
	v[10] = mat->_44 * t[0] + mat->_24 * t[1] + mat->_14 * t[2];
	v[14] = -mat->_43 * t[0] - mat->_23 * t[1] - mat->_13 * t[2];

	t[0] = mat->_23 * mat->_34 - mat->_24 * mat->_33;
	t[1] = mat->_13 * mat->_34 - mat->_14 * mat->_33;
	t[2] = mat->_13 * mat->_24 - mat->_14 * mat->_23;
	v[3] = -mat->_12 * t[0] + mat->_22 * t[1] - mat->_32 * t[2];
	v[7] = mat->_11 * t[0] - mat->_21 * t[1] + mat->_31 * t[2];

	v[11] = -mat->_11 * ( mat->_22 * mat->_34 - mat->_24 * mat->_32 ) +
		mat->_21 * ( mat->_12 * mat->_34 - mat->_14 * mat->_32 ) -
		mat->_31 * ( mat->_12 * mat->_24 - mat->_14 * mat->_22 );

	v[15] = mat->_11 * ( mat->_22 * mat->_33 - mat->_23 * mat->_32 ) -
		mat->_21 * ( mat->_12 * mat->_33 - mat->_13 * mat->_32 ) +
		mat->_31 * ( mat->_12 * mat->_23 - mat->_13 * mat->_22 );

	det = 1.0f / det;

	for ( i = 0; i < 4; ++i )
		for ( j = 0; j < 4; ++j )
			result->m[i][j] = v[4*i+j] * det;

	return retn;
}

float matrix4_determinant( const matrix4_t* mat )
{
	float t[3], v[4];

	if ( mat == NULL ) return 0;

	t[0] = mat->_33 * mat->_44 - mat->_34 * mat->_43;
	t[1] = mat->_32 * mat->_44 - mat->_24 * mat->_43;
	t[2] = mat->_23 * mat->_34 - mat->_24 * mat->_33;
	v[0] = mat->_22 * t[0] - mat->_32 * t[1] + mat->_42 * t[2];
	v[1] = -mat->_21 * t[0] + mat->_31 * t[1] - mat->_41 * t[2];

	t[0] = mat->_21 * mat->_32 - mat->_31 * mat->_22;
	t[1] = mat->_21 * mat->_42 - mat->_41 * mat->_22;
	t[2] = mat->_31 * mat->_42 - mat->_41 * mat->_32;
	v[2] = mat->_44 * t[0] - mat->_34 * t[1] + mat->_24 * t[2];
	v[3] = -mat->_43 * t[0] + mat->_33 * t[1] - mat->_23 * t[2];

	return mat->_11 * v[0] + mat->_12 * v[1] + mat->_13 * v[2] + mat->_14 * v[3];
}

void matrix4_translation( matrix4_t* mat, float x, float y, float z )
{
	if ( mat == NULL ) return;

	mat->_12 = mat->_13 = mat->_14 =
	mat->_21 = mat->_23 = mat->_24 =
	mat->_31 = mat->_32 = mat->_34 = 0.0f;

	mat->_11 = mat->_22 = mat->_33 = mat->_44 = 1.0f;

	mat->_41 = x; mat->_42 = y; mat->_43 = z;
}

void matrix4_rotation_x( matrix4_t* mat, float rad )
{
	float fsin, fcos;

	if ( mat == NULL ) return;

	mat->_12 = mat->_13 = mat->_14 =
	mat->_21 = mat->_24 =
	mat->_31 = mat->_34 =
	mat->_41 = mat->_42 = mat->_43 = 0.0f;

	mat->_11 = mat->_44 = 1.0f;

	sincosf( rad, &fsin, &fcos );

	mat->_22 = fcos; mat->_23 = fsin;
	mat->_32 = -fsin; mat->_33 = fcos;
}

void matrix4_rotation_y( matrix4_t* mat, float rad )
{
	float fsin, fcos;

	if ( mat == NULL ) return;

	mat->_12 = mat->_14 =
	mat->_21 = mat->_23 = mat->_24 =
	mat->_32 = mat->_34 =
	mat->_41 = mat->_42 = mat->_43 = 0.0f;

	mat->_22 = mat->_44 = 1.0f;

	sincosf( rad, &fsin, &fcos );

	mat->_11 = fcos; mat->_13 = -fsin;
	mat->_31 = fsin; mat->_33 = fcos;
}

void matrix4_rotation_z( matrix4_t* mat, float rad )
{
	float fsin, fcos;

	if ( mat == NULL ) return;

	mat->_13 = mat->_14 =
	mat->_23 = mat->_24 =
	mat->_31 = mat->_32 = mat->_34 =
	mat->_41 = mat->_42 = mat->_43 = 0.0f;

	mat->_33 = mat->_44 = 1.0f;

	sincosf( rad, &fsin, &fcos );

	mat->_11 = fcos; mat->_12 = fsin;
	mat->_21 = -fsin; mat->_33 = fcos;
}

void matrix4_scale( matrix4_t* mat, float x_scale, float y_scale, float z_scale )
{
	if ( mat == NULL ) return;

	mat->_12 = mat->_13 = mat->_14 =
	mat->_21 = mat->_23 = mat->_24 =
	mat->_31 = mat->_32 = mat->_34 =
	mat->_41 = mat->_42 = mat->_43 = 0.0f;

	mat->_44 = 1.0f;

	mat->_11 = x_scale; mat->_22 = y_scale; mat->_33 = z_scale;
}
