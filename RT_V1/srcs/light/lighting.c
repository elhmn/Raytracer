/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:38:45 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 21:47:04 by bmbarga          ###   ########.fr       */
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

	s = get_sColor(0, 0, 0);
	m = NULL;
	d = pos_norme(l);
	d = 1;//pow(d, 2);
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
			
//			s.r = m->kd * (light->I.Id.r) * prod;
//			s.g = m->kd * (light->I.Id.g) * prod;
//			s.b = m->kd * (light->I.Id.b) * prod;
//				put_var_dbl("s.r", s.r); //Debug
//				put_var_dbl("s.g", s.g); //Debug
//				put_var_dbl("s.b", s.b); //Debug
		}
	}
/*	(void)s;
	(void)l;
	(void)n;
	(void)light;
*/
	return (s);
}
