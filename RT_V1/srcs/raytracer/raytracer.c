/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:08:15 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 18:18:34 by bmbarga          ###   ########.fr       */
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

static void	rt_check_error(t_rt *rt)
{
	if (!rt)
		check_errors(NUL, "raytracer.c", "rt");
	if (!rt->screen)
		check_errors(NUL, "raytracer.c", "rt->screen");
	if (!rt->objs)
		check_errors(NUL, "raytracer.c", "rt->objs");
	if (!rt->ray)
		check_errors(NUL, "raytracer.c", "rt->ray");
}

int			get_distance(t_ray *r, t_obj *obj, t_rt *rt)
{
	int		d;

	d = -1;
	if (obj != NULL)
	{
		if (obj->ifCollision)
			d = obj->ifCollision(r, obj->data, obj, rt);
	}
	return (d);
}

static void	rt_get_color(t_ray *ray, t_obj *o, t_rt *rt, t_pos p)
{
	t_list		*list;
	t_light		*light;
	t_sColor	sCol;
	t_pos		n;
	t_pos		l;
	t_base		base;

	if (!rt || !ray || !o)
		check_errors(NUL, "raytracer.c", "rt || ray || o");
	list = rt->lights;
	sCol = get_sColor(o->sCol.r * o->material->ka,
			o->sCol.g * o->material->ka, o->sCol.b * o->material->ka);
	while (rt->render && list)
	{
		light = (t_light*)list->content;
		if (light)
		{
			l = pos_vector(p, light->sp.o);
			if (o->normal)
			{
				if (enlightened(rt, o, p, l, light->sp.o))
				{
					n = o->normal(o, ray->rd, p);
					if (rt->diffuse)
						sCol = add_sColor(sCol,
								diffuse_light(light, o, l, n));
					if (rt->specular)
					{
						base.o = p;
						base.i = l;
						base.j = n;
						base.k = rt->camera->sp.o;
						sCol = add_sColor(sCol, specular_light(light, o, base));
					}
				}
				else
					sCol = sub_sColor(sCol,
							get_sColor(sCol.r / 5., sCol.g / 5., sCol.b / 5.));
			}
		}
		list = list->next;
	}
	ray->col = get_reshaped_color(sColor_to_color(sCol));
}

static t_pos		get_point(t_pos ro, t_pos r, double d)
{
	pos_mult_to_number(&r, d);
	pos_add_to_pos(&ro, r);
	return (ro);
}

static void	rt_get_ray_color(t_ray *r, t_list *o, t_rt *rt)
{
	t_list	*list;
	t_obj	*obj;
	t_obj	*tmp;
	double	ret;
	double	d;

	list = o;
	d = MAX_DBL;
	if (!rt || !r)
		check_errors(NUL, "raytracer.c", "rt && r");
	tmp = NULL;
	while (list != NULL)
	{
		obj = (t_obj*)list->content;
		if (obj && d > (ret = get_distance(r, obj, rt))
			&& ret >= 0)
		{
			tmp = obj;
			d = ret;
		}
		list = list->next;
	}
	if (tmp)
	{
		r->col = tmp->col;
		if (tmp && tmp->material)
			rt_get_color(r, tmp, rt,
					get_point(rt->camera->sp.o, r->rd, d));
	}

}

static void	rt_set_ray_pos(int incX, int incY, t_ray *r, t_rt *rt)
{
	int		pX;
	int		pY;
	t_pos	t;
	t_pos	c;
	t_pos	u;
	t_pos	v;
	t_pos	w;

	if (!rt || !r)
		check_errors(NUL, "raytracer.c", "rt && r");
	c = rt->camera->sp.o;
	u = pos_normalize(rt->camera->sp.i);
	v = pos_normalize(rt->camera->sp.j);
	w = pos_normalize(rt->camera->sp.k);
	pX = rt->screen->pixelWidth;
	pY = rt->screen->pixelHeight;
	pos_mult_to_number(&w, rt->camera->dist);
	pos_add_to_pos(&c, w);
	t = u;
	pos_mult_to_number(&t, - ((pX * (rt->screen->resX + 1)) / 2.) + incX * pX);
	pos_add_to_pos(&c, t);
	t = v;
	pos_mult_to_number(&t, ((pY * (rt->screen->resY - 1)) / 2.) - incY * pY);
	pos_add_to_pos(&c, t);
	set_pos(&(r->pos), c.x, c.y, c.z);
	r->ro = rt->camera->sp.o;
	r->rd = pos_normalize(pos_vector(r->ro, r->pos));
}

void		raytracer(t_rt *rt)
{
	int		i;
	int		j;
	t_ray	**r;
	t_list	*o;

	ft_putendl("raytracer IN"); //debug
	rt_check_error(rt);
	i = -1;
	r = rt->ray;
	o = rt->objs;
	set_ray_array_zero(r, rt->screen);
	while (++i < rt->screen->resY)
	{
		j = -1;
		while (++j < rt->screen->resX)
		{
			if (r && r[i] && r[i] + j)
			{
				rt_set_ray_pos(j, i, r[i] + j, rt);
				rt_get_ray_color(r[i] + j, o, rt);
			}
		}
	}
	ft_putendl("raytracer OUT"); //debug
}
