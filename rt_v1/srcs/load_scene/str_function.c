/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 01:01:57 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 02:32:51 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include <stdlib.h>

int						tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab && *tab)
	{
		tab++;
		i++;
	}
	return (i);
}

void					put_tab(char **tab)
{
	while (*tab)
	{
		ft_putstr("[");
		ft_putstr(*tab++);
		ft_putendl("]");
	}
}

void					cust_epurstr(char *s)
{
	int			i;
	int			tmp;

	if (s)
	{
		tmp = 0;
		i = 0;
		while (s[i] && s[tmp])
		{
			if (s[tmp] && s[i] && (s[i] != '\n' && s[i] != ' ' && s[i] != '\t'))
			{
				s[tmp] = s[i];
				if (i != tmp)
					s[i] = ' ';
				tmp++;
			}
			if (!s[tmp])
				break;
			i++;
		}
		if (!s[i])
			s[tmp] = '\0';
	}
}

void					str_lower(char *s)
{
	while (s && *s)
	{
		*s = ft_tolower(*s);
		s++;
	}
}
