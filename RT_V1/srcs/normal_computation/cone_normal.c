/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 11:14:39 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 11:56:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "put_var.h"
#include "check_errors.h"
#include "normal_computation.h"
#include "transform.h"
#include "math.h"

t_pos		cone_normal(t_obj *o, t_pos r, t_pos p)
{
	t_pos			n;
	t_pos			a;
	t_pos			c;
	t_dataCone		*data;

	(void)n;
	(void)o;
	(void)r;
	(void)p;
	(void)data;
	
	n = get_pos(0, 0, 0);
	data = (t_dataCone*)o->data;
	if (data)
	{
		p = transform(o->o, o->sp, p, o->rot);
		c = get_pos(0, data->top, 0);
		a = get_pos(0, 1,  0);
		if (p.y < data->top)
			a = get_pos(0, -1,  0);
		n = p;
		pos_mult_to_number(&a, pos_norme(pos_vector(c, p))
							/ cos(RAD(data->ang / 2)));
		pos_add_to_pos(&c, a);
		pos_mult_to_number(&c, -1);
		pos_add_to_pos(&n, c);
		n = pos_normalize(n);
	}
	return (n);
}
