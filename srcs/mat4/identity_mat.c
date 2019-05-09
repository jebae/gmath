#include "gmath.h"

t_mat4		identity_mat()
{
	int		r;
	int		c;
	t_mat4	mat;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (r == c)
				mat.arr[r][c] = 1;
			else
				mat.arr[r][c] = 0;
			c++;
		}
		r++;
	}
	return (mat);
}
