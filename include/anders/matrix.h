#ifndef ANDERS_MATRIX_H
#define ANDERS_MATRIX_H

#include <anders/types.h>
#include <anders/vector.h>

#define mat2(a1,a2,b1,b2) (mat2){{ \
	a1,a2,          \
	b1,b2           \
}}
#define mat3(a1,a2,a3,b1,b2,b3,c1,c2,c3) (mat3){{ \
	a1,a2,a3,       \
	b1,b2,b3,       \
	c1,c2,c3        \
}}
#define mat4(a1,a2,a3,a4,b1,b2,b3,b4,c1,c2,c3,c4,d1,d2,d3,d4) (mat4){{ \
	a1,a2,a3,a4,    \
	b1,b2,b3,b4,    \
	c1,c2,c3,c4,    \
	d1,d2,d3,d4     \
}}


/* mat2 */
mat2 identity2(float i);
//#define mat2(i) identity2(i)
mat2 add2(mat2 a, mat2 b);
mat2 sub2(mat2 a, mat2 b);
mat2 mul2(mat2 a, mat2 b);
//mat2 div2(mat2 a, mat2 b);
void print_mat2(mat2 m);

/* mat3 */
mat3 identity3(float i);
//#define mat3(i) identity3(i)
mat3 add3(mat3 a, mat3 b);
mat3 sub3(mat3 a, mat3 b);
mat3 mul3(mat3 a, mat3 b);
//mat3 div3(mat3 a, mat3 b);
void print_mat3(mat3 m);

/* mat4 */
mat4 identity4(float i);
//#define mat4(i) identity4(i)
#define identity(i) identity4(i)
mat4 add4(mat4 a, mat4 b);
mat4 sub4(mat4 a, mat4 b);
mat4 mul4(mat4 a, mat4 b);
//mat4 div4(mat4 a, mat4 b);
void print_mat4(mat4 m);

#define mat_print(a) \
	_Generic((a), \
			mat2: print_mat2, \
			mat3: print_mat3, \
			mat4: print_mat4 \
			)((a))

static inline mat4 mat4_look_at(vec3 pos, vec3 target, vec3 up)
{
	mat4 matrix = identity(1.0f);
	mat4 translation = identity(1.0f);

	vec3 direction = normalize(vec_sub(pos, target));
	vec3 right = normalize(cross(up, direction));
	vec3 u = cross(direction, right);

	matrix.m[0][0] = right.x;
	matrix.m[0][1] = right.y;
	matrix.m[0][2] = right.z;
                   
	matrix.m[1][0] = u.x;
	matrix.m[1][1] = u.y;
	matrix.m[1][2] = u.z;
                   
	matrix.m[2][0] = -direction.x;
	matrix.m[2][1] = -direction.y;
	matrix.m[2][2] = -direction.z;
                   
	matrix.m[0][3] = -dot(right, pos);
	matrix.m[1][3] = -dot(u, pos);
	matrix.m[2][3] = dot(direction, pos);
	return mul4(matrix, translation);
}

static inline mat4 mat4_orthographic(float l, float r, float b, float t, float f, float n)
{
	return (mat4) {{
		2/(r-l), 0, 0, -((r+l)/(r-l)),
		0, 2/(t-b), 0, -((t+b)/(t-b)),
		0, 0, -2/(f-n), -((f+n)/(f-n)),
		0, 0, 0, 1
	}};
}

static inline mat4 mat4_perspective(float fov, float aspect, float near, float  far)
{
	mat4 matrix = { .m = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1}};
	if (near <= 0.0f || far <= near || aspect <= 0.0f)
		return identity4(1.0f);
	float f = 1.0f / tanf(fov * 0.5f);
	matrix.data[0] = f / aspect;
	matrix.data[5] = f;
	matrix.data[10] = (far + near) / (near - far);
	matrix.data[11] = (2.0f * far * near) / (near -far);
	matrix.data[14] = -1.0f;
	matrix.data[15] = 0.0f;
	return matrix;
}

static inline mat4 mat4_perspective_inf(float fov, float aspect, float near, float  far)
{
	mat4 matrix = { .m = {1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1}};
	float f = 1.0f / tanf(fov * 0.5f * (float)PI / 180.0f);
	matrix.data[0] = f / aspect;
	matrix.data[5] = f;
	matrix.data[10] = -1.0f;
	matrix.data[11] = -1.0f;
	matrix.data[14] = -2.0f * near;
	matrix.data[15] = 0.0f;
	return matrix;
}

static inline mat4 rotate(mat4 matrix, float radians, vec3 vector)
{
	float rot_x = vector.x;
	float rot_y = vector.y;
	float rot_z = vector.z;
	float c = cosf(radians);
	float s = sinf(radians);
	float t = 1.0f - c;

	float len = 1.0f / sqrtf(rot_x*rot_x + rot_y*rot_y + rot_z*rot_z);
	if (len < 1e-8f) return matrix;
	float inv_len = 1.0 / len;
	float x = rot_x * inv_len;
	float y = rot_y * inv_len;
	float z = rot_z * inv_len;
	mat4 rot = { .m = {
		t*x*x + c,     t*x*y + s*z,   t*x*z - s*y,   0.0f,
		t*x*y - s*z,   t*y*y + c,     t*y*z + s*x,   0.0f,
		t*x*z + s*y,   t*y*z - s*x,   t*z*z + c,     0.0f,
		0.0f,          0.0f,          0.0f,          1.0f
	}};
	return mul4(matrix, rot);
}

static inline mat4 scale(mat4 m, vec3 v)
{
	return mul4(m, mat4(
			v.x, 0, 0, 0,
			0, v.y, 0, 0,
			0, 0, v.z, 0,
			0, 0, 0, 1
			));
}

static inline mat4 translate(mat4 m, vec3 v)
{
	return mul4(m, mat4(
			1, 0, 0, v.x,
			0, 1, 0, v.y,
			0, 0, 1, v.z,
			0, 0, 0, 1
			));
}

static inline vec4 add_vec4(mat4 m, vec4 v)
{
	vec4 r = {0};
	for (int i = 0; i < 4; i++)
		r.data[i] = m.data[0+i*4] * v.x +
			    m.data[1+i*4] * v.y +
			    m.data[2+i*4] * v.z +
			    m.data[3+i*4] * v.w;
	return r;
}
#endif // ANDERS_MATRIX_H
