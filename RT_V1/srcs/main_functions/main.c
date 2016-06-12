/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 08:33:16 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/13 08:33:16 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include "put_var.h"
#include <mlx.h>
#include <stdlib.h>

/*
**			TO_DO
**	+Get scene from file
**	+Load scene
**	+Loop
**		- Raytracer
**		- Realtime events
**		- Simple Real Time Renderer
**	+Destroy objects
*/

void	drawSquare(t_rt *rt)
{
	t_color		col;
	int			i;
	int			j;

	i = -1;
	col.color = 0xFFFFFF;
	set_color(&col);
	while (++i < SCREEN_WIDTH / 2)
	{
		j = -1;
		while (++j < SCREEN_HEIGHT / 2)
			pixel_put_img(rt, i, j, &col);
	}
}

int	main(int ac, char **av)
{
	t_rt		*rt;
	
	rt = NULL;
	(void)av;
	(void)ac;
	
	init_rt(&rt);

	put_space(*(rt->space)); //Debug
	put_camera(*(rt->camera)); //Debug
	put_screen(*(rt->screen)); //Debug
	set_img(&(rt->img), rt->env->img, &(rt->lay));

//	drawSquare(rt); //Debug
//	mlx_put_image_to_window(rt->env->mlx, rt->env->win, rt->env->img, 0, 0);

	mlx_loop_hook(rt->env->mlx, loop_hook, (void*)rt);
	mlx_loop(rt->env->mlx);
	return (0);
}
