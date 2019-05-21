#include "gmath.h"

t_vec4		parallel_projection(t_vec4 *vertex)
{
	return (*vertex);
}

float       cal_parallel_proj_z(int x, int y, t_polygon_coefficient *co)
{
    return (-1 * (co->a * x + co->b * y + co->d) / co->c);
}
