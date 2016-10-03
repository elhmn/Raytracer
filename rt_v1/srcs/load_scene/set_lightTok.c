/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lightTok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 03:10:01 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 16:46:19 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void			get_index(char **tab, int *t)
{
	int		i;

	i = -1;
	if (tab)
	{
		while (tab[++i])
		{
			if ((find_type(tab[i], N_LIGHT, SEP_2)))
				*t++ = i;
		}
	}
}

int					obj_number(char **tab)
{
	int		len;

	len = 0;
	if (tab)
		while (*tab)
			if ((find_type(*tab++, N_LIGHT, SEP_2)))
				len++;
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
		}
	}
}

void				set_lightTok_var(t_lightTok *t, char *s)
{
	char		**tab;

	(void)t;
	(void)s;
	tab = NULL;
	if (s && t)
	{
		tab = ft_strsplit(s, SEP_3);
		put_tab(tab); //Debug
		ft_putendl(" ---------------- "); //Debug
	}
	free_tab(tab);
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
			}
			t++;
		}
	}
	free_tab(tmp);
}


void				set_lightTok(t_sceneTok *sTok, char **tab)
{
	int		len;
	int		*tmp;

	(void)sTok;
	(void)tab;
	len = obj_number(tab);
	put_var_dbl("object len", obj_number(tab)); //Debug
	if (!len)
		check_errors(NUL, "no light defined", "");
	if (!(tmp = (int*)malloc(sizeof(int) * (len))))
		check_errors(MALLOC, "tmp", "set_lightTok.c");

	get_index(tab, tmp);
	new_lightsTok(sTok, len);
	set_lightsTok_tab((sTok->lightsTok), tab, tmp, len);
	free(tmp);
}
