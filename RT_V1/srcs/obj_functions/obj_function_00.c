/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_function_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:43:02 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/27 00:18:48 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include <stdlib.h>

/*
** this function has to be code properly or deleted
*/

void	*new_obj(int type, void	*data, t_pos pos, t_color col)
{
	t_obj		*obj;

	if (!(obj = (t_obj*)malloc(sizeof(t_obj))))
		check_errors(MALLOC, "obj", "obj_function_00.c");

	obj->ifCollision = NULL;
	if (type == SPHERE)
	{
		obj->type = SPHERE;
		obj->ifCollision = sphere_collision;
	}
	else if (type == PLANE)
	{
		obj->type = PLANE;
	}
	init_base_self(&(obj->sp));
	set_pos(&(obj->sp.o), pos.x, pos.y, pos.z);
	obj->data = data;
	obj->col = col;
	return ((void*)obj);
}
