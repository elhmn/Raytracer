/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 15:26:38 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/25 15:26:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "check_errors.h"
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
