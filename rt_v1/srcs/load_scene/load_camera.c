/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 13:53:37 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 17:54:59 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void		load_camera(t_camera *c, t_camTok *t)
{
	if (c && t)
	{
		c->sp.o = t->pos;
		rot_camera(c, t->rot);
		add_pos_to_pos(l->sp.o, t->trans);
	}
	ft_putendl("load camera"); //Debug
}
