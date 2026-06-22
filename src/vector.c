#include <anders/vector.h>
#include <stdio.h>

/* Add */
vec2 vec2_add(vec2 a, vec2 b) {
	return vec2(a.x + b.x, a.y + b.y);
}
vec2 vec2_addf(vec2 a, float b) {
	return vec2(a.x + b, a.y + b);
}
vec3 vec3_add(vec3 a, vec3 b) {
	return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}
vec3 vec3_addf(vec3 a, float b) {
	return vec3(a.x + b, a.y + b, a.z + b);
}
vec4 vec4_add(vec4 a, vec4 b) {
	return vec4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}
vec4 vec4_addf(vec4 a, float b) {
	return vec4(a.x + b, a.y + b, a.z + b, a.w + b);
}

/* Div */
vec2 vec2_div(vec2 a, vec2 b) {
	return vec2(a.x / b.x, a.y / b.y);
}
vec2 vec2_divf(vec2 a, float b) {
	return vec2(a.x / b, a.y / b);
}
vec3 vec3_div(vec3 a, vec3 b) {
	return vec3(a.x / b.x, a.y / b.y, a.z / b.z);
}
vec3 vec3_divf(vec3 a, float b) {
	return vec3(a.x / b, a.y / b, a.z / b);
}
vec4 vec4_div(vec4 a, vec4 b) {
	return vec4(a.x / b.x, a.y / b.y, a.z / b.z, a.w / b.w);
}
vec4 vec4_divf(vec4 a, float b) {
	return vec4(a.x / b, a.y / b, a.z / b, a.w / b);
}

/* Mul */
vec2 vec2_mul(vec2 a, vec2 b) {
	return vec2(a.x * b.x, a.y * b.y);
}
vec2 vec2_mulf(vec2 a, float b) {
	return vec2(a.x * b, a.y * b);
}
vec3 vec3_mul(vec3 a, vec3 b) {
	return vec3(a.x * b.x, a.y * b.y, a.z * b.z);
}
vec3 vec3_mulf(vec3 a, float b) {
	return vec3(a.x * b, a.y * b, a.z * b);
}
vec4 vec4_mul(vec4 a, vec4 b) {
	return vec4(a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w);
}
vec4 vec4_mulf(vec4 a, float b) {
	return vec4(a.x * b, a.y * b, a.z * b, a.w * b);
}

/* Sub */
vec2 vec2_sub(vec2 a, vec2 b) {
	return vec2(a.x - b.x, a.y - b.y);
}
vec2 vec2_subf(vec2 a, float b) {
	return vec2(a.x - b, a.y - b);
}
vec3 vec3_sub(vec3 a, vec3 b) {
	return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}
vec3 vec3_subf(vec3 a, float b) {
	return vec3(a.x - b, a.y - b, a.z - b);
}
vec4 vec4_sub(vec4 a, vec4 b) {
	return vec4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}
vec4 vec4_subf(vec4 a, float b) {
	return vec4(a.x - b, a.y - b, a.z - b, a.w - b);
}

vec3 cross(vec3 a, vec3 b)
{
	return (vec3) {{
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	}};
}

float vec3_dot(vec3 a, vec3 b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

float vec2_length(vec2 v) {
	return sqrtf(v.x * v.x + v.y * v.y);
}
float vec3_length(vec3 v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}
float vec4_length(vec4 v) {
	return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

vec3 normalize(vec3 v)
{
	float length = sqrtf(dot(v, v));
	if (length == 0.0f) return v;
	return vec3(v.x / length, v.y / length, v.z / length);
	//return (vec3) {{v.x / length, v.y / length, v.z / length}};
}


void print_vec2(vec2 v)
{
	for (int i = 0; i < 2; i++)
		printf("%.2f ", v.data[i]);
	printf("\n");
}
void print_vec3(vec3 v)
{
	for (int i = 0; i < 3; i++)
		printf("%.2f ", v.data[i]);
	printf("\n");
}
void print_vec4(vec4 v)
{
	for (int i = 0; i < 4; i++)
		printf("%.2f ", v.data[i]);
	printf("\n");
}
