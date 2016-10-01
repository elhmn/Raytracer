/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 00:36:23 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 11:56:19 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "put_var.h"
#include "check_errors.h"
#include "normal_computation.h"
#include "transform.h"

t_pos		cylinder_normal(t_obj *o, t_pos r, t_pos p)
{
	t_pos				n;
	t_pos				c;

	(void)r;
	n = get_pos(0, 0, 0);
	p = transform(o->o, o->sp, p, o->rot);
	c = get_pos(0, p.y, 0);
	n = pos_normalize(pos_vector(c, p));
	return (n);
}
