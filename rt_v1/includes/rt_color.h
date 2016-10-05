/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:02:01 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/06 00:17:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_COLOR_H
# define RT_COLOR_H

# include "rt.h"

# define LIMIT_SCOL(x)	(x > 1 && x < 0) ? ((x > 1) ? 1 : 0) : x
# define LIMIT_COL(x)	(x > 255. && x < 0.) ? ((x > 255.) ? 255. : 0.) : x

/*
** sColor terms are limited between 0 and 1. s stands for scaled
*/

typedef struct		s_s_color
{
	double			r;
	double			g;
	double			b;
}					t_s_color;

/*
** rt_color.c
*/

t_color				s_color_to_color(t_s_color s);
t_s_color			color_to_s_color(t_color c);
t_s_color			get_s_color(double r, double g, double b);
void				set_s_color(t_s_color *s, double r, double g, double b);
t_s_color			add_s_color(t_s_color a, t_s_color b);
t_s_color			sub_s_color(t_s_color a, t_s_color b);

#endif
