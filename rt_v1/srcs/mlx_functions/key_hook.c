/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:42:41 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:45:51 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "put_var.h"
#include "check_errors.h"
#include "object.h"

void		key_move(t_rt *rt, int keycode)
{
	if (keycode == K_W)
		pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, MOVE, 0));
	else if (keycode == K_S)
		pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, -MOVE, 0));
	else if (keycode == K_A)
		pos_add_to_pos(&(rt->camera->sp.o), get_pos(-MOVE, 0, 0));
	else if (keycode == K_D)
		pos_add_to_pos(&(rt->camera->sp.o), get_pos(MOVE, 0, 0));
	else if (keycode == K_E)
		pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, 0, MOVE));
	else if (keycode == K_Q)
		pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, 0, -MOVE));
	else
		return ;
	rt->refresh = 1;
}

void		key_rotation(t_rt *rt, int keycode)
{
	if (keycode == K_RIGHT)
		rot_camera(rt->camera, get_pos(0, ROT, 0));
	else if (keycode == K_LEFT)
		rot_camera(rt->camera, get_pos(0, -ROT, 0));
	else if (keycode == K_UP)
		rot_camera(rt->camera, get_pos(ROT, 0, 0));
	else if (keycode == K_DOWN)
		rot_camera(rt->camera, get_pos(-ROT, 0, 0));
	else
		return ;
	rt->refresh = 1;
}

void		key_render_control(t_rt *rt, int keycode)
{
	if (keycode == K_1)
	{
		rt->render = (rt->render) ? 0 : 1;
		if (rt->render)
		{
			rt->diffuse = 1;
			rt->specular = 1;
		}
	}
	else if (keycode == K_2)
		rt->diffuse = (rt->diffuse) ? 0 : 1;
	else if (keycode == K_3)
		rt->specular = (rt->specular) ? 0 : 1;
	else
		return ;
	rt->refresh = 1;
}

int			key_hook(int keycode, void *param)
{
	t_rt		*rt;

	rt = (t_rt*)param;
	key_move(rt, keycode);
	key_rotation(rt, keycode);
	key_render_control(rt, keycode);
	if (keycode == K_QUIT)
	{
		release_mlx(rt);
		exit(0);
	}
	return (0);
}
