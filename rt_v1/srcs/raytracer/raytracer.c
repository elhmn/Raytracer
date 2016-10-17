/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:08:15 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 20:10:22 by bmbarga          ###   ########.fr       */
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
		if (obj->if_collision)
			d = obj->if_collision(r, obj->data, obj, rt);
	}
	return (d);
}


static t_pos		get_point(t_pos ro, t_pos r, double d)
{
	pos_mult_to_number(&r, d);
	pos_add_to_pos(&ro, r);
	return (ro);
}


static void	rt_set_ray_pos(int incx, int incy, t_ray *r, t_rt *rt)
{
	int		px;
	int		py;
	t_pos	t;
	t_base	b;

	if (!rt || !r)
		check_errors(NUL, "raytracer.c", "rt && r");
	b.o = rt->camera->sp.o;
	b.i = pos_normalize(rt->camera->sp.i);
	b.j = pos_normalize(rt->camera->sp.j);
	b.k = pos_normalize(rt->camera->sp.k);
	px = rt->screen->pixel_width;
	py = rt->screen->pixel_height;
	pos_mult_to_number(&(b.k), rt->camera->dist);
	pos_add_to_pos(&(b.o), b.k);
	t = b.i;
	pos_mult_to_number(&t, - ((px * (rt->screen->res_x + 1)) / 2.) + incx * px);
	pos_add_to_pos(&(b.o), t);
	t = b.j;
	pos_mult_to_number(&t, ((py * (rt->screen->res_y - 1)) / 2.) - incy * px);
	pos_add_to_pos(&b.o, t);
	set_pos(&(r->pos), b.o.x, b.o.y, b.o.z);
	r->ro = rt->camera->sp.o;
	r->rd = pos_normalize(pos_vector(r->ro, r->pos));
}

void		raytracer(t_rt *rt)
{
	int		i;
	int		j;
	t_ray	**r;
	t_list	*o;

	rt_check_error(rt);
	i = -1;
	r = rt->ray;
	o = rt->objs;
	set_ray_array_zero(r, rt->screen);
	while (++i < rt->screen->res_y)
	{
		j = -1;
		while (++j < rt->screen->res_x)
		{
			if (r && r[i] && r[i] + j)
			{
				rt_set_ray_pos(j, i, r[i] + j, rt);
				rt_get_ray_color(r[i] + j, o, rt);
			}
		}
	}
}
