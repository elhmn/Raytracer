/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:38:45 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 14:06:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_color.h"
#include "light.h"
#include "material.h"
#include "object.h"
#include "put_var.h"
#include <math.h>

t_sColor	diffuse_light(t_light *light, t_obj *o, t_pos l, t_pos n)
{
	t_sColor	s;
	t_material	*m;
	double		prod;
	double		d;

	d = 1;
	m = NULL;
	s = get_sColor(0, 0, 0);
	l = pos_normalize(l);
	if (light && o)
	{
		m = o->material;
		if (m)
		{
			prod = pos_dot_product(l, n);
			s.r = ABS(m->kd * (light->I.Id.r / d) * prod);
			s.g = ABS(m->kd * (light->I.Id.g / d) * prod);
			s.b = ABS(m->kd * (light->I.Id.b / d) * prod);
		}
	}
	return (s);
}

t_sColor	specular_light(t_light *light, t_obj *o, t_base b)
{
	t_pos		p;
	t_pos		l;
	t_pos		n;
	t_pos		cam;
	t_pos		v;

	t_sColor	s;
	t_material	*m;
	double		prod;

	p = b.o;
	l = pos_normalize(b.i);
	n = b.j;
	cam = b.k;

	m = NULL;
	s = get_sColor(0, 0, 0);
	if (light && o)
	{
		m = o->material;
		if (m)
		{
			prod = pos_dot_product(l, n);
			pos_mult_to_number(&n, prod);
			pos_mult_to_number(&n, 2);
			pos_mult_to_number(&l, -1);
			pos_add_to_pos(&n, l);
			v = pos_normalize(pos_vector(p, cam));
			prod = pow(pos_dot_product(n, v), m->pow);

			s.r = ABS(m->ks * (light->I.Is.r) * prod);
			s.g = ABS(m->ks * (light->I.Is.g) * prod);
			s.b = ABS(m->ks * (light->I.Is.b) * prod);		
		}
	}
	return (s);
}
