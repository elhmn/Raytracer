/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 20:06:39 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/20 17:52:27 by bmbarga          ###   ########.fr       */
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
						t_base b)
{
	t_ray		r;

	r.rd = pos_normalize(b.i);
	r.pos = light->sp.o;
	r.ro = b.j;
	if (!rt->shadow || enlightened(rt, rt->cur_obj, r))
	{
		if (rt->diffuse)
			*s_col = add_s_color(*s_col,
					diffuse_light(light, rt->cur_obj, b.i, b.o));
		if (rt->specular)
			*s_col = add_s_color(*s_col,
					specular_light(light, rt->cur_obj,
						get_base(b.j, b.i, b.o, rt->camera->sp.o)));
	}
	else
		*s_col = sub_s_color(*s_col,
				get_s_color(s_col->r / SHADOW_COEF,
					s_col->g / SHADOW_COEF, s_col->b / SHADOW_COEF));
}

/*
** base b is used to store normal and light direction and hit point
*/

void			rt_get_color(t_ray *ray, t_obj *o, t_rt *rt, t_pos p)
{
	t_list		*list;
	t_light		*light;
	t_s_color	s_col;
	t_base		b;

	if (!rt || !ray || !o)
		check_errors(NUL, "raytracer.c", "rt || ray || o");
	list = rt->lights;
	s_col = get_s_color(o->s_col.r * o->material->ka,
			o->s_col.g * o->material->ka, o->s_col.b * o->material->ka);
	while (rt->render && list)
	{
		if ((light = (t_light*)list->content))
			if (o->normal)
			{
				b.j = p;
				b.o = o->normal(o, ray->rd, b.j);
				b.i = pos_vector(b.j, light->sp.o);
				rt->cur_obj = o;
				get_light(rt, &s_col, light, b);
			}
		list = list->next;
	}
	ray->col = get_reshaped_color(s_color_to_color(s_col));
}
