/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:25:31 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:25:32 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

float		vec_dot_vec(t_vec4 *v1, t_vec4 *v2)
{
	int		i;
	float	res;

	i = 0;
	res = 0;
	while (i < 3)
	{
		res += v1->arr[i] * v2->arr[i];
		i++;
	}
	return (res);
}

t_vec4		scalar_mul_vec(float scalar, t_vec4 *v)
{
	int		i;
	t_vec4	res;

	i = 0;
	while (i < 3)
	{
		res.arr[i] = v->arr[i] * scalar;
		i++;
	}
	res.arr[i] = v->arr[i];
	return (res);
}

t_vec4		vec_plus_vec(t_vec4 *v1, t_vec4 *v2)
{
	int		i;
	t_vec4	res;

	i = 0;
	while (i < 3)
	{
		res.arr[i] = v1->arr[i] + v2->arr[i];
		i++;
	}
	res.arr[i] = 1;
	return (res);
}

t_vec4		vec_cross_vec(t_vec4 *v1, t_vec4 *v2)
{
	t_vec4	res;

	res.arr[0] = v1->arr[1] * v2->arr[2] - v1->arr[2] * v2->arr[1];
	res.arr[1] = v1->arr[2] * v2->arr[0] - v1->arr[0] * v2->arr[2];
	res.arr[2] = v1->arr[0] * v2->arr[1] - v1->arr[1] * v2->arr[0];
	res.arr[3] = 1;
	return (res);
}

float		vec_norm(t_vec4 *v)
{
	return (sqrtf(pow(v->arr[0], 2) + pow(v->arr[1], 2) + pow(v->arr[2], 2)));
}
