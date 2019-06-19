/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:33:04 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:33:04 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_complex		complex_coord_zoom(t_complex_coord_zoom_args *args)
{
	t_complex		entry_point;
	double			scale;

	scale = 1.0 / (args->zoom);
	entry_point.r = args->entry_point->r * scale;
	entry_point.i = args->entry_point->i * scale;
	entry_point.r += (1 - scale) * args->focus->r;
	entry_point.i += (1 - scale) * args->focus->i;
	return (entry_point);
}
