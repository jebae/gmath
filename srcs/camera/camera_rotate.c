#include "gmath.h"

t_quaternion	camera_rotate_q(t_vec4 *camera, t_vec4 *focus)
{
	static t_vec4		z_w = (t_vec4){0, 0, 1, 1};
	t_vec4				z_c;
	t_vec4				rot_axis;
	t_quaternion		q1;
	t_quaternion		q2;

	z_c = vec_plus_vec(focus, &scalar_mul_vec(-1, camera));
	rot_axis = vec_cross_vec(&z_w, &z_c);
	q = rotate_q(&rot_axis, -1 * acos(z_c.arr[2] / (1 + vec_norm(&z_c))));
	return (q);
}

/* z and x seperately make it!! */
