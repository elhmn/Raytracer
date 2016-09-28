/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_move_00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:51:17 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/28 19:08:26 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include "put_var.h"
#include <stdlib.h>

void		move_base(t_base *b, t_pos pos)
{
	if (b)
	{
		pos_add_to_pos(&(b->o), pos);
		pos_add_to_pos(&(b->i), pos);
		pos_add_to_pos(&(b->j), pos);
		pos_add_to_pos(&(b->k), pos);
	}
}

void		move_obj(t_obj *o, t_pos pos)
{
	if (o)
		move_base(&(o->sp), pos); 
}

void		move_camera(t_camera *c, t_pos pos)
{
	if (c)
		move_base(&(c->sp), pos);
}
