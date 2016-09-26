/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_function_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:05:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/26 13:07:20 by bmbarga          ###   ########.fr       */
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
	cylinder->rot = get_pos(0, 0, 0);
	cylinder->col = col;
	cylinder->ifCollision = cylinder_collision;
	init_base_self(&(cylinder->o));
	init_base_self(&(cylinder->sp));
	copy_pos(&(cylinder->sp.o), pos);
	return (cylinder);
}

/*
** Cone creation :
**		- t_pos var is defined as (x = top, y = lim, z = ang)
*/

t_obj	*newCone_std(t_pos pos, double top,
					double lim, t_color col)
{
	return (newCone(pos, get_pos(top, lim, 10), col));
}

t_obj	*newCone(t_pos pos, t_pos var, t_color col)
{
	t_obj				*cone;
	t_dataCone			*data;

	cone = NULL;
	data = NULL;
	if (var.z /  2. == 90)
		return (NULL);
	if (!(cone = (t_obj*)malloc(sizeof(t_obj))))
		check_errors(MALLOC, "cone", "obj_function_01.c");
	if (!(data = (t_dataCone*)malloc(sizeof(t_dataCylinder))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->top = var.x;
	data->lim = var.y;
	data->ang = var.z;
	cone->data = data;
	cone->type = CONE;
	cone->rot = get_pos(0, 0, 0);
	cone->col = col;
	cone->ifCollision = cone_collision;
	init_base_self(&(cone->o));
	init_base_self(&(cone->sp));
	copy_pos(&(cone->sp.o), pos);
	return (cone);
}
