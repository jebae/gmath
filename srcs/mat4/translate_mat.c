#include "gmath.h"

t_mat4		translate_mat(float x, float y, float z)
{
	t_mat4	m;

	m = identity_mat();
	m.arr[0][3] = x;
	m.arr[1][3] = y;
	m.arr[2][3] = z;
	return (m);
}
