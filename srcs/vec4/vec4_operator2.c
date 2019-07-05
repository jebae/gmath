#include "gmath.h"

t_vec4		vec_sub_vec(t_vec4 *v1, t_vec4 *v2)
{
	int		i;
	t_vec4	res;

	i = 0;
	while (i < 3)
	{
		res.arr[i] = v1->arr[i] - v2->arr[i];
		i++;
	}
	res.arr[i] = 1;
	return (res);
}