/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:27:29 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 11:58:23 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "put_var.h"
#include "check_errors.h"
#include "libft.h"
#include <math.h>

/*
** sphere collision function
*/

static double		delta(t_pos e)
{
	return (pow(e.y, 2) - (4. * e.x * e.z));
}

static double		get_dist(t_pos e, double delta)
{
	double	d1;
	double	d2;
	double	q;
	double	rd;
	double	ret;

	q = (2. * e.x);
	rd = sqrt(delta);
	d1 = (-1. * e.y - rd) / q;
	d2 = (-1. * e.y + rd) / q;
	ret = d1;
	if (d1 > d2)
		ret = d2;
	return (ret);
}

static double		is_collision(t_ray *ray, t_data_sphere *data,
								t_obj *obj, t_rt *rt)
{
	double			ret;
	t_pos			u;
	t_pos			v;
	t_pos			e;
	double			tmp;

	ret = -1.;
	if (rt && ray && data)
	{
		u = ray->rd;
		v = pos_vector(obj->sp.o, ray->ro);
		e.x = pos_dot_product(u, u);
		e.y = 2. * pos_dot_product(u, v);
		e.z = pos_dot_product(v, v) - pow(data->radius, 2);
		if ((tmp = delta(e)) < 0.)
			ret = -1.;
		else if (tmp == 0.)
			ret = (-1. * e.y) / (2. * e.x);
		else
			ret = get_dist(e, tmp);
	}
	return (ret);
}

double				sphere_collision(t_ray *ray, void *data,
										t_obj *obj, t_rt *rt)
{
	double			d;
	t_data_sphere	*dat;

	d = -1;
	dat = (t_data_sphere*)data;
	if (ray && dat && rt && obj)
		d = is_collision(ray, dat, obj, rt);
	return (d);
}
