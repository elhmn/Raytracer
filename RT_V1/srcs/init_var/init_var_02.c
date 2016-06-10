#include "libft.h"
#include "check_errors.h"
#include "put_var.h"
#include "object.h"
#include "rt.h"
#include <mlx.h>
#include <stdlib.h>

void	init_ray(t_ray *ray)
{
	if (ray)
	{
		set_pos(&(ray->camPos), 0, 0, 0);
		set_pos(&(ray->spPos), 0, 0, 0);
		ray->col = 0;
	}
}

void	init_camera_base(t_camera *cam, t_base *space)
{
	t_base	*base;

	base = NULL;
	if (cam && space)
	{
		base =  &(cam->space);
		set_pos(&(base->o), space->o.x, space->o.y,
		space->o.z - (cam->dist + SAFE_DIST));
		set_pos(&(base->i), base->o.x + 1, base->o.y, base->o.z);

		set_pos(&(base->j), base->o.x, base->o.y + 1, base->o.z);

		set_pos(&(base->k), base->o.x, base->o.y, base->o.z + 1);
	}
}

void	init_objs(t_list **objs)
{
	t_dataSphere	*data;
	t_pos			pos;

	//get_sphereData()
	if (!(data = (t_dataSphere*)malloc(sizeof(t_dataSphere))))
		check_errors(MALLOC, "init_var_02.c", "data");
	data->radius = 20;
	set_pos(&pos, 0, 0, 0);

	//Load objects properties from a file
	//create objects
	//init objects
	//add objects to list

	if (objs)
	{
		if (!(*objs = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "init_var_02.c", "objs");
		(*objs)->content = new_obj(SPHERE, (void*)data, pos);
		if (!(*objs)->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj((*objs)->content);
	}
	ft_putendl("init_objs called"); //Debug
}
