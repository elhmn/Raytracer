/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:29:29 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/20 17:23:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_color.h"
#include "put_var.h"
#include "check_errors.h"

t_s_color			add_s_color(t_s_color a, t_s_color b)
{
	t_s_color	c;

	c.r = LIMIT_SCOL(a.r + b.r);
	c.g = LIMIT_SCOL(a.g + b.g);
	c.b = LIMIT_SCOL(a.b + b.b);
	return (c);
}

t_s_color			sub_s_color(t_s_color a, t_s_color b)
{
	t_s_color	c;

	c.r = LIMIT_SCOL(a.r - b.r);
	c.g = LIMIT_SCOL(a.g - b.g);
	c.b = LIMIT_SCOL(a.b - b.b);
	return (c);
}
