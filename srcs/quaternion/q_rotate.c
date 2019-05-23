#include "gmath.h"

t_quaternion	rotate_q(t_vec4 *n, float theta)
{
	t_quaternion		q;
	float				s;

	s = sin(theta * 0.5);
	q.x = s * n->arr[0];
	q.y = s * n->arr[1];
	q.z = s * n->arr[2];
	q.w = cos(theta * 0.5);
	return (q);
}

t_vec4			rotate(t_quaternion *q, t_vec4 *v, t_quaternion *q_i)
{
	t_quaternion	res;

	v->arr[3] = 0;
	res = q_mul_q(q, (t_quaternion *)v);
	res = q_mul_q(&res, q_i);
	v->arr[3] = 1;
	res.w = 1;
	return (*((t_vec4 *)&res));
}
