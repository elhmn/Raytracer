/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_objs_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:45:26 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 18:45:27 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "rt.h"
#include "load_scene.h"
#include "init.h"

void		put_obj_tok(t_obj_tok *t)
{
	if (t)
	{
		ft_putendl("object :\n{\n");
		ft_putstr("type = ");
		ft_putendl(t->type);
		ft_putstr("name = ");
		ft_putendl(t->name);
		ft_putstr("axis = ");
		ft_putendl(t->axis);
		ft_putstr("pos -> ");
		put_pos(t->pos);
		ft_putstr("normal -> ");
		put_pos(t->normal);
		ft_putstr("rot -> ");
		put_pos(t->rot);
		ft_putstr("trans -> ");
		put_pos(t->trans);
		ft_putstr("mat -> ");
		put_pos(t->mat);
		put_var_dbl("radius", t->radius);
		put_var_dbl("height", t->height);
		put_var_dbl("angle", t->angle);
		put_var_dbl("top", t->top);
		ft_putendl("}\n");
	}
}

void		put_objs_tok(t_obj_tok **t)
{
	if (!t)
		return ;
	while (*t)
		put_obj_tok(*t++);
}
