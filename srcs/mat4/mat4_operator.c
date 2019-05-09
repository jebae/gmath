#include "gmath.h"

t_vec4		mat_mul_vec(t_mat4 *m, t_vec4 *v)
{
	int		r;
	int		c;
	t_vec4	res;

	r = 0;
	while (r < 4)
	{
		res.arr[r] = 0;
		c = 0;
		while (c < 4)
		{
			res.arr[r] += m->arr[r][c] * v->arr[c];
			c++;
		}
		r++;
	}
	return (res);
}

t_mat4		mat_mul_mat(t_mat4 *m1, t_mat4 *m2)
{
	int		r1;
	int		r2;
	int		c;
	t_mat4	res;

	r1 = 0;
	while (r1 < 4)
	{
		r2 = 0;
		res.arr[r1][r2] = 0;
		while (r2 < 4)
		{
			c = 0;
			while (c < 4)
			{
				res.arr[r1][r2] += m1->arr[r1][c] * m2->arr[c][r2];
				c++;
			}
			r2++;
		}
		r1++;
	}
	return (res);
}
