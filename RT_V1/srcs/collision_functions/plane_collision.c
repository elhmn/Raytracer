/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:27:26 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 08:49:50 by bmbarga          ###   ########.fr       */
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

static double		is_collision(t_ray *ray, t_dataPlane *data,
								t_obj *obj, t_rt *rt)
{
	double		ret;
	double		denom;
	double		enume;
	t_pos		n;
	t_pos		rd;
	t_pos		ro;
	t_pos		po;
	t_camera	*cam;

	ret = -1;
	if (ray && data && obj && rt && rt->camera)
	{
		cam = rt->camera;
		n = pos_normalize(data->v_normal);
		rd = pos_normalize(pos_vector(cam->sp.o, ray->pos));
		ro = cam->sp.o;
		po = obj->sp.o;
		denom = pos_dot_product(n, rd);
		if (denom > 1e-6 && denom)
		{
			enume = pos_dot_product(n, po) - pos_dot_product(n, ro);
			ret = (enume) / (denom);
		}
	}
	return (ret);
}

double				plane_collision(t_ray *ray, void *data,
									t_obj *obj, t_rt *rt)
{
	double			d;
	t_dataPlane		*dat;

	d = -1;
	dat = (t_dataPlane*)data;
	if (ray && dat && rt && obj)
		d = is_collision(ray, dat, obj, rt);
	return (d);
}
