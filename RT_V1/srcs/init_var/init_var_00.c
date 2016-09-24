/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:28:41 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/24 19:02:07 by bmbarga          ###   ########.fr       */
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

void		init_rt(t_rt **rt)
{
	if (rt)
	{
		if (!(*rt = (t_rt*)malloc(sizeof(t_rt))))
			check_errors(MALLOC, "init_var_00.c", "rt");
		init_env(&((*rt)->env));
		init_screen(&((*rt)->screen));
		init_space(&((*rt)->space));
		init_camera(&((*rt)->camera), *((*rt)->screen), (*rt)->space);
		init_ray_array(&((*rt)->ray), (*rt)->screen);
		init_objs(&(*rt)->objs);
		(*rt)->img = NULL; 
//		rot_camera((*rt)->camera, get_pos(-25, 0, 0));//Debug
//		pos_add_to_pos(&(rt[0]->camera->sp.o), get_pos(0, -40, -10)); //Debug

//		rot_camera((*rt)->camera, get_pos(0, 0, 0));//Debug
		pos_add_to_pos(&(rt[0]->camera->sp.o), get_pos(0, 300, -200)); //Debug
	}
	ft_putendl("init_rt called"); //Debug
}

void		init_env(t_env **env)
{
 //Debug
	if (env)
	{

		if (!(*env = (t_env*)malloc(sizeof(t_env))))
			check_errors(MALLOC, "init_var_00.c", "env");
		if (!((*env)->mlx = mlx_init()))
			check_errors(MALLOC, "init_var_00.c", "mlx");
		if (!((*env)->win = mlx_new_window((*env)->mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "RTV1")))
			check_errors(MALLOC, "init_var_00.c", "win");
		if (!((*env)->img = mlx_new_image((*env)->mlx, SCREEN_WIDTH, SCREEN_HEIGHT)))
			check_errors(MALLOC, "init_var_00.c", "img");
	}
	ft_putendl("init_env called"); //Debug
}

void		init_screen(t_screen **screen)
{
	if (screen)
	{
		if (!(*screen = (t_screen*)malloc(sizeof(t_screen))))
			check_errors(MALLOC, "init_var_00.c", "screen");

		screen[0]->pixelWidth = PIXEL_WIDTH;
		screen[0]->pixelHeight = PIXEL_HEIGHT;
		screen[0]->width = SCREEN_WIDTH;
		screen[0]->height = SCREEN_HEIGHT;
		screen[0]->resX = RESX;
		screen[0]->resY = RESY;
	}
	ft_putendl("init_screen called"); //Debug
}

void		init_camera(t_camera **camera, t_screen screen, t_space *space)
{
	if (camera && space)
	{
		if (!(*camera = (t_camera*)malloc(sizeof(t_camera))))
			check_errors(MALLOC, "init_var_00.c", "camera");
		camera[0]->fieldOfView = FOV;
		camera[0]->dist = (double)(screen.pixelWidth * screen.resX)
		/ (double)(tan(RAD((camera[0]->fieldOfView / 2.)) * 2.));
		set_pos(&(camera[0]->v_up), 1, 1, 1);
		init_base_self(&(camera[0]->sp));
		set_pos(&(camera[0]->sp.o), 0, 0,
		- (camera[0]->dist + SAFE_DIST));
	}
	ft_putendl("init_camera called"); //Debug
}
