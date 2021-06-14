/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lights_tok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:36:48 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 18:43:44 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "rt.h"
#include "load_scene.h"
#include "init.h"

void		put_light_tok(t_light_tok *t)
{
	if (t)
	{
		ft_putendl("light :\n{\n");
		ft_putstr("type = ");
		ft_putendl(t->type);
		ft_putstr("pos -> ");
		put_pos(t->pos);
		ft_putstr("Is -> ");
		put_pos(t->is);
		ft_putstr("id -> ");
		put_pos(t->id);
		ft_putendl("}\n");
	}
}

void		put_lights_tok(t_light_tok **t)
{
	if (!t)
		return ;
	while (*t)
		put_light_tok(*t++);
}
