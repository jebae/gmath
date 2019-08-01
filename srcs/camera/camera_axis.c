/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:58:42 by jebae             #+#    #+#             */
/*   Updated: 2019/08/01 16:58:43 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

void		set_camera_z_axis(t_camera *cam, t_vec4 *focus)
{
	cam->z_axis = vec_sub_vec(focus, &(cam->pos));
	cam->z_axis = normalize(&(cam->z_axis));
}

void		set_camera_x_axis(t_camera *cam)
{
	static t_vec4	z_w = (t_vec4){{0.0f, 0.0f, 1.0f, 1.0f}};
	t_quaternion	q;
	t_quaternion	q_i;

	if (ABS(vec_dot_vec(&(cam->z_axis), &z_w)) >= 1.0f)
		return ;
	cam->x_axis = vec_cross_vec(&(cam->z_axis), &z_w);
	q = rotate_q(&(cam->z_axis), cam->roll);
	q_i = inverse_q(&q);
	cam->x_axis = rotate(&q, &(cam->x_axis), &q_i);
	cam->x_axis = normalize(&(cam->x_axis));
}

void		set_camera_y_axis(t_camera *cam)
{
	cam->y_axis = vec_cross_vec(&(cam->z_axis), &(cam->x_axis));
	cam->y_axis = normalize(&(cam->y_axis));
}

void		set_camera_axis(t_camera *cam, t_vec4 *focus)
{
	set_camera_z_axis(cam, focus);
	set_camera_x_axis(cam);
	set_camera_y_axis(cam);
}
