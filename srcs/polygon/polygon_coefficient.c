#include "gmath.h"

t_polygon_coefficient		polygon_coefficient(t_polygon *polygon)
{
	t_polygon_coefficient		co;
	t_vec4						v;
	t_vec4						b1;
	t_vec4						b2;

	v = scalar_mul_vec(-1, &(polygon->vertices[0]));
	b1 = vec_plus_vec(&(polygon->vertices[1]), &v);
	b2 = vec_plus_vec(&(polygon->vertices[2]), &v);
	v = vec_cross_vec(&b1, &b2);
	ft_memcpy((void *)&co, (const void *)&v, sizeof(float) * 3);
	co.d = -1 * vec_dot_vec(&v, &(polygon->vertices[0]));
	return (co);
}
