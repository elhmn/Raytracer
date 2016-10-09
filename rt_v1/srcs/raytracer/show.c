/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:08:17 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:21:32 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "put_var.h"
#include "object.h"

/*
** i will solve that issue later
** modifier la fonction show 
** et y ajouter la gestion
** de la taille des pixels = pixelRatio
*/

void	show(t_rt *rt)
{
	t_ray	**ray;
	int		i;
	int		j;
	int		w;
	int		h;

	ray = NULL;
	if (rt)
	{
		i = -1;
		ray = rt->ray;
		w = rt->screen->res_x;
		h = rt->screen->res_y;
		while (++i < w)
		{
			j = -1;
			while (++j < h)
			{
				if (ray && ray[j] && (ray[j] + i))
					pixel_put_img(rt, i, j, &(ray[j][i].col));
			}
		}
	}
}
