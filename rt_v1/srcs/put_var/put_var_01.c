/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var_01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:04:14 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:47:30 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "put_var.h"
#include "check_errors.h"
#include <stdio.h>
#include <stdlib.h>

void	put_ray(t_ray ray)
{
	ft_putstr("pos : ");
	put_pos(ray.pos);
	ft_putstr("col :");
	ft_putnbr(ray.col.color);
	ft_putendl("");
}

void	put_data_sphere(t_data_sphere *data)
{
	t_data_sphere *sp;

	sp = (t_data_sphere*)data;
	if (sp)
	{
		ft_putstr("radius =  [");
		ft_putdbl(sp->radius);
		ft_putendl("]");
	}
}

void	put_data_plane(t_data_plane *data)
{
	t_data_plane	*pl;

	pl = (t_data_plane*)data;
	if (pl)
	{
		ft_putstr("v_normal -> ");
		put_pos(pl->v_normal);
	}
}


void	put_type(int type)
{
	if (type == SPHERE)
		ft_putstr("Sphere");
	else if (type == PLANE)
		ft_putstr("Plane");
	else
		ft_putstr("Unknown");
}

/*
** put Data for each tyo->sp** clean that code to avoid if forest
*/

void	put_obj(void *obj)
{
	t_obj		*o;

	o = (t_obj*)obj;
	if (o)
	{
		ft_putstr("Obj : ");
		put_type(o->type);
		ft_putendl(" {\n");
		ft_putstr("pos -> ");
		put_pos(o->sp.o);
		ft_putstr("base \n{\n");
		put_base(o->sp);
		ft_putstr("rotation -> ");
		put_pos(o->rot);
		ft_putstr("}\n");
		if (o->material)
			put_material(*(o->material));
		if (o->type == SPHERE)
			put_data_sphere(o->data);
		if (o->type == PLANE)
			put_data_plane(o->data);
		if (o->type == CYLINDER)
			put_data_cylinder(o->data);
		if (o->type == CONE)
			put_data_cone(o->data);
		ft_putendl("\n}\n");
	}
}
