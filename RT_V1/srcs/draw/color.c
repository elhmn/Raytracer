/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 07:42:16 by bmbarga           #+#    #+#             */
/*   Updated: 2015/01/20 00:58:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			set_color(t_color *col)
{
	if (col)
	{
		col->r = (col->color & MASK_R) >> (8 * 2);
		col->g = (col->color & MASK_G) >> 8;
		col->b = (col->color & MASK_B);
		col->alpha = 0;
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
