#ifndef GRAPHIC_MATH_H
# define GRAPHIC_MATH_H

# include <math.h>
# include "libft.h"
#include <stdio.h>

typedef struct					s_quaternion
{
	float						x;
	float						y;
	float						z;
	float						w;
}								t_quaternion;

typedef struct					s_rotation_helper
{
	float						cr;
	float						sr;
	float						cp;
	float						sp;
	float						cy;
	float						sy;
}								t_rotation_helper;

typedef struct					s_vec4
{
	float						arr[4];
}								t_vec4;

typedef struct					s_mat4
{
	float						arr[4][4];
}								t_mat4;

t_mat4			identity_mat();

t_vec4			mat_mul_vec(t_mat4 *m, t_vec4 *v);

t_mat4			mat_mul_mat(t_mat4 *m1, t_mat4 *m2);

t_mat4			scale_mat(float scale);

t_mat4			translate_mat(float x, float y, float z);

t_vec4			zero_vec();

float			vec_dot_vec(t_vec4 *v1, t_vec4 *v2);

t_vec4			scalar_mul_vec(float scalar, t_vec4 *v);

t_vec4			vec_plus_vec(t_vec4 *v1, t_vec4 *v2);

t_vec4			vec_cross_vec(t_vec4 *v1, t_vec4 *v2);

float			vec_norm(t_vec4 *v);

t_quaternion	q_mul_q(t_quaternion *q1, t_quaternion *q2);

t_quaternion	rotate_q(t_vec4 *n, float theta);

t_quaternion	inverse_q(t_quaternion *q);

t_vec4			rotate(t_quaternion *q, t_vec4 *v, t_quaternion *q_i);

t_vec4			normalize(t_vec4 *v);

t_mat4			camera_coord_mat(t_vec4 *camera, t_vec4 *focus, float roll);

#endif
