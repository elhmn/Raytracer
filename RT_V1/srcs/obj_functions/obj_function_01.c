/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_function_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:05:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 20:45:40 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include "normal_computation.h"
#include <stdlib.h>

t_obj	*newSphere(t_pos pos, int radius, t_color col)
{
	t_obj			*sphere;
	t_dataSphere	*data;

	sphere = NULL;
	data = NULL;
	if(!(sphere = new_obj(SPHERE, pos, col)))
		check_errors(MALLOC, "sphere", "obj_function_01.c");
	if (!(data = (t_dataSphere*)malloc(sizeof(t_dataSphere))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->radius = radius;
	sphere->data = (void*)data;
	sphere->ifCollision = sphere_collision;
	sphere->normal = sphere_normal;
	return (sphere);
}

t_obj	*newPlane(t_pos pos, t_pos v_normal, t_color col)
{
	t_obj			*plane;
	t_dataPlane		*data;

	plane = NULL;
	data = NULL;
	if (!(plane = new_obj(PLANE, pos, col)))
		check_errors(MALLOC, "plane", "obj_function_01.c");
	if (!(data = (t_dataPlane*)malloc(sizeof(t_dataPlane))))
			check_errors(MALLOC, "data", "obj_function_01.c");
	(void)v_normal;
	data->v_normal = v_normal;//get_pos(0, 1, 0);//v_normal;
	plane->data = (void*)data;
	plane->ifCollision = plane_collision;
	plane->normal = plane_normal;
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
	if (!(cylinder = new_obj(CYLINDER, pos, col)))
		check_errors(MALLOC, "cylinder", "obj_function_01.c");
	if (!(data = (t_dataCylinder*)malloc(sizeof(t_dataCylinder))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->radius = r;
	data->height = h;
	cylinder->data = (void*)data;
	cylinder->ifCollision = cylinder_collision;
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
	if (!(cone = new_obj(CONE, pos, col)))
		check_errors(MALLOC, "cone", "obj_function_01.c");
	if (!(data = (t_dataCone*)malloc(sizeof(t_dataCone))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->top = var.x;
	data->lim = var.y;
	data->ang = var.z;
	cone->data = (void*)data;
	cone->ifCollision = cone_collision;
	return (cone);
}
