/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_camTok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 13:34:40 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 13:34:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "rt.h"
#include "load_scene.h"
#include "init.h"

void		put_camTok(t_camTok *t)
{
	if (t)
	{
		ft_putendl("camera :\n{\n");
		ft_putstr("pos -> ");
		put_pos(t->pos);
		ft_putstr("rot -> ");
		put_pos(t->rot);
		ft_putstr("lookAt = ");
		ft_putendl(t->lookAt);
		ft_putendl("}\n");
	}
}

