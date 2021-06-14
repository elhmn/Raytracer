/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_function_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:05:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 18:41:45 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include "normal_computation.h"
#include <stdlib.h>

t_obj	*new_sphere(t_pos pos, int radius, t_color col)
{
	t_obj			*sphere;
	t_data_sphere	*data;

	sphere = NULL;
	data = NULL;
	if (!(sphere = new_obj(SPHERE, pos, col)))
		check_errors(MALLOC, "sphere", "obj_function_01.c");
	if (!(data = (t_data_sphere*)malloc(sizeof(t_data_sphere))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->radius = radius;
	sphere->data = (void*)data;
	sphere->if_collision = sphere_collision;
	sphere->normal = sphere_normal;
	return (sphere);
}

t_obj	*new_plane(t_pos pos, t_pos v_normal, t_color col)
{
	t_obj				*plane;
	t_data_plane		*data;

	plane = NULL;
	data = NULL;
	if (!(plane = new_obj(PLANE, pos, col)))
		check_errors(MALLOC, "plane", "obj_function_01.c");
	if (!(data = (t_data_plane*)malloc(sizeof(t_data_plane))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	(void)v_normal;
	data->v_normal = v_normal;
	plane->data = (void*)data;
	plane->if_collision = plane_collision;
	plane->normal = plane_normal;
	return (plane);
}

/*
** build cylinder
*/

t_obj	*new_cylinder(t_pos pos, double r, double h, t_color col)
{
	t_obj				*cylinder;
	t_data_cylinder		*data;

	cylinder = NULL;
	data = NULL;
	if (!(cylinder = new_obj(CYLINDER, pos, col)))
		check_errors(MALLOC, "cylinder", "obj_function_01.c");
	if (!(data = (t_data_cylinder*)malloc(sizeof(t_data_cylinder))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->radius = r;
	data->height = h;
	cylinder->data = (void*)data;
	cylinder->if_collision = cylinder_collision;
	cylinder->normal = cylinder_normal;
	return (cylinder);
}

/*
** Cone creation :
**		- t_pos var is defined as (x = top, y = lim, z = ang)
*/

t_obj	*new_cone_std(t_pos pos, double top,
					double lim, t_color col)
{
	return (new_cone(pos, get_pos(top, lim, 10), col));
}

t_obj	*new_cone(t_pos pos, t_pos var, t_color col)
{
	t_obj				*cone;
	t_data_cone			*data;

	cone = NULL;
	data = NULL;
	if (var.z / 2. == 90)
		return (NULL);
	if (!(cone = new_obj(CONE, pos, col)))
		check_errors(MALLOC, "cone", "obj_function_01.c");
	if (!(data = (t_data_cone*)malloc(sizeof(t_data_cone))))
		check_errors(MALLOC, "data", "obj_function_01.c");
	data->top = var.x;
	data->lim = var.y;
	data->ang = var.z;
	cone->data = (void*)data;
	cone->if_collision = cone_collision;
	cone->normal = cone_normal;
	return (cone);
}
