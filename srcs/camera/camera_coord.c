/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:24:48 by jebae             #+#    #+#             */
/*   Updated: 2019/07/29 14:46:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_mat4			camera_basis_mat(t_camera *cam)
{
	static t_vec4		z_w = (t_vec4){{0, 0, 1, 1}};
	t_mat4				mat;
	t_vec4				x_c;
	t_vec4				y_c;
	t_vec4				z_c;

	mat = identity_mat();
	z_c = camera_z_axis(cam);
	x_c = camera_x_axis(&z_w, &z_c, cam->roll);
	y_c = camera_y_axis(&z_c, &x_c);
	x_c = scalar_mul_vec(cam->zoom, &x_c);
	y_c = scalar_mul_vec(cam->zoom, &y_c);
	ft_memcpy((void *)(mat.arr[0]), (const void *)&x_c, sizeof(float) * 3);
	ft_memcpy((void *)(mat.arr[1]), (const void *)&y_c, sizeof(float) * 3);
	ft_memcpy((void *)(mat.arr[2]), (const void *)&z_c, sizeof(float) * 3);
	return (mat_transpose(&mat));
}

t_mat4			world_to_cam_coord_mat(t_camera *cam)
{
	t_mat4		mat;
	t_vec4		x_c;
	t_vec4		y_c;
	t_vec4		z_c;

	mat = camera_basis_mat(cam);
	mat = mat_transpose(&mat);
	ft_memcpy((void *)&x_c, (void *)(mat.arr[0]), sizeof(float) * 3);
	ft_memcpy((void *)&y_c, (void *)(mat.arr[1]), sizeof(float) * 3);
	ft_memcpy((void *)&z_c, (void *)(mat.arr[2]), sizeof(float) * 3);
	mat.arr[0][3] = vec_dot_vec(&x_c, &(cam->pos)) * (-1.0f);
	mat.arr[1][3] = vec_dot_vec(&y_c, &(cam->pos)) * (-1.0f);
	mat.arr[2][3] = vec_dot_vec(&z_c, &(cam->pos)) * (-1.0f);
	mat.arr[3][3] = 1;
	return (mat);
}
