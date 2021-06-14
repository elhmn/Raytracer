/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:28:05 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:28:05 by bmbarga          ###   ########.fr       */
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

static double		find_collision(t_pos ro, t_pos rd, double r)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	ret;

	ret = -1;
	a = pow(rd.x, 2) + pow(rd.z, 2);
	b = 2. * (rd.x * ro.x + rd.z * ro.z);
	c = pow(ro.x, 2) + pow(ro.z, 2) - pow(r, 2);
	delta = pow(b, 2) - (4. * a * c);
	if (delta < 0)
		ret = -1.;
	else if (delta == 0)
		ret = -b / (2. * a);
	else
		ret = get_dist(a, b, delta);
	return (ret);
}

static double		is_collision(t_ray *ray, t_data_cylinder *data,
					t_obj *obj, t_rt *rt)
{
	double			ret;
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
		ret = find_collision(ro, rd, data->radius);
		ret = get_cylinder_limit(ro, rd, ret,
				get_pos(data->radius, data->height, 0));
	}
	return (ret);
}

/*
** Bug the cylinder object seems to be parralel to the camera
*/

double				cylinder_collision(t_ray *ray, void *data,
									t_obj *obj, t_rt *rt)
{
	double			d;
	t_data_cylinder	*dat;

	d = -1;
	dat = (t_data_cylinder*)data;
	if (ray && rt && dat && obj)
		d = is_collision(ray, dat, obj, rt);
	return (d);
}
