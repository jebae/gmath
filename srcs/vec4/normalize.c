#include "gmath.h"

t_vec4		normalize(t_vec4 *v)
{
	float	norm;
	t_vec4	res;

	norm = vec_norm(v);
	res.arr[0] = v->arr[0] / norm;
	res.arr[1] = v->arr[1] / norm;
	res.arr[2] = v->arr[2] / norm;
	return (res);
}
