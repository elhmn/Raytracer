/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_omni_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 12:22:32 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 12:23:00 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "check_errors.h"
#include "put_var.h"
#include <stdlib.h>

t_light				*new_omni_light(t_pos pos, t_inty i)
{
	t_light		*l;

	if ((l = new_light()))
	{
		l->type = OMNI;
		init_base_self(&(l->sp));
		copy_pos(&(l->sp.o), pos);
		l->volume = NULL;
		inty_copy(&(l->inty), i);
	}
	return (l);
}
