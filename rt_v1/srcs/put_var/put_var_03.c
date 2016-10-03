/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var_03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 15:02:26 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/02 21:38:34 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include "object.h"
#include "put_var.h"
#include "material.h"
#include <mlx.h>
#include <stdlib.h>

void		put_material(t_material m)
{
	ft_putstr("material: \n{\n");
	ft_putstr("name = ");
	ft_putendl(m.name);
	put_var_dbl("ka", m.ka);
	put_var_dbl("kd", m.kd);
	put_var_dbl("ks", m.ks);
	ft_putstr("}\n");
}

void		start_block(char *str)
{
	ft_putstr(str);
	ft_putendl(" 			loading...");
}

void		end_block(char *str)
{
	ft_putstr(str);
	ft_putendl("			OK");
}
