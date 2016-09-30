/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:02:31 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 17:03:16 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_color.h"
#include "put_var.h"
#include "check_errors.h"

t_color				sColor_to_color(t_sColor s)
{
	t_color		c;

	c.r = LIMIT_COL(s.r * 255.);
	c.g = LIMIT_COL(s.g * 255.);
	c.b = LIMIT_COL(s.b * 255.);
	return (c);
}

t_sColor			color_to_sColor(t_color c)
{
	t_sColor		s;

	s.r = LIMIT_SCOL(c.r / 255.);
	s.g = LIMIT_SCOL(c.g / 255.);
	s.b = LIMIT_SCOL(c.b / 255.);
	return (s);
}

void			set_sColor(t_sColor *s, double r, double g, double b)
{
	s->r = LIMIT_SCOL(r);
	s->g = LIMIT_SCOL(g);
	s->b = LIMIT_SCOL(b);
}

t_sColor			get_sColor(double r, double g, double b)
{
	t_sColor	s;

	s.r = LIMIT_SCOL(r);
	s.g = LIMIT_SCOL(g);
	s.b = LIMIT_SCOL(b);
	return (s);
}

t_sColor			add_sColor(t_sColor a, t_sColor b)
{
	t_sColor	c;

	c.r = LIMIT_SCOL(a.r + b.r);
	c.g = LIMIT_SCOL(a.g + b.g);
	c.b = LIMIT_SCOL(a.b + b.b);
	return (c);
}
