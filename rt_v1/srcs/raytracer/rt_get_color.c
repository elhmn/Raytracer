/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 20:06:39 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 20:09:32 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "check_errors.h"
#include "libft.h"
#include "rt.h"
#include "put_var.h"
#include "light.h"
#include "material.h"
#include "rt_color.h"


void			rt_get_color(t_ray *ray, t_obj *o, t_rt *rt, t_pos p)
{
	t_list		*list;
	t_light		*light;
	t_s_color	s_col;
	t_ray		r;
	t_pos		n;
	t_pos		l;
	t_base		base;

	if (!rt || !ray || !o)
		check_errors(NUL, "raytracer.c", "rt || ray || o");
	list = rt->lights;
	s_col = get_s_color(o->s_col.r * o->material->ka,
			o->s_col.g * o->material->ka, o->s_col.b * o->material->ka);
	while (rt->render && list)
	{
		light = (t_light*)list->content;
		if (light)
		{
			l = pos_vector(p, light->sp.o);
			r.rd = pos_normalize(l);
			r.pos = light->sp.o;
			r.ro = p;
			if (o->normal)
			{
				if (enlightened(rt, o, r))
				{
					n = o->normal(o, ray->rd, p);
					if (rt->diffuse)
						s_col = add_s_color(s_col,
								diffuse_light(light, o, l, n));
					if (rt->specular)
					{
						base.o = p;
						base.i = l;
						base.j = n;
						base.k = rt->camera->sp.o;
						s_col = add_s_color(s_col, specular_light(light, o, base));
					}
				}
				else
					s_col = sub_s_color(s_col,
							get_s_color(s_col.r / SHADOW_COEF, s_col.g / SHADOW_COEF, s_col.b / SHADOW_COEF));
			}
		}
		list = list->next;
	}
	ray->col = get_reshaped_color(s_color_to_color(s_col));
}
