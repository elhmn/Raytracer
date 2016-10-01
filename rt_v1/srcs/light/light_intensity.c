/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 12:37:55 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 16:21:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "put_var.h"
#include "rt_color.h"

t_sColor	getI(double r, double g, double b)
{
	t_sColor	s;

	s.r = LIMIT_SCOL(r);
	s.g = LIMIT_SCOL(g);
	s.b = LIMIT_SCOL(b);
	return (s);
}

t_inty		get_inty(t_sColor Id, t_sColor Is)
{
	t_inty		I;

	I.Id = Id;
	I.Is = Is;
	return (I);
}

void		inty_copy(t_inty *d, t_inty s)
{
	d->Id = s.Id;
	d->Is = s.Is;
}
