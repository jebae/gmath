#include "gmath.h"

t_vec4		zero_vec()
{
	int		i;
	t_vec4	v;

	i = 0;
	v.arr[3] = 1;
	while (i < 3)
	{
		v.arr[i] = 0;
		i++;
	}
	return (v);
}
