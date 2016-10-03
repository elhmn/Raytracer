/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tok_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 02:51:02 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 16:32:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void					get_position(t_pos *p, char **tab)
{
	char	*str;
	char	**tmp;

	str = NULL;
	if (tab)
		while (*tab)
			if ((str = find_type(*tab++, A_POSITION, SEP_4)))
				break ;
	if (!str)
		check_errors(NUL, "no position defined", "");
	tmp = ft_strsplit(str, SEP_5);
	if (!tmp && tab_len(tmp) != 3)
		check_errors(NUL, "wrong format", "");
	p->x = ft_atoi(tmp[0]);
	p->y = ft_atoi(tmp[1]);
	p->z = ft_atoi(tmp[2]);
	put_pos(*p);
	free(str);
	free_tab(tmp);
}

void					get_rotation(t_pos *p, char **tab)
{
	char	*str;
	char	**tmp;

	str = NULL;
	if (tab)
		while (*tab)
			if ((str = find_type(*tab++, A_ROTATION, SEP_4)))
				break ;
	if (!str)
		check_errors(NUL, "no rotation defined", "");
	tmp = ft_strsplit(str, SEP_5);
	if (!tmp && tab_len(tmp) != 3)
		check_errors(NUL, "wrong format", "");
	p->x = ft_atoi(tmp[0]);
	p->y = ft_atoi(tmp[1]);
	p->z = ft_atoi(tmp[2]);
	free(str);
	free_tab(tmp);
	put_pos(*p); //Debug
}
