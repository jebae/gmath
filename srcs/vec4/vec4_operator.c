#include "gmath.h"

float		vec_dot_vec(t_vec4 *v1, t_vec4 *v2)
{
	int		i;
	float	res;

	i = 0;
	res = 0;
	while (i < 3)
	{
		res += v1->arr[i] * v2->arr[i];
		i++;
	}
	return (res);
}

t_vec4		scalar_mul_vec(float scalar, t_vec4 *v)
{
	int		i;
	t_vec4	res;

	i = 0;
	while (i < 3)
	{
		res.arr[i] = v->arr[i] * scalar;
		i++;
	}
	res.arr[i] = v->arr[i];
	return (res);
}
