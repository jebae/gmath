#include "gmath.h"

static t_vec4	camera_x_axis(t_vec4 *z_w, t_vec4 *z_c, float roll)
{
	t_quaternion	q;
	t_quaternion	q_i;
	t_vec4			x_c;

	x_c = vec_cross_vec(z_c, z_w);
	q = rotate_q(z_c, roll);
	q_i = inverse_q(&q);
	x_c = rotate(&q, &x_c, &q_i);
	return (x_c);
}

t_mat4			camera_coord_mat(t_vec4 *camera, t_vec4 *focus, float roll)
{
	static t_vec4		z_w = (t_vec4){0, 0, 1, 1};
	t_mat4				mat;
	t_vec4				x_c;
	t_vec4				y_c;
	t_vec4				z_c;

	mat = identity_mat();
	z_c = scalar_mul_vec(-1, camera);
	z_c = vec_plus_vec(focus, &z_c);
	z_c = normalize(&z_c);
	x_c = camera_x_axis(&z_w, &z_c, roll);
	x_c = normalize(&x_c);
	y_c = vec_cross_vec(&z_c, &x_c);
	y_c = normalize(&y_c);
	ft_memcpy((void *)(mat.arr[0]), (const void *)&x_c, sizeof(float) * 3);
	ft_memcpy((void *)(mat.arr[1]), (const void *)&y_c, sizeof(float) * 3);
	ft_memcpy((void *)(mat.arr[2]), (const void *)&z_c, sizeof(float) * 3);
	mat.arr[0][3] = vec_dot_vec(&x_c, camera) * (-1);
	mat.arr[1][3] = vec_dot_vec(&y_c, camera) * (-1);
	mat.arr[2][3] = vec_dot_vec(&z_c, camera) * (-1);
	mat.arr[3][3] = 1;
	return (mat);
}
