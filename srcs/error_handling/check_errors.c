/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:08:52 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:09:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "check_errors.h"

static void		fun_error_init(t_ferr *f)
{
	if (f)
	{
		f[0] = f_malloc;
		f[1] = f_nul;
	}
	else
	{
		ft_putendl("Error : f :: check_errors.c :: set to NULL ");
		exit(-1);
	}
}

void			check_errors(int code, char *file_name, char *var_name)
{
	int		i;
	t_ferr	fun_error[NUL + 1];

	i = -1;
	fun_error_init(fun_error);
	ERR;
	ERR_VAR(var_name);
	ERR_SP;
	ERR_FILE(file_name);
	ERR_SP;
	while (++i < (NUL + 1))
		if (i == code)
			fun_error[i]();
	exit(0);
}
