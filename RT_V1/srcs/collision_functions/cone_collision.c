/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 00:20:48 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 14:08:32 by bmbarga          ###   ########.fr       */
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

static double		get_limit(t_pos ro, t_pos rd, double ret, t_pos data)
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

static double		find_collision(t_pos ro, t_pos rd,
							double h, double ang)
{
	double	a;
	double	b;
	double	c;
	double	e;
	double	delta;
	double	ret;

	ret = -1;
	e = tan(RAD(ang / 2.));
	a = pow(rd.x, 2) + pow(rd.z, 2) - pow(rd.y, 2) * e;
	b = 2. * (rd.x * ro.x + rd.z * ro.z - e * ro.y * rd.y
		+ e * rd.y * h);
	c = pow(ro.x, 2) + pow(ro.z, 2) - e * (pow(ro.y, 2) - 2. * ro.y * h + pow(h, 2));
	delta = pow(b, 2) - (4. * a * c);
	if (delta < 0)
		ret = -1.;
	else if (delta == 0)
		ret = -b / (2. * a);
	else
		ret = getDist(a, b, delta);
	return (ret);
}

static double		is_collision(t_ray *ray, t_dataCone *data,
					t_obj *obj, t_rt *rt)
{
	double			ret;
	double			e;
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
		ret = find_collision(ro, rd, data->top, data->ang);
		e = tan(RAD(data->ang / 2.));
		ret = get_limit(ro, rd, ret,
				get_pos(data->top, data->lim, e));
	}
	return (ret);
}

double				cone_collision(t_ray *ray, void *data,
									t_obj *obj, t_rt *rt)
{
	double			d;
	t_dataCone		*dat;

	d = -1;
	dat = (t_dataCone*)data;
	if (ray && rt && dat && obj)
		d = is_collision(ray, dat, obj, rt);
	return (d);
}
