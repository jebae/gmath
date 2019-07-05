/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon_coefficient.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:25:11 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:25:11 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_polygon_coefficient		polygon_coefficient(t_polygon *polygon)
{
	t_polygon_coefficient		co;
	t_vec4						v;
	t_vec4						b1;
	t_vec4						b2;

	b1 = vec_sub_vec(&(polygon->vertices[1]), &(polygon->vertices[0]));
	b2 = vec_sub_vec(&(polygon->vertices[2]), &(polygon->vertices[0]));
	v = vec_cross_vec(&b1, &b2);
	ft_memcpy((void *)&co, (const void *)&v, sizeof(float) * 3);
	co.d = -1 * vec_dot_vec(&v, &(polygon->vertices[0]));
	return (co);
}
