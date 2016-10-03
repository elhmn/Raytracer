/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_callback_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 09:46:44 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/02 21:29:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "put_var.h"
#include "check_errors.h"
#include "object.h"

/*
** gerer correctement l'expose
*/

int			loop_hook(void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (!(rt = (t_rt*)param))
		check_errors(NUL, "rt", "mlx_callback_00.c");
	loop(rt);
	return (0);
}

int			expose_hook(void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (rt->env
		&& rt->env->mlx
		&& rt->env->win
		&& rt->env->img)
	{
		mlx_clear_window(rt->env->mlx, rt->env->win);
		mlx_put_image_to_window(rt->env->mlx, rt->env->win,
							rt->env->img, 0, 0);
	}
	else
		check_errors(NUL, "mlx_callback_00.c", "rt->env struct");
	ft_putendl("expose_hook");//Debug
	return (0);
}

int			key_hook(int keyCode, void *param)
{
	t_rt		*rt;

	rt = (t_rt*)param;
	put_var_dbl("keyCode", keyCode); //Debug
	if (keyCode == K_QUIT)
	{
		//release rt function
		release_mlx(rt);
		exit(0);
	}
	//Debug------------------
	if (keyCode == K_RIGHT)
	{
		rt->refresh = 1;
		rot_camera(rt->camera, get_pos(0, ROT, 0));
	}
	if (keyCode == K_LEFT)
	{
		rt->refresh = 1;
		rot_camera(rt->camera, get_pos(0, -ROT, 0));
	}
	if (keyCode == K_UP)
	{
		rt->refresh = 1;
		rot_camera(rt->camera, get_pos(ROT, 0, 0));
	}
	if (keyCode == K_DOWN)
	{
		rt->refresh = 1;
		rot_camera(rt->camera, get_pos(-ROT, 0, 0));
	}
	if (keyCode == K_W)
	{
		rt->refresh = 1;
	    pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, MOVE, 0));
	}
	if (keyCode == K_S)
	{
		rt->refresh = 1;
	    pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, -MOVE, 0));
	}
	if (keyCode == K_A)
	{
		rt->refresh = 1;
	    pos_add_to_pos(&(rt->camera->sp.o), get_pos(-MOVE, 0, 0));
	}
	if (keyCode == K_D)
	{
		rt->refresh = 1;
	    pos_add_to_pos(&(rt->camera->sp.o), get_pos(MOVE, 0, 0));
	}
	if (keyCode == K_E)
	{
		rt->refresh = 1;
	    pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, 0, MOVE));
	}
	if (keyCode == K_Q)
	{
		rt->refresh = 1;
	    pos_add_to_pos(&(rt->camera->sp.o), get_pos(0, 0, -MOVE));
	}
	if (keyCode == K_1)
	{
		rt->render = (rt->render) ? 0 : 1;
		if (rt->render)
		{
			rt->diffuse = 1;
			rt->specular = 1;
		}
		rt->refresh = 1;
	}
	if (keyCode == K_2)
	{
		rt->diffuse = (rt->diffuse) ? 0 : 1;
		rt->refresh = 1;
	}
	if (keyCode == K_3)
	{
		rt->specular = (rt->specular) ? 0 : 1;
		rt->refresh = 1;
	}
	//put_camera(*(rt->camera)); //Debug
	return (0);
}
