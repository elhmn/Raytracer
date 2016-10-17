/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 13:53:37 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 12:26:51 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void		load_camera(t_camera *c, t_cam_tok *t)
{
	if (c && t)
	{
		c->sp.o = t->pos;
		rot_camera(c, t->rot);
		pos_add_to_pos(&(c->sp.o), t->trans);
	}
}
