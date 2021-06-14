/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_var_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:02:09 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:02:54 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <mlx.h>
#include "rt.h"
#include "check_errors.h"

void			copy_pos(t_pos *dst, t_pos src)
{
	if (dst)
	{
		dst->x = src.x;
		dst->y = src.y;
		dst->z = src.z;
	}
}

void			set_pos(t_pos *pos, double x, double y, double z)
{
	if (pos)
	{
		pos->x = x;
		pos->y = y;
		pos->z = z;
	}
}

void			set_img(char **img, void *void_img, t_lay *lay)
{
	if (img && lay && void_img)
	{
		*img = (char*)mlx_get_data_addr(void_img, &(lay->bpp),
				&(lay->line), &(lay->endian));
		if (!(*img))
			check_errors(MALLOC, "set_var_00.c", "img");
	}
}
