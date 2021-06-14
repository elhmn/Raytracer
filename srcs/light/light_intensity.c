/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_intensity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 12:37:55 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 12:18:28 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "put_var.h"
#include "rt_color.h"

t_s_color	get_i(double r, double g, double b)
{
	t_s_color	s;

	s.r = LIMIT_SCOL(r);
	s.g = LIMIT_SCOL(g);
	s.b = LIMIT_SCOL(b);
	return (s);
}

t_inty		get_inty(t_s_color id, t_s_color is)
{
	t_inty		i;

	i.id = id;
	i.is = is;
	return (i);
}

void		inty_copy(t_inty *d, t_inty s)
{
	d->id = s.id;
	d->is = s.is;
}
