/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lightTok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 03:10:01 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 03:40:23 by bmbarga          ###   ########.fr       */
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
		while (tab[++i])
		{
			if ((find_type(tab[i], N_LIGHT, SEP_2)))
				*t++ = i;
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

void				new_lightsTok(sTok, int len)
{
	if (sTok)
	{
		if (!(sTok->lightsTok =
				(t_lightTok*)malloc(sizeof(t_lightTok) * (len + 1))));
			check_errors(MALLOC, "sTok->lightsTok", "set_lightTok");
			sTok->lightsTok[len] = NULL;
	}
}

/*
void				set_lightsTok_tab(t_lightsTok **t, char **tab, int i)
{
	if (t && tab)
	{
		while (*t)
		{
			t++;
		}
	}
}
*/
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
	if (!(tmp = (int*)malloc(sizeof(int) * len)))
		check_errors(MALLOC, "tmp", "set_lightTok.c");
	get_index(tab, tmp);
	new_lightsTok(sTok, len);
//	set_lightsTok_tab(sTok->lightsTok, tab, tmp);
	free(tmp);
}
