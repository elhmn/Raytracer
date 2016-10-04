/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lightsTok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 13:35:20 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 13:35:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "put_var.h"
#include "rt.h"
#include "load_scene.h"
#include "init.h"

void		put_lightTok(t_lightTok *t)
{
	if (t)
	{
		ft_putendl("light :\n{\n");
		ft_putstr("type = ");
		ft_putendl(t->type);
		ft_putstr("pos -> ");
		put_pos(t->pos);
		ft_putstr("Is -> ");
		put_pos(t->Is);
		ft_putstr("Id -> ");
		put_pos(t->Id);
		ft_putendl("}\n");
	}
}

void		put_lightsTok(t_lightTok **t)
{
	if (!t)
		return ;
	while (*t)
		put_lightTok(*t++);
}


