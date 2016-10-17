/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:27:26 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 11:55:02 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "put_var.h"
#include "check_errors.h"
#include "libft.h"
#include <math.h>

/*
** plane collision function
*/

static double		is_collision(t_ray *ray, t_data_plane *data,
								t_obj *obj, t_rt *rt)
{
	double		ret;
	double		denom;
	t_pos		n;
	t_pos		po;

	ret = -1;
	if (ray && data && obj && rt)
	{
		n = pos_normalize(data->v_normal);
		po = obj->sp.o;
		denom = pos_dot_product(n, ray->rd);
		if (denom > 1e-6 && denom)
			ret = (pos_dot_product(n, po)
					- pos_dot_product(n, ray->ro)) / (denom);
	}
	return (ret);
}

double				plane_collision(t_ray *ray, void *data,
									t_obj *obj, t_rt *rt)
{
	double				d;
	t_data_plane		*dat;

	d = -1;
	dat = (t_data_plane*)data;
	if (ray && dat && rt && obj)
		d = is_collision(ray, dat, obj, rt);
	return (d);
}
