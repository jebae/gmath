#include "gmath.h"

void	rotate_camera(t_camera *cam, t_vec4 *axis, t_vec4 *axis_foot, float theta)
{
	t_vec4			po;
	t_vec4			pc;
	t_quaternion	q;
	t_quaternion	q_i;

	po = scalar_mul_vec(-1, axis_foot);
	pc = vec_plus_vec(&(cam->pos), &po);
	q = rotate_q(axis, theta);
	q_i = inverse_q(&q);
	pc = rotate(&q, &pc, &q_i);
	cam->pos = vec_plus_vec(&pc, axis_foot);
}