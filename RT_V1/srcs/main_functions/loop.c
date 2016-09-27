/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:03:14 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/27 09:49:54 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "put_var.h"
#include "check_errors.h"
#include "transform.h"

void	loop(t_rt *rt)
{
	if (rt)
	{
		if (rt->refresh)
		{
			ft_putendl("loop_hook enter"); //Debug
			raytracer(rt);
			clear_image(rt);
			show(rt);
			if (rt->env
				&& rt->env->mlx
				&& rt->env->win
				&& rt->env->img)
			{
				mlx_clear_window(rt->env->mlx, rt->env->win);
				mlx_put_image_to_window(rt->env->mlx, rt->env->win,
									rt->env->img, 0, 0);
			}
			else
				check_errors(NUL, "loop.c", "rt->env struct");
			rt->refresh = 0;
			ft_putendl("loop_hook exit"); //Debug
		}
	}
}
