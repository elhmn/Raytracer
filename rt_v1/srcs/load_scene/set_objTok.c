/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objTok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:34:06 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 13:48:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static void				init_objTok(t_objTok *t)
{
	if (t)
	{
		t->name = NULL;
		t->axis = NULL;
		t->type = NULL;
		t->pos = get_pos(0, 0, 0);
		t->rot = get_pos(0, 0, 0);
		t->mat = get_pos(0, 0, 0);
		t->col = get_pos(0, 0, 0);
		t->normal = get_pos(0, -1, 0);
		t->radius = 0;
		t->height = 0;
		t->angle = 0;
	}	
}

static void				new_objsTok(t_sceneTok *sTok, int len)
{
	int				i;

	if (sTok)
	{
		if (!(sTok->objsTok =
				(t_objTok**)malloc(sizeof(t_objTok*) * (len + 1))))
			check_errors(MALLOC, "sTok->objsTok", "set_objTok");
		sTok->objsTok[len] = NULL;
		i = -1;
		while (++i < len)
		{
			if (!(sTok->objsTok[i] =
					(t_objTok*)malloc(sizeof(t_objTok))))	
				check_errors(MALLOC, "sTok->objsTok[i]", "set_objTok");
			init_objTok(sTok->objsTok[i]);
		}
	}
}

static void				set_objTok_var(t_objTok *t, char *s)
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
		get_pos_tok(&t->col, tab, A_COLOR);
		get_pos_tok(&t->mat, tab, A_MATERIAL);
		get_dbl_tok(&t->radius, tab, A_RADIUS);
		get_dbl_tok(&t->height, tab, A_HEIGHT);
		get_dbl_tok(&t->angle, tab, A_ANGLE);
	}
	free_tab(tab);
}

static void				set_objsTok_tab(t_objTok **t, char **tab, int *index, int len)
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
					set_objTok_var(*t, tmp[1]);
				else
					check_errors(NUL, "obj bad format", tab[index[i]]);
				i++;
			}
			t++;
		}
	}
	free_tab(tmp);
}


void				set_objTok(t_sceneTok *sTok, char **tab)
{
	int		len;
	int		*tmp;

	len = obj_number(tab, N_OBJECT);
	if (!len)
		check_errors(NUL, "no obj defined", "");
	if (!(tmp = (int*)malloc(sizeof(int) * (len))))
		check_errors(MALLOC, "tmp", "set_objsTok.c");
	get_index(tab, tmp, N_OBJECT);
	new_objsTok(sTok, len);
	set_objsTok_tab((sTok->objsTok), tab, tmp, len);
	free(tmp);
}
