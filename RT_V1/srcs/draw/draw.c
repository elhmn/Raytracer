/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:24:59 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/26 20:16:38 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include <mlx.h>

/*
** set pixel_put_img a 4 parametres
*/

void		pixel_put_img(t_rt *rt, int x, int y, t_color *col)
{
	int			size;
	char		*image;
	int			b;

	if (!rt)
		check_errors(NUL, "rt", "draw.c");
	image = rt->img;
	if (col && image)
	{
		size = rt->lay.line;
		b = rt->lay.bpp / 8;
		x *= b;
		if (size > 0 && (y < SCREEN_HEIGHT && y >= 0)
				&& (x >= 0 && x + rt->lay.bpp / 8 < size))
		{
			image[(y * (size)) + x + 0] = col->b;
			image[(y * (size)) + x + 1] = col->g;
			image[(y * (size)) + x + 2] = col->r;
			image[(y * (size)) + x + 3] = col->alpha;
		}
	}
}
