/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:08:17 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/24 17:18:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
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

	ray = rt->ray;
	if (rt)
	{
		i = -1;
		w = rt->screen->resX;
		h = rt->screen->resY;
		while (++i < w)
		{
			j = -1;
			while (++j < h)
				pixel_put_img(rt, i, j, &(ray[j][i].col));
		}
	}
}
