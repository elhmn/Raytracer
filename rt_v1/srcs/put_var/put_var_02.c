/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:26:38 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:53:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include "object.h"
#include "put_var.h"
#include <mlx.h>
#include <stdlib.h>

void		put_var_dbl(char *var, double val)
{
	if (var)
	{
		ft_putstr(var);
		ft_putstr(" = ");
	}
	ft_putstr("[");
	ft_putdbl(val);
	ft_putendl("]");
}

void	put_data_cone(t_data_cone *data)
{
	t_data_cone	*d;

	d = (t_data_cone*)data;
	(void)d;
	ft_putendl("put data Cone");
}

void	put_data_cylinder(t_data_cylinder *data)
{
	t_data_cylinder	*d;

	d = (t_data_cylinder*)data;
	(void)d;
	ft_putendl("put data Cone");
}

void	put_s_color(t_s_color s)
{
	ft_putstr("(");
	ft_putdbl(s.r);
	ft_putstr(", ");
	ft_putdbl(s.g);
	ft_putstr(", ");
	ft_putdbl(s.b);
	ft_putstr(")");
	ft_putendl("");
}

void	put_light(t_light *l)
{
	if (l)
	{
		ft_putstr("Light : ");
		put_var_dbl("type", l->type);
		ft_putendl(" {\n");
		ft_putstr("pos -> ");
		put_pos(l->sp.o);
		ft_putstr("base \n{\n");
		put_base(l->sp);
		ft_putstr("}\n");
		ft_putendl("I : \n{\n");
		ft_putstr("id : ");
		put_s_color(l->inty.id);
		ft_putstr("Is : ");
		put_s_color(l->inty.is);
		ft_putstr("}\n");
		ft_putendl("\n}\n");
	}
}
