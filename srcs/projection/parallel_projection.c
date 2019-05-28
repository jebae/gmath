/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_projection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:25:14 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:25:15 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_vec4		parallel_projection(t_vec4 *vertex)
{
	return (*vertex);
}

float		cal_parallel_proj_z(int x, int y, t_polygon_coefficient *co)
{
	return (-1 * (co->a * x + co->b * y + co->d) / co->c);
}
