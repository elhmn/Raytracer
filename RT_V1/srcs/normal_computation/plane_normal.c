/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:20:52 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 20:47:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "check_errors.h"
#include "normal_computation.h"

t_pos		plane_normal(t_obj *o, t_pos r, t_pos p)
{
	t_pos			n;
	t_dataPlane		*dat;

	(void)n;
	(void)o;
	(void)r;
	(void)p;
	n = get_pos(0, 0, 0);
	dat = (t_dataPlane*)o->data;
	if (dat)
		n = dat->v_normal;
	return (n);
}
