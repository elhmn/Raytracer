/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:01:35 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 15:31:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static void		load_light(t_light *l, t_lightTok *t, int id)
{
	if (l)
	{
		l->type = 0;
		l->id = id;
		t->Id = get_pos(CONV_100(LIMIT_100(t->Id.x)),
				CONV_100(LIMIT_100(t->Id.y)),
				CONV_100(LIMIT_100(t->Id.z)));

		t->Is = get_pos(CONV_100(LIMIT_100(t->Is.x)),
				CONV_100(LIMIT_100(t->Is.y)),
				CONV_100(LIMIT_100(t->Is.z)));

		l->I = get_inty(getI(t->Id.x, t->Id.y, t->Id.z), getI(t->Is.x, t->Is.y, t->Is.z));
		l->sp.o = t->pos;
		l->volume = NULL;
	}
}

static t_list		*add_new_light(t_lightTok *t, int id)
{
	t_list		*l;

	l = NULL;
	if (!(l = ft_lstnew(NULL, 0)))
		check_errors(MALLOC, "l", "load_lights.c");
	l->content = new_omniLight(get_pos(0, 0, 0), get_inty(getI(0, 0, 0), getI(0, 0, 0)));
	load_light((t_light*)l->content, t, id);
	if (!l->content)
		check_errors(MALLOC, "l->content", "load_lights.c");
	return (l);
}

void			load_lights(t_list **list, t_lightTok **t)
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
				*list = add_new_light(*t, i);
				put_light((t_light*)(*list)->content); //Debug
			}
			else
			{
				tmp = add_new_light(*t, i);
				ft_lstadd_end(list, tmp);
				put_light((t_light*)tmp->content); //Debug
				tmp = NULL;
			}
			t++;
		}
	}
	ft_putendl("load lights"); //Debug
}
