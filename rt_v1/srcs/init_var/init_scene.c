/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 21:09:21 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 03:41:20 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "object.h"
#include "check_errors.h"
#include "rt.h"
#include "put_var.h"
#include "init.h"
#include "load_scene.h"
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

void		init_scene(t_rt *rt, char *scene)
{
	(void)rt;
	(void)scene;

	ft_putendl("init scene"); //Debug
	if (rt)
	{
		init_camera(&(rt->camera), *(rt->screen),
						rt->space);
		rt->objs = NULL;
		rt->lights = NULL;
//		/*
			init_objs(&(rt->objs));
			init_lights(&(rt->lights));
//		*/
//		load_scene(scene);
		ft_putendl("load empty scene"); //Debug
		if (scene)
		{
			ft_putendl("load scene"); //Debug
		}
	}
}
