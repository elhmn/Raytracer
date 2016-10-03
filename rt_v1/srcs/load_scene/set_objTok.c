/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objTok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 17:34:06 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 17:53:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void				new_objsTok(t_sceneTok *sTok, int len)
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
		}
	}
}

void				set_objTok_var(t_objTok *t, char *s)
{
	char		**tab;

	(void)t;
	(void)s;
	tab = NULL;
	if (s && t)
	{
		tab = ft_strsplit(s, SEP_3);
		get_label_tok(&t->type, tab, A_TYPE);
		get_label_tok(&t->name, tab, A_NAME);

		get_pos_tok(&t->pos, tab, A_POSITION);
		get_pos_tok(&t->rot, tab, A_ROTATION);
		get_pos_tok(&t->col, tab, A_COLOR);
		get_pos_tok(&t->mat, tab, A_MATERIAL);
		t->data = NULL;

		ft_putendl(" >----------------< "); //Debug
		ft_putstr("type = ");
		ft_putendl(t->type);
		put_pos(t->pos);
		put_pos(t->rot);
		put_pos(t->mat);
		ft_putendl(" >----------------> "); //Debug
	}
	free_tab(tab);
}

void				set_objsTok_tab(t_objTok **t, char **tab, int *index, int len)
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

	(void)sTok;
	(void)tab;

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
