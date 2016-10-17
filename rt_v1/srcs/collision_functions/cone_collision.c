/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:32:32 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:32:33 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "put_var.h"
#include "check_errors.h"
#include "libft.h"
#include "transform.h"
#include <math.h>

static double		get_dist(double a, double b, double delta)
{
	double		ret;
	double		r_delta;
	double		d1;
	double		d2;

	r_delta = sqrt(delta);
	d1 = (-b - r_delta) / (2. * a);
	d2 = (-b + r_delta) / (2. * a);
	ret = d1;
	if (ret > d2)
		ret = d2;
	return (ret);
}

static double		find_collision(t_pos ro, t_pos rd,
							double h, double ang)
{
	double	a;
	double	b;
	double	c;
	double	e;
	double	delta;

	e = tan(RAD(ang / 2.));
	a = pow(rd.x, 2) + pow(rd.z, 2) - pow(rd.y, 2) * e;
	b = 2. * (rd.x * ro.x + rd.z * ro.z - e * ro.y * rd.y
		+ e * rd.y * h);
	c = pow(ro.x, 2) + pow(ro.z, 2) - e * (pow(ro.y, 2)
			- 2. * ro.y * h + pow(h, 2));
	delta = pow(b, 2) - (4. * a * c);
	if (delta < 0)
		return (-1.);
	else if (delta == 0)
		return (-b / (2. * a));
	else
		return (get_dist(a, b, delta));
	return (-1);
}

static double		is_collision(t_ray *ray, t_data_cone *data,
					t_obj *obj, t_rt *rt)
{
	double			ret;
	double			e;
	t_pos			rd;
	t_pos			rf;
	t_pos			ro;

	ret = -1;
	if (rt && ray && rt->space)
	{
		ro = ray->ro;
		rf = ray->pos;
		ro = transform(obj->o, obj->sp, ro, obj->rot);
		rf = transform(obj->o, obj->sp, rf, obj->rot);
		rd = pos_vector(ro, rf);
		rd = pos_normalize(rd);
		ret = find_collision(ro, rd, data->top, data->ang);
		e = tan(RAD(data->ang / 2.));
		ret = get_cone_limit(ro, rd, ret,
				get_pos(data->top, data->lim, e));
	}
	return (ret);
}

double				cone_collision(t_ray *ray, void *data,
									t_obj *obj, t_rt *rt)
{
	double			d;
	t_data_cone		*dat;

	d = -1;
	dat = (t_data_cone*)data;
	if (ray && rt && dat && obj)
		d = is_collision(ray, dat, obj, rt);
	return (d);
}
