/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_function_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:05:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/24 18:56:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include <stdlib.h>

t_obj	*newSphere(t_pos pos, int radius, t_color col)
{
	t_obj			*sphere;
	t_dataSphere	*data;

	sphere = NULL;
	data = NULL;
	if(!(sphere = (t_obj*)malloc(sizeof(t_obj))))
		check_errors(MALLOC, "sphere", "obj_function_01.c");
	if (!(data = (t_dataSphere*)malloc(sizeof(t_dataSphere))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->radius = radius;
	sphere->data = (void*)data;
	sphere->type = SPHERE;
	sphere->col = col;
	sphere->ifCollision = sphere_collision;
	init_base_self(&(sphere->sp));
	set_pos(&(sphere->sp.o), pos.x, pos.y, pos.z);
	return (sphere);
}

t_obj	*newPlane(t_pos pos, t_pos v_normal, t_color col)
{
	t_obj			*plane;
	t_dataPlane		*data;

	plane = NULL;
	data = NULL;
	if (!(plane = (t_obj*)malloc(sizeof(t_obj))))
		check_errors(MALLOC, "plane", "obj_function_01.c");
	if (!(data = (t_dataPlane*)malloc(sizeof(t_dataPlane))))
			check_errors(MALLOC, "data", "obj_function_01.c");
	data->v_normal = v_normal;
	plane->data = (void*)data;
	plane->type = PLANE;
	plane->col = col;
	plane->ifCollision = plane_collision;
	init_base_self(&(plane->sp));
	copy_pos(&(plane->sp.o), pos);
	return (plane);
}

/*
** build cylinder
*/

t_obj	*newCylinder(t_pos pos, double r, double h, t_color col)
{
	t_obj				*cylinder;
	t_dataCylinder		*data;

	cylinder = NULL;
	data = NULL;
	if (!(cylinder = (t_obj*)malloc(sizeof(t_obj))))
		check_errors(MALLOC, "cylinder", "obj_function_01.c");
	if (!(data = (t_dataCylinder*)malloc(sizeof(t_dataCylinder))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->radius = r;
	data->height = h;
	cylinder->data = data;
	cylinder->type = CYLINDER;
	cylinder->col = col;
	cylinder->ifCollision = cylinder_collision;
	init_base_self(&(cylinder->o));
	init_base_self(&(cylinder->sp));
	copy_pos(&(cylinder->sp.o), pos);
	return (cylinder);
}

/*
** function a ameliorer (function below)
*/

void	deleteObj(t_obj **obj)
{
	ft_putendl("i delete object"); //DEBUG
	if ((*obj) && (*obj)->type == SPHERE)
	{
		free((*obj)->data);
		(*obj)->data = NULL;
		free(*obj);
		(*obj) = NULL;
	}
}
