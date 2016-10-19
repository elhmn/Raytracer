/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_material.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:21:13 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/19 17:27:20 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "material.h"
#include "check_errors.h"
#include <stdlib.h>

/*
** material standard creation function
*/

t_material		*new_material(char *name, double ka, double ks, double kd)
{
	t_material		*m;

	m = NULL;
	if (!(m = (t_material*)malloc(sizeof(t_material))))
		check_errors(MALLOC, "m", "new_material");
	m->ka = LIMIT_COEF(ka);
	m->ks = LIMIT_COEF(ks);
	m->kd = LIMIT_COEF(kd);
	m->pow = 30.;
	m->name = name;
	return (m);
}

t_material		*new_material_pos(char *name, t_pos k, double pow)
{
	t_material	*m;

	m = NULL;
	if (!(m = new_material(name, k.x, k.y, k.z)))
		check_errors(MALLOC, "m", "new_material");
	m->pow = pow;
	return (m);
}

void			set_specular_power(t_material *m, double pow)
{
	if (m)
		m->pow = pow;
}
