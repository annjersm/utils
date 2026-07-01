#ifndef ANDERS_MATH_H
#define ANDERS_MATH_H

#include <anders/types.h>

static inline float get_degrees(float radians)
{
	return radians * (180 / PI);
}

static inline float get_radians(float degrees)
{
	return degrees * (PI / 180);
}

float sigmoid(float x);

#endif // ANDERS_MATH_H
