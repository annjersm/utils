#ifndef ANDERS_VECTOR_H
#define ANDERS_VECTOR_H

#include <anders/types.h>
#include <math.h>

#if true
	#define vec2(x, y)       (vec2){{x, y}}
	#define vec3(x, y, z)    (vec3){{x, y, z}}
	#define vec4(x, y, z, w) (vec4){{x, y, z, w}}
#else
	#define vec2(...) (vec2){__VA_ARGS__}
	#define vec3(...) (vec3){__VA_ARGS__}
	#define vec4(...) (vec4){__VA_ARGS__}
#endif

vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_addf(vec2 a, float b);
vec3 vec3_add(vec3 a, vec3 b);
vec3 vec3_addf(vec3 a, float b);
vec4 vec4_add(vec4 a, vec4 b);
vec4 vec4_addf(vec4 a, float b);
#define vec_add(a, b) \
	_Generic((a), \
		vec2: _Generic((b), vec2: vec2_add, float: vec2_addf, default: vec2_add), \
		vec3: _Generic((b), vec3: vec3_add, float: vec3_addf, default: vec3_add), \
		vec4: _Generic((b), vec4: vec4_add, float: vec4_addf, default: vec4_add)  \
	)((a),(b))

vec2 vec2_div(vec2 a, vec2 b);
vec2 vec2_divf(vec2 a, float b);
vec3 vec3_div(vec3 a, vec3 b);
vec3 vec3_divf(vec3 a, float b);
vec4 vec4_div(vec4 a, vec4 b);
vec4 vec4_divf(vec4 a, float b);
#define vec_div(a, b) \
	_Generic((a), \
		vec2: _Generic((b), vec2: vec2_div, float: vec2_divf, default: vec2_div), \
		vec3: _Generic((b), vec3: vec3_div, float: vec3_divf, default: vec3_div), \
		vec4: _Generic((b), vec4: vec4_div, float: vec4_divf, default: vec4_div)  \
	)((a),(b))

vec2 vec2_mul(vec2 a, vec2 b);
vec2 vec2_mulf(vec2 a, float b);
vec3 vec3_mul(vec3 a, vec3 b);
vec3 vec3_mulf(vec3 a, float b);
vec4 vec4_mul(vec4 a, vec4 b);
vec4 vec4_mulf(vec4 a, float b);
#define vec_mul(a, b) \
	_Generic((a), \
		vec2: _Generic((b), vec2: vec2_mul, float: vec2_mulf, default: vec2_mul), \
		vec3: _Generic((b), vec3: vec3_mul, float: vec3_mulf, default: vec3_mul), \
		vec4: _Generic((b), vec4: vec4_mul, float: vec4_mulf, default: vec4_mul)  \
	)((a),(b))

vec2 vec2_sub(vec2 a, vec2 b);
vec2 vec2_subf(vec2 a, float b);
vec3 vec3_sub(vec3 a, vec3 b);
vec3 vec3_subf(vec3 a, float b);
vec4 vec4_sub(vec4 a, vec4 b);
vec4 vec4_subf(vec4 a, float b);
#define vec_sub(a, b) \
	_Generic((a), \
		vec2: _Generic((b), vec2: vec2_sub, float: vec2_subf, default: vec2_sub), \
		vec3: _Generic((b), vec3: vec3_sub, float: vec3_subf, default: vec3_sub), \
		vec4: _Generic((b), vec4: vec4_sub, float: vec4_subf, default: vec4_sub)  \
	)((a),(b))

vec3 cross(vec3 a, vec3 b) ;
float vec2_dot(vec2 a, vec2 b);
float vec3_dot(vec3 a, vec3 b);
float vec4_dot(vec4 a, vec4 b);
#define dot(a, b) \
	_Generic((a), \
			vec2: vec2_dot, \
			vec3: vec3_dot, \
			vec4: vec4_dot  \
			)((a),(b))

float vec2_length(vec2 v);
float vec3_length(vec3 v);
float vec4_length(vec4 v);
#define length(a) \
	_Generic((a), vec2: vec2_length, vec3: vec3_length, vec4: vec4_length \
			)((a))

vec2 vec2_normalize(vec2 v);
vec3 vec3_normalize(vec3 v);
vec4 vec4_normalize(vec4 v);
#define normalize(a) \
	_Generic((a), \
			vec2: vec2_normalize, \
			vec3: vec3_normalize, \
			vec4: vec4_normalize  \
		)((a))

void print_vec2(vec2 v);
void print_vec3(vec3 v);
void print_vec4(vec4 v);
#define vec_print(a) \
	_Generic((a), \
			vec2: print_vec2, \
			vec3: print_vec3, \
			vec4: print_vec4  \
	)((a))

#endif // ANDERS_VECTOR_H
