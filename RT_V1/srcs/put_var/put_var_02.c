/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:26:38 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/26 10:00:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include "object.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

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
