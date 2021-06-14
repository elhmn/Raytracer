/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_collision_limit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:11:41 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:17:42 by bmbarga          ###   ########.fr       */
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

/*
** data -> (x = top, y = lim, z = e = tan(RAD(ang / 2)))
*/

double				get_cone_limit(t_pos ro, t_pos rd, double ret, t_pos data)
{
	double			d1;
	double			d2;
	double			s;
	double			h;
	double			e;

	s = data.x;
	h = data.y;
	e = data.z;
	if (ret > 0 && h > 0 &&
		!((s - (h)) < ro.y + rd.y * ret
			&& (s + (h)) > ro.y + rd.y * ret))
	{
		d1 = get_limit_aux(ro, rd, get_pos((s + h) * e, s + h, 0));
		d2 = get_limit_aux(ro, rd, get_pos((s + h) * e, s - h, 0));
		if (d1 > d2)
			d1 = d2;
		ret = d1;
	}
	return (ret);
}
