/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_polygon.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:25:07 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:25:07 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_polygon		new_polygon(size_t v_count, int line_color, int fill_color)
{
	t_polygon	polygon;

	polygon.v_count = v_count;
	polygon.line_color = line_color;
	polygon.fill_color = fill_color;
	polygon.vertices = (t_vec4 *)ft_memalloc(sizeof(t_vec4) * v_count);
	return (polygon);
}
