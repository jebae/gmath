/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:25:21 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:25:22 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_quaternion	rotate_q(t_vec4 *n, float theta)
{
	t_quaternion		q;
	float				s;

	s = sinf(theta * 0.5);
	q.x = s * n->arr[0];
	q.y = s * n->arr[1];
	q.z = s * n->arr[2];
	q.w = cosf(theta * 0.5);
	return (q);
}

t_vec4			rotate(t_quaternion *q, t_vec4 *v, t_quaternion *q_i)
{
	t_quaternion	res;

	v->arr[3] = 0.0f;
	res = q_mul_q(q, (t_quaternion *)v);
	res = q_mul_q(&res, q_i);
	v->arr[3] = 1.0f;
	res.w = 1.0f;
	return (*((t_vec4 *)&res));
}
