/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lightTok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 03:10:01 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/05 10:15:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static void				init_lightTok(t_lightTok *t)
{
	if (t)
	{
		t->type = T_OMNI;
		t->pos = get_pos(0, 400, 0);
		t->trans = get_pos(0, 0, 0);
		t->rot = get_pos(0, 0, 0);
		t->Id = get_pos(60, 60, 60);
		t->Is = get_pos(40, 40, 40);
	}
}

void			get_index(char **tab, int *t, char *type)
{
	int		i;
	char	*s;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			if ((s = find_type(tab[i], type, SEP_2)))
			{
				*t++ = i;
				free(s);
			}
		}
	}
}

int					obj_number(char **tab, char *type)
{
	int		len;
	char	*s;

	len = 0;
	if (tab)
	{
		while (*tab)
		{
			if (((s = find_type(*tab++, type, SEP_2))))
			{
				len++;
				free(s);
			}
		}
	}
	return (len);
}

void				new_lightsTok(t_sceneTok *sTok, int len)
{
	int				i;

	if (sTok)
	{
		if (!(sTok->lightsTok =
				(t_lightTok**)malloc(sizeof(t_lightTok*) * (len + 1))))
			check_errors(MALLOC, "sTok->lightsTok", "set_lightTok");
		sTok->lightsTok[len] = NULL;
		i = -1;
		while (++i < len)
		{
			if (!(sTok->lightsTok[i] =
					(t_lightTok*)malloc(sizeof(t_lightTok))))
				check_errors(MALLOC, "sTok->lightsTok[i]", "set_lightTok");
			init_lightTok(sTok->lightsTok[i]);
		}
	}
}

void				set_lightTok_var(t_lightTok *t, char *s)
{
	char		**tab;

	tab = NULL;
	if (s && t)
	{
		tab = ft_strsplit(s, SEP_3);
		get_label_tok(&t->type, tab, A_TYPE);
		get_pos_tok(&t->pos, tab, A_POSITION);
		get_pos_tok(&t->trans, tab, A_TRANSLATION);
		get_pos_tok(&t->Id, tab, A_ID);
		get_pos_tok(&t->Is, tab, A_IS);
		free_tab(&tab);
	}
}

void				set_lightsTok_tab(t_lightTok **t, char **tab, int *index, int len)
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
					set_lightTok_var(*t, tmp[1]);
				else
					check_errors(NUL, "light bad format", tab[index[i]]);
				i++;
				free_tab(&tmp);
			}
			t++;
		}
	}
}


void				set_lightTok(t_sceneTok *sTok, char **tab)
{
	int		len;
	int		*tmp;

	len = obj_number(tab, N_LIGHT);
	if (!len)
		sTok->lightsTok = NULL;
	else
	{
		if (!(tmp = (int*)malloc(sizeof(int) * (len))))
			check_errors(MALLOC, "tmp", "set_lightTok.c");
		get_index(tab, tmp, N_LIGHT);
		new_lightsTok(sTok, len);
		set_lightsTok_tab((sTok->lightsTok), tab, tmp, len);
		free(tmp);
	}
}
