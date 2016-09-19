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
		set_pos(&(ray->pos), 0, 0, 0);
	}
}

//a mettre au propre

void	init_objs(t_list **objs)
{
	//Load objects properties from a file
	//create objects
	//init objects
	//add objects to list

	t_list	*tmp;

	if (objs)
	{
		if (!(*objs = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "init_var_02.c", "objs");
		(*objs)->content = newSphere(get_pos(0, 0, 0), 200, get_color(255, 0, 0));
		if (!(*objs)->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj((*objs)->content);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(200, 0, 0), 150, get_color(255, 0, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(-200, 0, 0), 150, get_color(255, 255, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
	
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newPlane(get_pos(0, -80, 0), get_pos(0, -1, 0), get_color(0, 0, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		
	}
	ft_putendl("init_objs called"); //Debug
}
