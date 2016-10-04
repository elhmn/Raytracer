/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 07:42:16 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 16:42:54 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_color.h"
#include "rt.h"

t_color			get_color(t_uint r, t_uint g, t_uint b)
{
	t_color		col;

	col.color = rgb_to_color(LIMIT_COL(r), LIMIT_COL(g), LIMIT_COL(b));
	set_color(&col);
	return (col);
}

t_color			get_reshaped_color(t_color col)
{
	return (get_color(col.r, col.g, col.b));
}

void			set_color(t_color *col)
{
	if (col)
	{
		col->alpha = (col->color & MASK_A) >> (8 * 2);
		col->r = (col->color & MASK_R) >> (8 * 2);
		col->g = (col->color & MASK_G) >> 8;
		col->b = (col->color & MASK_B);
	}
}

t_uint			rgb_to_color(t_uint r, t_uint g, t_uint b)
{
	unsigned int color;

	color = 0;
	r = (r << 8 * 2);
	g = (g << 8);
	color = r | g | b;
	return (color);
}
