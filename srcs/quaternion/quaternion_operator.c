#include "gmath.h"

t_quaternion		q_mul_q(t_quaternion *q1, t_quaternion *q2)
{
	t_quaternion	q;

	q.w = q1->w * q2->w - vec_dot_vec((t_vec4 *)q1, (t_vec4 *)q2);
	q.x = q1->w * q2->x + q2->w * q1->x +\
		  q1->y * q2->z - q1->z * q2->y;
	q.y = q1->w * q2->y + q2->w * q1->y +\
		  q1->z * q2->x - q1->x * q2->z;
	q.z = q1->w * q2->z + q2->w * q1->z +\
		  q1->x * q2->y - q1->y * q2->x;
	return (q);
}
