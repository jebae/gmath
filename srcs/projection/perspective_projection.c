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

float       cal_perspective_proj_z(int x, int y, t_polygon_coefficient *co)
{
    float   z;

    z = -1 * (co->d / (co->a * (float)x + co->b * (float)y + co->c));
    return (z);
}
