#include "gmath.h"

t_coord		parallel_projection(t_vec4 *vertex)
{
	t_coord		coord;

	coord.x = (int)(vertex->arr[0]);
	coord.y = (int)(vertex->arr[1]);
	return (coord);
}
