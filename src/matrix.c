#include <anders/vector.h>
#include <anders/types.h>
//#include <anders/matrix.h>
#include <stdio.h>

/******************************************************************************/
/************************************ mat2 ************************************/
mat2 identity2(float i)
{
	return (mat2) {{i,0, 0,i}};
}

mat2 add2(mat2 a, mat2 b)
{
	return (mat2) {{
		a.x.x + b.x.x,  a.x.y + b.x.y,
		a.y.x + b.y.x,  a.y.y + b.y.y
	}};
}

mat2 sub2(mat2 a, mat2 b)
{
	return (mat2) {{
		a.x.x - b.x.x,  a.x.y - b.x.y,
		a.y.x - b.y.x,  a.y.y - b.y.y
	}};
}

mat2 mul2(mat2 a, mat2 b)
{
	static const int size = 2;
	mat2 c = {0};
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			for (int i = 0; i < size; i++)
				c.m[x][y] += a.m[x][i] * b.m[i][y];
	return c;
}

/******************************************************************************/
/************************************ mat3 ************************************/
mat3 identity3(float i)
{
	return (mat3) {{i,0,0, 0,i,0, 0,0,i}};
}

mat3 add3(mat3 a, mat3 b)
{
	return (mat3) {{
		a.x.x + b.x.x,   a.x.y + b.x.y,   a.x.z + b.x.z,
		a.y.x + b.y.x,   a.y.y + b.y.y,   a.y.z + b.y.z,
		a.z.x + b.z.x,   a.z.y + b.z.y,   a.z.z + b.z.z
	}};
}

mat3 sub3(mat3 a, mat3 b)
{
	return (mat3) {{
		a.x.x - b.x.x,   a.x.y - b.x.y,   a.x.z - b.x.z,
		a.y.x - b.y.x,   a.y.y - b.y.y,   a.y.z - b.y.z,
		a.z.x - b.z.x,   a.z.y - b.z.y,   a.z.z - b.z.z
	}};
}

mat3 mul3(mat3 a, mat3 b)
{
	static const int size = 3;
	mat3 c = {0};
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			for (int i = 0; i < size; i++)
				c.m[x][y] += a.m[x][i] * b.m[i][y];
	return c;
}

/******************************************************************************/
/************************************ mat4 ************************************/
mat4 identity4(float i)
{
	return (mat4) {{i,0,0,0, 0,i,0,0, 0,0,i,0, 0,0,0,i}};
}

mat4 add4(mat4 a, mat4 b)
{
	return (mat4) {{
		a.x.x + b.x.x,   a.x.y + b.x.y,   a.x.z + b.x.z,   a.x.w + b.x.w,
		a.y.x + b.y.x,   a.y.y + b.y.y,   a.y.z + b.y.z,   a.y.w + b.y.w,
		a.z.x + b.z.x,   a.z.y + b.z.y,   a.z.z + b.z.z,   a.z.w + b.z.w,
		a.w.x + b.w.x,   a.w.y + b.w.y,   a.w.z + b.w.z,   a.w.w + b.w.w
	}};
}

mat4 sub4(mat4 a, mat4 b)
{
	return (mat4) {{
		a.x.x - b.x.x,   a.x.y - b.x.y,   a.x.z - b.x.z,   a.x.w - b.x.w,
		a.y.x - b.y.x,   a.y.y - b.y.y,   a.y.z - b.y.z,   a.y.w - b.y.w,
		a.z.x - b.z.x,   a.z.y - b.z.y,   a.z.z - b.z.z,   a.z.w - b.z.w,
		a.w.x - b.w.x,   a.w.y - b.w.y,   a.w.z - b.w.z,   a.w.w - b.w.w
	}};
}
/*
 *  0  1  2  3
 *  4  5  6  7
 *  8  9 10 11
 * 12 13 14 15
 *
 */

mat4 mul4(mat4 a, mat4 b)
{
	static const int size = 4;
	mat4 c = {0};
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
			for (int i = 0; i < size; i++)
				c.m[x][y] += a.m[x][i] * b.m[i][y];
	return c;
}

mat4 div4(mat4 a, mat4 b)
{
}

void print_mat4(mat4 m)
{
	for (int i = 0; i < 4; i++) {
		printf("%2.2f %2.2f %2.2f %2.2f\n",
				m.m[0][i],
				m.m[1][i],
				m.m[2][i],
				m.m[3][i]);
	}
}
