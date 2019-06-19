/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:33:13 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:33:13 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gmath.h"

t_complex		cmplx_plus_cmplx(t_complex *c1, t_complex *c2)
{
	t_complex		res;

	res.r = c1->r + c2->r;
	res.i = c1->i + c2->i;
	return (res);
}

t_complex		conjugate(t_complex *c)
{
	t_complex		conj;

	conj.r = c->r;
	conj.i = -1 * c->i;
	return (conj);
}

t_complex		cmplx_mul_cmplx(t_complex *c1, t_complex *c2)
{
	t_complex	res;

	res.r = c1->r * c2->r - c1->i * c2->i;
	res.i = c1->r * c2->i + c1->i * c2->r;
	return (res);
}
