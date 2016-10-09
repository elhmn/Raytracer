/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:38:45 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 23:06:22 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "rt_color.h"
#include "light.h"
#include "material.h"
#include "object.h"
#include "put_var.h"
#include <math.h>
#include <stdlib.h>
#include "check_errors.h"

t_s_color	diffuse_light(t_light *light, t_obj *o, t_pos l, t_pos n)
{
	t_s_color	s;
	t_material	*m;
	double		prod;
	double		d;

	d = 1;
	m = NULL;
	s = get_s_color(0, 0, 0);
	l = pos_normalize(l);
	if (light && o)
	{
		m = o->material;
		if (m)
		{
			prod = pos_dot_product(l, n);
			s.r = ABS(m->kd * (light->inty.id.r / d) * prod);
			s.g = ABS(m->kd * (light->inty.id.g / d) * prod);
			s.b = ABS(m->kd * (light->inty.id.b / d) * prod);
		}
	}
	return (s);
}

t_s_color	specular_light(t_light *light, t_obj *o, t_base b)
{
	t_pos		p;
	t_pos		l;
	t_pos		n;
	t_pos		cam;
	t_pos		v;

	t_s_color	s;
	t_material	*m;
	double		prod;

	p = b.o;
	l = pos_normalize(b.i);
	n = b.j;
	cam = b.k;

	m = NULL;
	s = get_s_color(0, 0, 0);
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

			s.r = ABS(m->ks * (light->inty.is.r) * prod);
			s.g = ABS(m->ks * (light->inty.is.g) * prod);
			s.b = ABS(m->ks * (light->inty.is.b) * prod);		
		}
	}
	return (s);
}

int		enlightened(t_rt *rt, t_obj* o, t_pos p, t_pos ld, t_pos lo)
{
	t_ray	*r;
	t_list	*list;
	t_obj	*obj;
	double	d;

	list = rt->objs;
	if (!(r = (t_ray*)malloc(sizeof(t_ray))))
		check_errors(NUL, "raytracer.c", "r");
	r->ro = p;
	r->pos = lo;
	r->rd = pos_normalize(ld);
	while (list != NULL)
	{
		obj = (t_obj*)list->content;
		if (obj && obj != o
				&& (d = get_distance(r, obj, rt)) >= 0)
		{
			if (d <= pos_norme(pos_vector(p, lo)))
			{
				free(r);
				return (0);
			}
		}
		list = list->next;
	}
	free(r);
	return (1);
}

