/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:27:23 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/25 16:33:28 by bmbarga          ###   ########.fr       */
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

	ret = -1;
	rDelta = sqrt(delta);
	d1 = (-b - rDelta) / (2. * a);
	d2 = (-b + rDelta) / (2. * a);

	ret = d1;
	if (d1 > d2)
		ret = d2;
	return (ret);
}

static double		find_collision(t_pos ro, t_pos rd, double r)
{
	double	ret;
	double	a;
	double	b;
	double	c;
	double	delta;

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

static double		is_collision(t_ray *ray, t_dataCylinder *data, t_obj *obj, t_rt *rt)
{
	double			ret;
	double			h;
	t_camera		*cam;
	t_pos			rd;
	t_pos			rf;
	t_pos			ro;

	ret = -1;
	cam = rt->camera;
	(void)obj;
	if (cam && rt->space)
	{
		h  = data->height;
		ro = cam->sp.o;
		rf = ray->pos;
		ro = transform(obj->o, obj->sp, ro, obj->rot);
		rf = transform(obj->o, obj->sp, rf, obj->rot);
		rd = pos_vector(ro, rf);
		rd = pos_normalize(rd);
		ret = find_collision(ro, rd, data->radius);
		if (ret >= 0 && h >= 0 &&
			!(((ro.y / ret) * -1.) <= rd.y
				&& (h / ret - (ro.y / ret)) >= rd.y))
		return (-1);
//		if (ret >= 0 && !(pow(ro.x + rd.x * ret, 2) + pow(ro.z + rd.z * ret, 2)
//				<= pow(data->radius, 2)))
//		return (-1);
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
