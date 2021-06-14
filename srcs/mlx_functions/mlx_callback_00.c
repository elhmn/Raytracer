/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_callback_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:39:51 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:43:08 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "put_var.h"
#include "check_errors.h"
#include "object.h"

/*
** gerer correctement l'expose
*/

int			loop_hook(void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
	if (!(rt = (t_rt*)param))
		check_errors(NUL, "rt", "mlx_callback_00.c");
	loop(rt);
	return (0);
}

int			expose_hook(void *param)
{
	t_rt	*rt;

	rt = (t_rt*)param;
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
		check_errors(NUL, "mlx_callback_00.c", "rt->env struct");
	return (0);
}
