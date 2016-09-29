/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 08:33:16 by elhmn             #+#    #+#             */
/*   Updated: 2016/09/29 20:20:33 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include "put_var.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

/*
**			TO_DO
**	+Get scene from file
**	+Load scene
**	+Loop
**		- Raytracer
**		- Realtime events
**		- Simple Real Time Renderer
**	+Destroy objects (don't forget to do that)
*/

/*
**			TO_DO_2
**	+Create Other Objects
**		-Plane
**		-Cylindre
**		-Cone
**		-Tore (bonus)
**	+Camera transformation
**		-Camera movement
**		-Camera rotation
**		-Camera lookAt object
**	+Create Light source
**		-Luminosite
**		-Ombres
**		-Brillance (bonus)
**	+MultiSpot (bonus)
**	+Load those object from file
**		-Design file format
**	+Load Scene from file
**	+Create multiple scene files for Defence at 42
*/

/*			BUGS
**	+Correct Rotation Gimbal effect				In progress
**	+Camera rotation issue						In progress
**	+Camera perspective a bit wierd				In progress
**
**	+Plane rotation and creation 					
**	+Cylinder limitation						DONE
**	+Cone limitation							
**
**	+Segfault unknown							Will keep in progress
*/

int		main(int ac, char **av)
{
	t_rt		*rt;
	
	rt = NULL;
	(void)av;
	(void)ac;

	init_rt(&rt);
	set_img(&(rt->img), rt->env->img, &(rt->lay));
	mlx_expose_hook(rt->env->win, expose_hook, (void*)rt);
	mlx_loop_hook(rt->env->mlx, loop_hook, (void*)rt);
	mlx_key_hook(rt->env->win, key_hook, (void*)rt);
	mlx_loop(rt->env->mlx);
	return (0);
}
