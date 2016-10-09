/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 00:28:56 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:20:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include "check_errors.h"
#include "libft.h"
#include "put_var.h"

void	clear_image(t_rt *rt)
{
	int		i;
	int		j;
	int		w;
	int		h;
	t_color	col;

	col = get_color(0, 0, 0);
	if (rt && rt->screen)
	{
		i = -1;
		w = rt->screen->res_x;
		h = rt->screen->res_y;
		while (++i < w)
		{
			j = -1;
			while (++j < h)
					pixel_put_img(rt, i, j, &col);
		}
	}
}

void	release_mlx(t_rt *rt)
{
	t_env	*e;

	e = NULL;
	if (rt && rt->env)
	{
		e = rt->env;
		clear_image(rt);
		mlx_destroy_image(e->mlx, e->img);
		e->img = NULL;
		rt->img = NULL;
		mlx_clear_window(e->mlx, e->win);
		mlx_destroy_window(e->mlx, e->win);
		e->win = NULL;
	}
	ft_putendl("I release var"); //Debug
}
