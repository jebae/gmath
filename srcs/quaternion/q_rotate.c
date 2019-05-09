#include "gmath.h"

t_quaternion	get_q(float roll, float pitch, float yaw)
{
	t_quaternion		q;
	t_rotation_helper	rh;

	rh.cr = cos(roll * 0.5);
	rh.cp = cos(pitch * 0.5);
	rh.cy = cos(yaw * 0.5);
	rh.sr = sin(roll * 0.5);
	rh.sp = sin(pitch * 0.5);
	rh.sy = sin(yaw * 0.5);
	q.w = rh.cr * rh.cp * rh.cy + rh.sr * rh.sp * rh.sy;
	q.x = rh.sr * rh.cp * rh.cy - rh.cr * rh.sp * rh.sy;
	q.y = rh.cr * rh.sp * rh.cy + rh.sr * rh.cp * rh.sy;
	q.z = rh.cr * rh.cp * rh.sy - rh.sr * rh.sp * rh.cy;
	return (q);
}

t_quaternion	get_q_inverse(t_quaternion *q)
{
	t_quaternion	q_i;

	q_i.w = q->w;
	q_i.x = -1 * q->x;
	q_i.y = -1 * q->y;
	q_i.z = -1 * q->z;
	return (q_i);
}

t_vec4			q_rotate(t_quaternion *q,\
		t_vec4 *v, t_quaternion *q_i)
{
	t_quaternion	res;

	v->q.w = 0;
	res = q_mul_q(q, (t_quaternion *)v);
	res = q_mul_q(&res, q_i);
	v->q.w = 1;
	res.w = 1;
	return (*((t_vec4 *)&res));
}
