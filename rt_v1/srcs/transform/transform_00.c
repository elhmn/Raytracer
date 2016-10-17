/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:06:52 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:04:46 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "put_var.h"
#include "transform.h"

/*
** Note that base b vectors are expressed with a base vectors
** Refering to my notes i will use the simplified formulas
** Don't forget to test those functions
*/

/*
** Transform method 2 Description :
**  -rotation d'angle r des (u, v, w) dans le repere A
**  -rotation d'angle -r des (i, j, k) dans B
*/

t_pos		transform(t_base a, t_base b, t_pos pos, t_pos rot)
{
	t_pos	p;
	t_base	e;

	e = a;
	pos_mult_to_number(&rot, -1);
	p.x = (pos.x - b.o.x) * e.i.x + (pos.y - b.o.y) * e.j.x
			+ (pos.z - b.o.z) * e.k.x;
	p.y = (pos.x - b.o.x) * e.i.y + (pos.y - b.o.y) * e.j.y
			+ (pos.z - b.o.z) * e.k.y;
	p.z = (pos.x - b.o.x) * e.i.z + (pos.y - b.o.y) * e.j.z
			+ (pos.z - b.o.z) * e.k.z;
	return (p);
}

t_pos		transform_rev(t_base b, t_pos pos)
{
	t_pos	p;

	p.x = pos.x * b.i.x + pos.y * b.j.x
			+ pos.z * b.k.x + b.o.x;
	p.y = pos.x * b.i.y + pos.y * b.j.y
			+ pos.z * b.k.y + b.o.y;
	p.z = pos.x * b.i.z + pos.y * b.j.z
			+ pos.z * b.k.z + b.o.z;
	return (p);
}
