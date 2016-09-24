/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:06:52 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/24 18:29:24 by bmbarga          ###   ########.fr       */
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
**	-rotation d'angle r des (u, v, w) dans le repere A
**	-rotation d'angle -r des (i, j, k) dans B
*/

/*
static t_pos		get_trans_pos(t_pos var, t_base b,
					double o, double p)
{
	t_pos	e;

	e.z = (p * (var.x * b.i.y - var.y * b.i.x)
			+ o * (var.z * b.i.x - var.x * b.i.z))
			/ (p * (b.i.y * b.k.x - b.i.x * b.k.y)
			+ o * (b.i.x * b.k.z - b.i.z * b.k.x));
	e.y = (var.x * b.i.y - var.y * b.i.x
			+ e.z * (b.i.x * b.k.y - b.i.y * b.k.x))
			/ o;
	e.x = (var.x - e.y * var.x - e.z * b.k.x)
			/ b.i.x;
	return (e);
}

static t_base		get_a_from_b(t_base a, t_base b)
{
	t_base	e;
	double	o;
	double	p;
	
	o = b.i.y * b.j.x - b.i.x * b.j.y;
	p = b.i.z * b.j.x - b.i.x * b.j.z;
	e.i = get_trans_pos(a.i, b, o, p);
	e.j = get_trans_pos(a.j, b, o, p);
	e.k = get_trans_pos(a.k, b, o, p);
	return (e);
}
*/

t_pos		transform(t_base a, t_base b, t_pos pos, t_pos rot)
{
	t_pos	p;
	t_base	e;

	e = a;
	pos_mult_to_number(&rot, -1);
	rot_base(&e, rot);
//	e = get_a_from_b(a, b);
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

/*
void				test_transform(void) //Debug function
{
	t_base		a;
	t_base		b;
	t_base		e;
	t_pos		m;
	t_pos		mp;

	init_base_self(&a);
	init_base_self(&b);

	//set base a
	copy_pos(&(a.i), get_pos(1, 0, 0));
	copy_pos(&(a.j), get_pos(0, 1, 0));
	copy_pos(&(a.k), get_pos(0, 0, 1));
	
	//set base b
	copy_pos(&(b.o), get_pos(1, 1, 1));
	copy_pos(&(b.i), get_pos(0, 0, 1));
	copy_pos(&(b.j), get_pos(0, 1, 0));
	copy_pos(&(b.k), get_pos(-1, 0, 0));

	//set m
	copy_pos(&m, get_pos(2, 2, 1));

	//run
	e = get_a_from_b(a, b);
	mp = transform(a, b, m);
	mp = transform_rev(b, mp);

	ft_putstr("new base a -> "); //Debug
	put_base(a); //Debug
	ft_putendl(""); //Debug

	ft_putstr("new base b -> "); //Debug
	put_base(b); //Debug
	ft_putendl(""); //Debug

	ft_putstr("new base e -> "); //Debug
	put_base(e); //Debug
	ft_putendl(""); //Debug

	ft_putstr("m -> "); //Debug
	put_pos(m);  //Debug
	ft_putendl(""); //Debug

	ft_putstr("m' -> "); //Debug
	put_pos(mp);  //Debug
	ft_putendl(""); //Debug
}
*/
