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

	sphere->type = SPHERE;
	sphere->data = (void*)data;
	sphere->col = col;
	sphere->ifCollision = sphere_collision;

//	sphere->spPos = spPos;
//	sphere->camPos = camPos;

	set_pos(&(sphere->spPos), spPos.x, spPos.y, spPos.z);
	set_pos(&(sphere->camPos), 0, 0, 0);
	return (sphere);
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
