/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 02:51:02 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 13:01:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void					get_dbl_tok(double *p, char **tab, char *type)
{
	char	*str;

	str = NULL;
	if (tab)
		while (*tab)
			if ((str = find_type(*tab++, type, SEP_4)))
				break ;
	if (str)
	{
		*p = ft_atoi(str);
		free(str);
	}
}

void					get_pos_tok(t_pos *p, char **tab, char *type)
{
	char	*str;
	char	**tmp;

	str = NULL;
	tmp = NULL;
	if (tab)
		while (*tab)
			if ((str = find_type(*tab++, type, SEP_4)))
				break ;
	if (str)
	{
		tmp = ft_strsplit(str, SEP_5);
		if (!tmp && tab_len(tmp) != 3)
			check_errors(NUL, "wrong format", "");
		p->x = ft_atoi(tmp[0]);
		p->y = ft_atoi(tmp[1]);
		p->z = ft_atoi(tmp[2]);
		free(str);
	}
	free_tab(tmp);
}

void					get_label_tok(char **s, char **tab, char *type)
{
	char	*str;

	str = NULL;
	if (tab)
		while (*tab)
			if ((str = find_type(*tab++, type, SEP_4)))
				break ;
	if (str)
		s[0] = str;
}
