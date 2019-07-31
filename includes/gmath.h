/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gmath.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:24:42 by jebae             #+#    #+#             */
/*   Updated: 2019/07/29 14:45:49 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GMATH_H
# define GMATH_H

# include <math.h>
# include "libft.h"
# define GMATH_TRUE			1
# define GMATH_FALSE		0
# define DEGREE_1			(M_PI / 180.0)
# define FLOAT_0			1e-6f

typedef struct			s_quaternion
{
	float				x;
	float				y;
	float				z;
	float				w;
}						t_quaternion;

typedef struct			s_vec4
{
	float				arr[4];
}						t_vec4;

typedef struct			s_mat4
{
	float				arr[4][4];
}						t_mat4;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_polygon
{
	size_t				v_count;
	struct s_vec4		*vertices;
	int					line_color;
	int					fill_color;
}						t_polygon;

typedef struct			s_polygon_coefficient
{
	float				a;
	float				b;
	float				c;
	float				d;
}						t_polygon_coefficient;

typedef struct			s_camera
{
	t_vec4				pos;
	t_vec4				x_axis;
	t_vec4				y_axis;
	t_vec4				z_axis;
	float				zoom;
	float				roll;
}						t_camera;

typedef struct			s_complex_coord_zoom_args
{
	double				width;
	double				height;
	double				zoom;
	t_complex			*entry_point;
	t_complex			*focus;
}						t_complex_coord_zoom_args;

/*
** matrix
*/
t_mat4					identity_mat(void);
t_vec4					mat_mul_vec(t_mat4 *m, t_vec4 *v);
t_mat4					mat_mul_mat(t_mat4 *m1, t_mat4 *m2);
t_mat4					scale_mat(float scale);
t_mat4					translate_mat(float x, float y, float z);
t_mat4					mat_transpose(t_mat4 *mat);
float					mat3_det(t_mat4 *mat);
t_vec4					mat3_cramer_solution(
	t_mat4 *a,
	t_vec4 *b,
	int *solution_found
);

/*
** vector
*/
t_vec4					zero_vec(void);
float					vec_dot_vec(t_vec4 *v1, t_vec4 *v2);
t_vec4					scalar_mul_vec(float scalar, t_vec4 *v);
t_vec4					vec_plus_vec(t_vec4 *v1, t_vec4 *v2);
t_vec4					vec_cross_vec(t_vec4 *v1, t_vec4 *v2);
float					vec_norm(t_vec4 *v);
t_vec4					normalize(t_vec4 *v);
t_vec4					vec_sub_vec(t_vec4 *v1, t_vec4 *v2);

/*
** complex
*/
t_complex				cmplx_plus_cmplx(t_complex *c1, t_complex *c2);
t_complex				conjugate(t_complex *c);
t_complex				cmplx_mul_cmplx(t_complex *c1, t_complex *c2);
t_complex				complex_coord_zoom(t_complex_coord_zoom_args *args);

/*
** quaternion
*/
t_quaternion			q_mul_q(t_quaternion *q1, t_quaternion *q2);
t_quaternion			rotate_q(t_vec4 *n, float theta);
t_quaternion			inverse_q(t_quaternion *q);
t_vec4					rotate(t_quaternion *q, t_vec4 *v, t_quaternion *q_i);

/*
** polygon
*/
t_polygon				new_polygon(size_t v_count, int line_color,\
	int fill_color);
t_polygon_coefficient	polygon_coefficient(t_polygon *polygon);

/*
** camera
*/
void					set_camera_z_axis(t_camera *cam, t_vec4 *focus);
void					set_camera_y_axis(t_camera *cam);
void					set_camera_x_axis(t_camera *cam);
void					set_camera_axis(t_camera *cam, t_vec4 *focus);
t_mat4					camera_basis_mat(t_camera *cam);
t_mat4					world_to_cam_coord_mat(t_camera *cam);
void					rotate_camera(
	t_camera *cam,
	t_vec4 *axis,
	t_vec4 *axis_foot,
	float theta
);

/*
** projection
*/
t_vec4					parallel_projection(t_vec4 *vertex);
float					cal_parallel_proj_z(
	int x,
	int y,
	t_polygon_coefficient *co
);
t_vec4					perspective_projection(t_vec4 *vertex);
float					cal_perspective_proj_z(
	int x,
	int y,
	t_polygon_coefficient *co
);

#endif
