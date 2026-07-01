#ifndef ANDERS_TYPES_H
#define ANDERS_TYPES_H

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef union mat2 mat2;
typedef union mat3 mat3;
typedef union mat4 mat4;

#define PI 3.14159265359

typedef union {
	struct {float x, y;};
	struct {float r, g;};
	float data[2];
} vec2;

typedef union {
	struct {float x, y, z;};
	struct {float r, g, b;};
	float data[3];
} vec3;

typedef union {
	struct {float x, y, z, w;};
	struct {float r, g, b, a;};
	float data[4];
} vec4;

union mat2 {
	struct {vec2 x, y;};
	float data[4];
	float m[2][2];
};

union mat3 {
	struct {vec3 x, y, z;};
	float data[9];
	float m[3][3];
};

union mat4 {
	struct {vec4 x, y, z, w;};
	float data[16];
	float m[4][4];
};

#endif // ANDERS_TYPES_H
