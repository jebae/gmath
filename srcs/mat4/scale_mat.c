#include "gmath.h"

t_mat4		scale_mat(float scale)
{
	int		r;
	t_mat4	m;

	m = identity_mat();
	r = 0;
	while (r < 3)
	{
		m.arr[r][r] = scale;
		r++;
	}
	return (m);
}
