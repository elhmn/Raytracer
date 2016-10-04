/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 21:09:21 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 17:28:01 by bmbarga          ###   ########.fr       */
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
	(void)scene;
	ft_putendl("init scene"); //Debug
	if (rt)
	{
		rt->objs = NULL;
		rt->lights = NULL;
		//init_objs(&(rt->objs));
		//init_lights(&(rt->lights));
		load_scene(rt, scene);
		if (!(rt->camera))
			init_camera(&(rt->camera), *(rt->screen),
						rt->space);
		if (!(rt->lights))
			init_lights(&(rt->lights));
		if (!(rt->objs))
			init_objs(&(rt->objs));
		ft_putendl("load empty scene"); //Debug
		if (scene)
		{
			ft_putendl("load scene"); //Debug
		}
	}
}
