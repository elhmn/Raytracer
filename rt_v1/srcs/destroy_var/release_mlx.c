/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 00:28:56 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 22:24:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "mlx.h"
#include "check_errors.h"
#include "libft.h"
#include "put_var.h"

void	clear_image(t_rt *rt)
{
	if (rt)
	{
		ft_memset((void*)(rt->img), '\0', rt->lay.depht);
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
