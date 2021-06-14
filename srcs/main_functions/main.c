/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 08:33:16 by elhmn             #+#    #+#             */
/*   Updated: 2016/10/17 18:05:31 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include "put_var.h"
#include "read_file.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

/*
** Ongoing :
**	+ Mise a la norme
**	+ test rt_loader
**	+ delete debug
*/

int		main(int ac, char **av)
{
	t_rt		*rt;
	char		*scene;

	rt = NULL;
	scene = NULL;
	if (ac > 1)
		scene = read_file(av[1]);
	init_rt(&rt, scene);
	set_img(&(rt->img), rt->env->img, &(rt->lay));
	mlx_expose_hook(rt->env->win, expose_hook, (void*)rt);
	mlx_loop_hook(rt->env->mlx, loop_hook, (void*)rt);
	mlx_key_hook(rt->env->win, key_hook, (void*)rt);
	mlx_loop(rt->env->mlx);
	return (0);
}
