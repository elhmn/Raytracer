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

int	main(int ac, char **av)
{
	t_rt		*rt;

	rt = NULL;
	(void)av;
	(void)ac;
	
	init_rt(&rt);
//	put_space(*(rt->space)); //Debug
//	put_camera(*(rt->camera)); //Debug
//	put_screen(*(rt->screen)); //Debug
//	t_ray ray;
//	put_ray(ray);
	mlx_loop_hook(rt->env->mlx, loop_hook, (void*)rt->env);
//	mlx_loop(rt->env->mlx); //Debug
	return (0);
}
