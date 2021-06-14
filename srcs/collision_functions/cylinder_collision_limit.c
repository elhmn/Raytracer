/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision_limit.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:18:17 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:22:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "put_var.h"
#include "check_errors.h"
#include "libft.h"
#include "transform.h"
#include <math.h>

static double		get_limit_aux(t_pos ro, t_pos rd, t_pos data)
{
	t_pos	rd_tmp;
	t_pos	ro_tmp;
	t_pos	tmp;
	double	d;

	d = (((data.y) - ro.y) / rd.y);
	rd_tmp = rd;
	ro_tmp = ro;
	pos_mult_to_number(&rd_tmp, d);
	pos_add_to_pos(&ro_tmp, rd_tmp);
	tmp = pos_vector(ro_tmp, get_pos(0, data.y, 0));
	if (pos_norme(tmp) <= data.x)
		return (d);
	return (MAX_DBL);
}

double				get_cylinder_limit(t_pos ro,
					t_pos rd, double ret, t_pos data)
{
	double			d1;
	double			d2;

	if (ret >= 0 && data.y > 0 &&
		!(((ro.y / ret) * -1.) <= rd.y
			&& (data.y / ret - (ro.y / ret)) >= rd.y))
	{
		d1 = get_limit_aux(ro, rd, get_pos(data.x, data.y, 0));
		d2 = get_limit_aux(ro, rd, get_pos(data.x, 0, 0));
		if (d1 > d2)
			d1 = d2;
		ret = d1;
	}
	return (ret);
}
