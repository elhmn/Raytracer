/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_omniLight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 12:20:40 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 14:14:29 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "check_errors.h"
#include "put_var.h"
#include <stdlib.h>

t_light				*new_omniLight(t_pos pos, t_inty I)
{
	t_light		*l;

	if ((l = newLight()))
	{
		l->type = OMNI;
		init_base_self(&(l->sp));
		copy_pos(&(l->sp.o), pos);
		l->volume = NULL;
		inty_copy(&(l->I), I);
	}
	return (l);
}
