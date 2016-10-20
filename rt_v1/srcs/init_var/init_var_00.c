/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:28:41 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/20 17:40:16 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "check_errors.h"
#include "rt.h"
#include "put_var.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

void		init_rt(t_rt **rt, char *scene)
{
	if (rt)
	{
		start_block("init_rt");
		if (!(*rt = (t_rt*)malloc(sizeof(t_rt))))
			check_errors(MALLOC, "init_var_00.c", "rt");
		init_env(&((*rt)->env));
		init_screen(&((*rt)->screen));
		init_space(&((*rt)->space));
		init_ray_array(&((*rt)->ray), (*rt)->screen);
		(*rt)->camera = NULL;
		(*rt)->lights = NULL;
		(*rt)->objs = NULL;
		init_scene(*rt, scene);
		(*rt)->img = NULL;
		(*rt)->refresh = 1;
		(*rt)->render = 0;
		(*rt)->diffuse = 0;
		(*rt)->specular = 0;
		(*rt)->shadow = 0;
		end_block("init_rt");
	}
}

void		init_env(t_env **env)
{
	if (env)
	{
		start_block("init_env");
		if (!(*env = (t_env*)malloc(sizeof(t_env))))
			check_errors(MALLOC, "init_var_00.c", "env");
		if (!((*env)->mlx = mlx_init()))
			check_errors(MALLOC, "init_var_00.c", "mlx");
		if (!((*env)->win = mlx_new_window((*env)->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "RTV1")))
			check_errors(MALLOC, "init_var_00.c", "win");
		if (!((*env)->img = mlx_new_image((*env)->mlx,
								SCREEN_WIDTH, SCREEN_HEIGHT)))
			check_errors(MALLOC, "init_var_00.c", "img");
		end_block("init_env");
	}
}

void		init_screen(t_screen **screen)
{
	if (screen)
	{
		start_block("init_screen");
		if (!(*screen = (t_screen*)malloc(sizeof(t_screen))))
			check_errors(MALLOC, "init_var_00.c", "screen");
		screen[0]->pixel_width = PIXEL_WIDTH;
		screen[0]->pixel_height = PIXEL_HEIGHT;
		screen[0]->width = SCREEN_WIDTH;
		screen[0]->height = SCREEN_HEIGHT;
		screen[0]->res_x = RESX;
		screen[0]->res_y = RESY;
		end_block("init_screen");
	}
}

void		init_camera(t_camera **camera,
							t_screen screen, t_space *space)
{
	if (camera && space)
	{
		start_block("init_camera");
		if (!(*camera = (t_camera*)malloc(sizeof(t_camera))))
			check_errors(MALLOC, "init_var_00.c", "camera");
		camera[0]->field_of_view = FOV;
		camera[0]->dist = (double)(screen.pixel_width * screen.res_x)
		/ (double)(tan(RAD((camera[0]->field_of_view / 2.)) * 2.));
		set_pos(&(camera[0]->v_up), 1, 1, 1);
		init_base_self(&(camera[0]->sp));
		set_pos(&(camera[0]->sp.o), 0, 100,
		-(camera[0]->dist + SAFE_DIST));
		end_block("init_camera");
	}
}
