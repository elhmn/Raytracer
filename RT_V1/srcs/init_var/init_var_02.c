/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:28:49 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/29 19:37:53 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ray->col.color = 0x00000000;
		set_color(&(ray->col));
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

	tmp = NULL;
	if (objs)
	{
		if (!(*objs = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "init_var_02.c", "objs");
		(*objs)->content = newSphere(get_pos(0, 400, 0), 200, get_color(255, 0, 0));
		if (!(*objs)->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj((*objs)->content);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(100, 220, 0), 150, get_color(255, 0, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(-100, 220, 0), 150, get_color(255, 255, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(-400, 0, 0), 150, get_color(255, 255, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(-900, 0, 0), 150, get_color(255, 255, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(400, 0, 0), 150, get_color(255, 255, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newSphere(get_pos(900, 0, 0), 150, get_color(255, 255, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);

/*
** Plane Init
*/

//		/*
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newPlane(get_pos(0, -80, 0), get_pos(0, -1, 0), get_color(50, 50, 50));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newPlane(get_pos(0, -400, 1000), get_pos(0, -1, 0), get_color(20, 20, 20));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		rot_plane(tmp->content, get_pos(90, 0, 0));
		//*/

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newCylinder(get_pos(0, 0, 0), 50, -1, get_color(0, 255, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		rot_object(tmp->content, get_pos(0, 0, 0)); //Debug
/*
**	Cylinder creation
*/
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(0, 0, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		rot_object(tmp->content, get_pos(90, 0, -45)); //Debug
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(0, 100, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		rot_object(tmp->content, get_pos(90, 0, 45)); //Debug
		put_obj(tmp->content);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(255, 0, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		rot_object(tmp->content, get_pos(90, 0, 90)); //Debug
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(125, 100, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		rot_object(tmp->content, get_pos(-90, 0, 0)); //Debug
		put_obj(tmp->content);
/*
**	Cone creation
*/
		/*
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newCone_std(get_pos(-800, 400, 500), 1000, 800, get_color(150, 100, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = newCone_std(get_pos(800, 0, 500), 1000, 500, get_color(150, 100, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		put_obj(tmp->content);
		*/
	}
	ft_putendl("init_objs called"); //Debug
}
