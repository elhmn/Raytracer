/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 08:33:16 by elhmn             #+#    #+#             */
/*   Updated: 2016/10/02 19:52:01 by bmbarga          ###   ########.fr       */
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
** Ongoing :
**	+ Design scene description format
**	+ Open and Read description format
**	+ Parse file
**	+ Load scene From file
**	+ Reshape Code
**	+ Mise a la norme
*/


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
**		-Plane 							DONE
**		-Cylindre						DONE
**		-Cone							DONE
**	+Camera transformation				
**		-Camera movement				DONE
**		-Camera rotation				DONE
**		-Camera lookAt object			NOT YET
**
**	+Create Light source				
**		-Luminosite						DONE
**		-Ombres							DONE
**		-Brillance (bonus)				DONE
**
**	+MultiSpot (bonus)					DONE
**
**	+Load those object from file		
**		-Design file format
**
**	+Load Scene from file
**
**	+Create multiple scene files for Defence at 42
*/


/*
**		BUGS:
**
**
*/

int		main(int ac, char **av)
{
	t_rt		*rt;
	
	rt = NULL;
	(void)av;
	(void)ac;

	if (ac > 1)
	{
		//load scene from file
		ft_putendl("Load rt from file");
	}
	else
	{
		ft_putendl("empty scene, with a simple camera");
		//create an empty scene
		// and open a command prompt
	}
	init_rt(&rt);
	set_img(&(rt->img), rt->env->img, &(rt->lay));
	mlx_expose_hook(rt->env->win, expose_hook, (void*)rt);
	mlx_loop_hook(rt->env->mlx, loop_hook, (void*)rt);
	mlx_key_hook(rt->env->win, key_hook, (void*)rt);
	mlx_loop(rt->env->mlx);
	return (0);
}
