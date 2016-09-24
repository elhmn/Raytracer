/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:28:46 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/24 17:28:47 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "check_errors.h"
#include "rt.h"
#include <mlx.h>
#include <stdlib.h>

void		set_ray_array_zero(t_ray **ray, t_screen *screen)
{
	int		max_x;
	int		max_y;
	int		i;
	int		j;

	if (screen && ray)
	{
		max_x = screen->resX;
		max_y = screen->resY;
		i = -1;
		while (++i < max_y)
		{
			j = -1;
			while (++j < max_x)
				init_ray(ray[i] + j);
		}
	}
}

void		init_ray_array(t_ray ***ray, t_screen *screen)
{
	int		max_x;
	int		max_y;
	int		i;

	if (screen)
	{
		max_x = screen->resX;
		max_y = screen->resY;
		i = -1;
		if (ray)
		{
			if (!(*ray = (t_ray**)malloc(sizeof(t_ray*) * max_y)))
				check_errors(MALLOC, "init_var_00.c", "ray");
		}
		while (++i < max_y)
		{
			if (!(ray[0][i] = (t_ray*)malloc(sizeof(t_ray) * max_x)))
				check_errors(MALLOC, "init_var_00.c", "*ray");
		}
		set_ray_array_zero(*ray, screen);
	}
	ft_putendl("init_ray called"); //Debug
}

void		init_base_self(t_base *b)
{
	b->o.x = 0;
	b->o.y = 0;
	b->o.z = 0;

	b->i.x = 1;
	b->i.y = 0;
	b->i.z = 0;
	
	b->j.x = 0;
	b->j.y = 1;
	b->j.z = 0;
	
	b->k.x = 0;
	b->k.y = 0;
	b->k.z = 1;
}

void		set_base_zero(t_base *b)
{
	b->o.x = 0;
	b->o.y = 0;
	b->o.z = 0;

	b->i.x = 0;
	b->i.y = 0;
	b->i.z = 0;
	
	b->j.x = 0;
	b->j.y = 0;
	b->j.z = 0;
	
	b->k.x = 0;
	b->k.y = 0;
	b->k.z = 0;
}

void		init_space(t_space **space)
{
	if (space)
	{
		if (!(*space = (t_space*)malloc(sizeof(t_space))))
			check_errors(MALLOC, "init_var_00.c", "space");
		init_base_self(&(space[0]->self));
		set_base_zero(&(space[0]->camera));
	}
	ft_putendl("init_space called"); //Debug
}
