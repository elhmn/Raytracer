/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:01:49 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 17:54:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "object.h"
#include "put_var.h"
#include <stdlib.h>

static t_obj		*create_obj(t_objTok *t)
{
	t_obj		*tmp;

	tmp = NULL;
	if (t)
	{
		if (!ft_strcmp(t->type, T_PLANE))
		{
			/*
			** if (t->axis)
			** 	t->normal = convert_axis();
			*/
			tmp = newPlane(t->pos, t->normal, get_color(t->col.x, t->col.y, t->col.z));
		}
		else if (!ft_strcmp(t->type, T_SPHERE))
			tmp = newSphere(t->pos, t->radius, get_color(t->col.x, t->col.y, t->col.z));
		else if (!ft_strcmp(t->type, T_CYLINDER))
			tmp = newCylinder(t->pos, t->radius, t->height, get_color(t->col.x, t->col.y, t->col.z));
		else if (!ft_strcmp(t->type, T_CONE))
			tmp = newCone(t->pos, get_pos(t->top, t->height, t->angle), get_color(t->col.x, t->col.y, t->col.z));
		else
			check_errors(NUL, "object", "wrong format");
		if (!tmp)
			check_errors(MALLOC, "tmp", "load_objs");
	}
	return (tmp);
}

static t_obj		*load_obj(t_objTok *t, int id)
{
	t_obj		*o;

	o = NULL;
	if (t)
	{
		o = create_obj(t);
		o->id = id;
		o->name = t->name;
		if (o->type != PLANE && o->type != SPHERE)
			rot_object(o, t->rot);
		else if (o->type == PLANE)
			rot_plane(o, t->rot);
		add_pos_to_pos(l->sp.o, t->trans);
		if (!(o->material = new_material(NULL,
						CONV_100(LIMIT_100(t->mat.x)),
						CONV_100(LIMIT_100(t->mat.y)),
						CONV_100(LIMIT_100(t->mat.z)))))
			check_errors(MALLOC, "o->material", "load_objs.c");
	}
	return (o);
}

static t_list		*add_new_obj(t_objTok *t, int id)
{
	t_list		*l;

	l = NULL;
	if (!(l = ft_lstnew(NULL, 0)))
		check_errors(MALLOC, "l", "load_objs.c");
	l->content = (void*)load_obj(t, id);
	if (!l->content)
		check_errors(MALLOC, "l->content", "load_objs.c");
	return (l);
}

void		load_objs(t_list **list, t_objTok **t)
{
	int			i;
	t_list		*tmp;

	i = -1;
	tmp = NULL;
	if (list && t)
	{
		while (*t)
		{
			if (++i == 0)
			{
				*list = add_new_obj(*t, i);
				put_obj((t_obj*)(*list)->content); //Debug
			}
			else
			{
				tmp = add_new_obj(*t, i);
				ft_lstadd_end(list, tmp);
				put_obj((t_obj*)tmp->content); //Debug
				tmp = NULL;
			}
			t++;
		}
	}
	ft_putendl("load objs"); //Debug
}
