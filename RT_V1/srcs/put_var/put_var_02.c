/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:26:38 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 15:02:40 by bmbarga          ###   ########.fr       */
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

void	put_dataCone(t_dataCone *data)
{
	t_dataCone	*d;

	d = (t_dataCone*)data;
	(void)d;
	ft_putendl("put data Cone");
}

void	put_dataCylinder(t_dataCylinder *data)
{
	t_dataCylinder	*d;

	d = (t_dataCylinder*)data;
	(void)d;
	ft_putendl("put data Cone");
}

void	put_sColor(t_sColor s)
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
		ft_putstr("Ia : ");
		put_sColor(l->I.Ia);
		ft_putstr("Id : ");
		put_sColor(l->I.Id);
		ft_putstr("Is : ");
		put_sColor(l->I.Is);
		ft_putstr("}\n");
		ft_putendl("\n}\n");
	}
}
