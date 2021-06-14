/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cam_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 18:37:12 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 18:42:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "rt.h"
#include "load_scene.h"
#include "init.h"

void		put_cam_tok(t_cam_tok *t)
{
	if (t)
	{
		ft_putendl("camera :\n{\n");
		ft_putstr("pos -> ");
		put_pos(t->pos);
		ft_putstr("rot -> ");
		put_pos(t->rot);
		ft_putstr("lookat = ");
		ft_putendl(t->lookat);
		ft_putendl("}\n");
	}
}
