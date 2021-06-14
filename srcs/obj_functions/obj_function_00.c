/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_function_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:05:39 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:36:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include "material.h"
#include "rt_color.h"
#include <stdlib.h>

/*
** this function has to be code properly or deleted
*/

t_obj	*new_obj(int type, t_pos pos, t_color col)
{
	t_obj		*obj;

	obj = NULL;
	if (!(obj = (t_obj*)malloc(sizeof(t_obj))))
		check_errors(MALLOC, "obj", "obj_function_00.c");
	obj->type = type;
	obj->if_collision = NULL;
	obj->normal = NULL;
	obj->material = NULL;
	obj->data = NULL;
	obj->rot = get_pos(0, 0, 0);
	obj->col = col;
	obj->s_col = get_s_color(0, 0, 0);
	obj->s_col = color_to_s_color(obj->col);
	init_base_self(&(obj->o));
	init_base_self(&(obj->sp));
	copy_pos(&(obj->sp.o), pos);
	return (obj);
}
