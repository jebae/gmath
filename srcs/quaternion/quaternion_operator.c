/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:25:24 by jebae             #+#    #+#             */
/*   Updated: 2019/05/28 15:25:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_quaternion		q_mul_q(t_quaternion *q1, t_quaternion *q2)
{
	t_quaternion	q;

	q.w = q1->w * q2->w - vec_dot_vec((t_vec4 *)q1, (t_vec4 *)q2);
	q.x = q1->w * q2->x + q2->w * q1->x +\
		q1->y * q2->z - q1->z * q2->y;
	q.y = q1->w * q2->y + q2->w * q1->y +\
		q1->z * q2->x - q1->x * q2->z;
	q.z = q1->w * q2->z + q2->w * q1->z +\
		q1->x * q2->y - q1->y * q2->x;
	return (q);
}

t_quaternion		inverse_q(t_quaternion *q)
{
	t_quaternion	q_i;

	q_i.w = q->w;
	q_i.x = -1 * q->x;
	q_i.y = -1 * q->y;
	q_i.z = -1 * q->z;
	return (q_i);
}
