/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:24:51 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:24:52 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

void	rotate_camera(
	t_camera *cam,
	t_vec4 *axis,
	t_vec4 *axis_foot,
	float theta
)
{
	t_vec4			pc;
	t_quaternion	q;
	t_quaternion	q_i;

	pc = vec_sub_vec(&(cam->pos), axis_foot);
	q = rotate_q(axis, theta);
	q_i = inverse_q(&q);
	pc = rotate(&q, &pc, &q_i);
	cam->pos = vec_plus_vec(&pc, axis_foot);
}
