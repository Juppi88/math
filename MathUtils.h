/**********************************************************************
 *
 * PROJECT:		Math library
 * FILE:		MathUtils.h
 * LICENCE:		See Licence.txt
 * PURPOSE:		Generic and useful math functions.
 *
 *				(c) Tuomo Jauhiainen 2012
 *
 **********************************************************************/

#pragma once
#ifndef __MYLLY_MATH_UTILS_H
#define __MYLLY_MATH_UTILS_H

#include "stdtypes.h"

#define math_max(x, y)		((x) > (y) ? (x) : (y))
#define math_min(x, y)		((x) < (y) ? (x) : (y))
#define math_abs(x)			(((x) < 0) ? -(x) : (x))

static MYLLY_INLINE int32 math_clamp( int32 value, int32 lower, int32 upper )
{
	value = value > upper ? upper : value;
	return value < lower ? lower : value;
}

static MYLLY_INLINE float math_clampf( float value, float lower, float upper )
{
	value = value > upper ? upper : value;
	return value < lower ? lower : value;
}

#endif /* __MYLLY_MATH_UTILS_H */
