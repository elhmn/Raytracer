/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:27:23 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/27 09:57:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "put_var.h"
#include "check_errors.h"
#include "libft.h"
#include "transform.h"
#include <math.h>

static double		getDist(double a, double b, double delta)
{
	double		ret;
	double		rDelta;
	double		d1;
	double		d2;

	rDelta = sqrt(delta);
	d1 = (-b - rDelta) / (2. * a);
	d2 = (-b + rDelta) / (2. * a);
	ret = d1;
	if (ret > d2)
		ret = d2;
	return (ret);
}

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
		ret = getDist(a, b, delta);
	return (ret);
}

static double		get_limit(t_pos ro, t_pos rd, double ret, t_pos data)
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

static double		is_collision(t_ray *ray, t_dataCylinder *data,
					t_obj *obj, t_rt *rt)
{
	double			ret;
	t_camera		*cam;
	t_pos			rd;
	t_pos			rf;
	t_pos			ro;

	ret = -1;
	cam = rt->camera;
	if (cam && rt->space)
	{
		ro = cam->sp.o;
		rf = ray->pos;
		ro = transform(obj->o, obj->sp, ro, obj->rot);
		rf = transform(obj->o, obj->sp, rf, obj->rot);
		rd = pos_vector(ro, rf);
		rd = pos_normalize(rd);
		ret = find_collision(ro, rd, data->radius);
		ret = get_limit(ro, rd, ret,
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
	t_dataCylinder	*dat;

	d = -1;
	dat = (t_dataCylinder*)data;
	if (ray && rt && dat && obj)
		d = is_collision(ray, dat, obj, rt);
	return (d);
}
