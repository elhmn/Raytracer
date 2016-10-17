/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:18:38 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 18:27:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static void			init_obj_tok(t_obj_tok *t)
{
	if (t)
	{
		t->name = O_NAME;
		t->axis = NULL;
		t->type = T_SPHERE;
		t->pos = get_pos(0, 0, 0);
		t->rot = get_pos(0, 0, 0);
		t->trans = get_pos(0, 0, 0);
		t->mat = get_pos(20, 30, 50);
		t->col = get_pos(50, 50, 50);
		t->normal = get_pos(0, -1, 0);
		t->radius = 100;
		t->height = -1;
		t->angle = 15;
		t->top = 100;
	}
}

static void			new_objs_tok(t_scene_tok *s_tok, int len)
{
	int				i;

	if (s_tok)
	{
		if (!(s_tok->objs_tok =
				(t_obj_tok**)malloc(sizeof(t_obj_tok*) * (len + 1))))
			check_errors(MALLOC, "s_tok->objs_tok", "set_obj_tok");
		s_tok->objs_tok[len] = NULL;
		i = -1;
		while (++i < len)
		{
			if (!(s_tok->objs_tok[i] =
					(t_obj_tok*)malloc(sizeof(t_obj_tok))))
				check_errors(MALLOC, "s_tok->objs_tok[i]", "set_obj_tok");
			init_obj_tok(s_tok->objs_tok[i]);
		}
	}
}

static void			set_obj_tok_var(t_obj_tok *t, char *s)
{
	char		**tab;

	tab = NULL;
	if (s && t)
	{
		tab = ft_strsplit(s, SEP_3);
		get_label_tok(&t->type, tab, A_TYPE);
		get_label_tok(&t->name, tab, A_NAME);
		get_label_tok(&t->axis, tab, A_AXIS);
		get_pos_tok(&t->normal, tab, A_NORMAL);
		get_pos_tok(&t->pos, tab, A_POSITION);
		get_pos_tok(&t->rot, tab, A_ROTATION);
		get_pos_tok(&t->trans, tab, A_TRANSLATION);
		get_pos_tok(&t->col, tab, A_COLOR);
		get_pos_tok(&t->mat, tab, A_MATERIAL);
		get_dbl_tok(&t->radius, tab, A_RADIUS);
		get_dbl_tok(&t->height, tab, A_HEIGHT);
		get_dbl_tok(&t->angle, tab, A_ANGLE);
		get_dbl_tok(&t->top, tab, A_TOP);
		free_tab(&tab);
	}
}

static void			set_objs_tok_tab(t_obj_tok **t,
						char **tab, int *index, int len)
{
	int			i;
	char		**tmp;

	i = 0;
	tmp = NULL;
	if (t && tab)
	{
		while (*t)
		{
			if (i < len)
			{
				tmp = ft_strsplit(tab[index[i]], SEP_2);
				if (tmp && tmp[0] && tmp[1])
				{
					set_obj_tok_var(*t, tmp[1]);
				}
				else
					check_errors(NUL, "obj bad format", tab[index[i]]);
				free_tab(&tmp);
				i++;
			}
			t++;
		}
	}
}

void				set_obj_tok(t_scene_tok *s_tok, char **tab)
{
	int		len;
	int		*tmp;

	len = obj_number(tab, N_OBJECT);
	if (!len)
		s_tok->objs_tok = NULL;
	if (!(tmp = (int*)malloc(sizeof(int) * (len))))
		check_errors(MALLOC, "tmp", "set_objs_tok.c");
	get_index(tab, tmp, N_OBJECT);
	new_objs_tok(s_tok, len);
	set_objs_tok_tab((s_tok->objs_tok), tab, tmp, len);
	free(tmp);
}
