/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_function_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:41:51 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/28 18:32:11 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"

void	pos_add_to_pos(t_pos *p1, t_pos p2)
{
	if (p1)
	{
		p1->x += p2.x;
		p1->y += p2.y;
		p1->z += p2.z;
	}
}

void	pos_add_to_pos_values(t_pos *pos, double x, double y, double z)
{
	if (pos)
	{
		pos->x += x;
		pos->y += y;
		pos->z += z;
	}
}

void	pos_sub_to_pos(t_pos *p1, t_pos p2)
{
	if (p1)
	{
		p1->x -= p2.x;
		p1->y -= p2.y;
		p1->z -= p2.z;
	}
}

void	pos_sub_to_pos_values(t_pos *pos, double x, double y, double z)
{
	if (pos)
	{
		pos->x -= x;
		pos->y -= y;
		pos->z -= z;
	}
}

double	pos_dot_product(t_pos p1, t_pos p2)
{
	return (p1.x * p2.x + p1.y * p2.y + p1.z * p2.z);
}
