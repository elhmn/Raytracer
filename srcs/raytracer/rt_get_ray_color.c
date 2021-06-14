/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_ray_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 20:09:44 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 20:37:32 by bmbarga          ###   ########.fr       */
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

static t_pos	get_point(t_pos ro, t_pos r, double d)
{
	pos_mult_to_number(&r, d);
	pos_add_to_pos(&ro, r);
	return (ro);
}

int				get_distance(t_ray *r, t_obj *obj, t_rt *rt)
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

static void		rt_get_ray_color_aux(t_rt *rt, t_obj *tmp, t_ray *r, double d)
{
	if (!tmp)
		return ;
	r->col = tmp->col;
	if (tmp && tmp->material)
		rt_get_color(r, tmp, rt,
				get_point(rt->camera->sp.o, r->rd, d));
}

void			rt_get_ray_color(t_ray *r, t_list *o, t_rt *rt)
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
	rt_get_ray_color_aux(rt, tmp, r, d);
}
