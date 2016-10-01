/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:02:01 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 17:34:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RT_COLOR_H
# define RT_COLOR_H

# include "rt.h"

# define LIMIT_SCOL(x) (x > 1 && x < 0) ? ((x > 1) ? 1 : 0) : x
# define LIMIT_COL(x) (x > 255. && x < 0.) ? ((x > 255.) ? 255. : 0.) : x

/*
** sColor terms are limited between 0 and 1. s stands for scaled
*/

typedef struct		s_sColor
{
	double			r;
	double			g;
	double			b;
}					t_sColor;

/*
** rt_color.c
*/

t_color				sColor_to_color(t_sColor s);
t_sColor			color_to_sColor(t_color c);
t_sColor			get_sColor(double r, double g, double b);
void				set_sColor(t_sColor *s, double r, double g, double b);
t_sColor			add_sColor(t_sColor a, t_sColor b);
t_sColor			sub_sColor(t_sColor a, t_sColor b);

#endif
