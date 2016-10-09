/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:01:35 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 23:03:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static void		load_light(t_light *l, t_light_tok *t, int id)
{
	if (l && t)
	{
		l->type = 0;
		l->id = id;
		t->id = get_pos(CONV_100(LIMIT_100(t->id.x)),
				CONV_100(LIMIT_100(t->id.y)),
				CONV_100(LIMIT_100(t->id.z)));

		t->is = get_pos(CONV_100(LIMIT_100(t->is.x)),
				CONV_100(LIMIT_100(t->is.y)),
				CONV_100(LIMIT_100(t->is.z)));

		l->inty = get_inty(get_i(t->id.x, t->id.y, t->id.z), get_i(t->is.x, t->is.y, t->is.z));
		l->sp.o = t->pos;
		pos_add_to_pos(&(l->sp.o), t->trans);
		l->volume = NULL;
	}
}

static t_list		*add_new_light(t_light_tok *t, int id)
{
	t_list		*l;

	l = NULL;
	if (!(l = ft_lstnew(NULL, 0)))
		check_errors(MALLOC, "l", "load_lights.c");
	l->content = new_omni_light(get_pos(0, 0, 0), get_inty(get_i(0, 0, 0), get_i(0, 0, 0)));
	load_light((t_light*)l->content, t, id);
	if (!l->content)
		check_errors(MALLOC, "l->content", "load_lights.c");
	return (l);
}

void			load_lights(t_list **list, t_light_tok **t)
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
