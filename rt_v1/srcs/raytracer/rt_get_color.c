/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 20:06:39 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/18 19:52:17 by bmbarga          ###   ########.fr       */
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

static t_base	get_base(t_pos p, t_pos l, t_pos n, t_pos cam)
{
	t_base	b;
	
	b.o = p;
	b.i = l;
	b.j = n;
	b.k = cam;
	return (b);
}

static void		get_light(t_rt *rt, t_s_color *s_col, t_light *light,
						t_obj *o, t_pos p, t_ray *ray)
{
	t_ray		r;
	t_base		b;

	b.o = (o->normal) ? o->normal(o, ray->rd, p) : get_pos(0, 0, 0);
	b.i = pos_vector(p, light->sp.o);
	r.rd = pos_normalize(b.i);
	r.pos = light->sp.o;
	r.ro = p;
	if (enlightened(rt, o, r))
	{
		if (rt->diffuse)
			*s_col = add_s_color(*s_col,
					diffuse_light(light, o, b.i, b.o));
		if (rt->specular)
			*s_col = add_s_color(*s_col,
					specular_light(light, o, get_base(p, b.i, b.o, rt->camera->sp.o)));
	}
	else
		*s_col = sub_s_color(*s_col,
				get_s_color(s_col->r / SHADOW_COEF,
					s_col->g / SHADOW_COEF, s_col->b / SHADOW_COEF));
}

/*
** base b is used to store normal and light direction
*/

void			rt_get_color(t_ray *ray, t_obj *o, t_rt *rt, t_pos p)
{
	t_list		*list;
	t_light		*light;
	t_s_color	s_col;


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
			if (o->normal)
				get_light(rt, &s_col, light, o, p, ray);
		}
		list = list->next;
	}
	ray->col = get_reshaped_color(s_color_to_color(s_col));
}
