#include "gmath.h"

t_vec4		perspective_projection(t_vec4 *vertex)
{
	t_vec4		proj;

	// handle when z is 0
	proj.arr[0] = vertex->arr[0] / vertex->arr[2];
	proj.arr[1] = vertex->arr[1] / vertex->arr[2];
	proj.arr[2] = 1;
	proj.arr[3] = 1;
	return (proj);
}
