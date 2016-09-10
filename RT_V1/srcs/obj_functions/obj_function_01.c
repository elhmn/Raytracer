#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include <stdlib.h>

t_obj	*newSphere(t_pos spPos, int radius, t_color col)
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
	set_pos(&(sphere->spPos), spPos.x, spPos.y, spPos.z);
	set_pos(&(sphere->camPos), 0, 0, 0);
	return (sphere);
}

t_obj	*newPlane(t_pos spPos, t_pos v_normal, t_color col)
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
	plane->ifCollision = NULL;//plane_collision;
	set_pos(&(plane->spPos), spPos.x, spPos.y, spPos.z);
	set_pos(&(plane->camPos), 0, 0, 0);
	return (plane);
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
