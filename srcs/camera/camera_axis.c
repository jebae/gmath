#include "gmath.h"

t_vec4		camera_z_axis(t_camera *cam)
{
	t_vec4		z;

	z = vec_sub_vec(&(cam->focus), &(cam->pos));
	z = normalize(&z);
	return (z);
}

t_vec4		camera_x_axis(t_vec4 *z_w, t_vec4 *z_c, float roll)
{
	t_quaternion	q;
	t_quaternion	q_i;
	t_vec4			x;

	x = vec_cross_vec(z_c, z_w);
	q = rotate_q(z_c, roll);
	q_i = inverse_q(&q);
	x = rotate(&q, &x, &q_i);
	x = normalize(&x);
	return (x);
}

t_vec4		camera_y_axis(t_vec4 *z, t_vec4 *x)
{
	t_vec4		y;

	y = vec_cross_vec(z, x);
	y = normalize(&y);
	return (y);
}