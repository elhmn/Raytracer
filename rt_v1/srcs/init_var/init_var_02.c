/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:28:49 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/02 21:35:17 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "check_errors.h"
#include "put_var.h"
#include "object.h"
#include "rt.h"
#include "light.h"
#include "rt_color.h"
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

void	init_objs(t_list **objs)
{
	//Load objects properties from a file
	//create objects
	//init objects
	//add objects to list
	t_list	*tmp;
	t_obj	*o;

	tmp = NULL;
	(void)o;
	if (objs)
	{
		if (!(*objs = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "init_var_02.c", "objs");
		(*objs)->content = o = newSphere(get_pos(0, 1100, 0), 200, get_color(0, 100, 0));
		if (!(*objs)->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
	
		o->material = new_material(NULL, 0.5, 0.3, 0.5);
	
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newSphere(get_pos(0, 1500, 1000), 1000, get_color(100, 0, 100));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.5, 0.3, 0.3);
///*
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newSphere(get_pos(100, 1120, 0), 150, get_color(100, 0, 100));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.5, 0.3, 0.3);
//*/		
//*
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newSphere(get_pos(-100, 1120, 0), 150, get_color(0, 100, 100));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.5, 0.3, 0.3);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newSphere(get_pos(-400, 0, 0), 150, get_color(100, 100, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.5, 0.7, 0.3);
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newSphere(get_pos(-900, 0, 0), 150, get_color(100, 100, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.5, 0.7, 0.3);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newSphere(get_pos(400, 0, 0), 150, get_color(100, 100, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.5, 0.7, 0.3);
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newSphere(get_pos(900, 0, 0), 150, get_color(100, 100, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.5, 0.7, 0.3);
//*/

/*
** Plane Init
*/

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newPlane(get_pos(0, 0, 0), get_pos(0, -1, 0), get_color(20, 20, 20));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.3, 0.2, 0.6);
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);

///*

		tmp->content = o = newPlane(get_pos(0, 0, 0), get_pos(0, 1, 0), get_color(20, 20, 20));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.3, 0.1, 0.6);
		rot_plane(tmp->content, get_pos(90, 0, 90));
		pos_add_to_pos(&(o->sp.o), get_pos(0, 0, 1000)); //Debug

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newPlane(get_pos(0, 0, 0), get_pos(0, -1, 0), get_color(90, 50, 20));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.3, 0.1, 0.6);
		rot_plane(tmp->content, get_pos(0, 0, 90));
		pos_add_to_pos(&(o->sp.o), get_pos(1500, 0, 0)); //Debug

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newPlane(get_pos(0, 0, 0), get_pos(0, 1, 0), get_color(70, 20, 20));
		o->material = new_material(NULL, 0.1, 0.1, 0.2);
		
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		rot_plane(tmp->content, get_pos(0, 0, 90));
		pos_add_to_pos(&(o->sp.o), get_pos(-1500, 0, 0)); //Debug

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newCylinder(get_pos(0, 0, 0), 50, -1, get_color(0, 150, 150));
		o->material = new_material(NULL, 0.3, 0.1, 0.2);
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		rot_object(tmp->content, get_pos(0, 0, 0)); //Debug
//*/

/*
**	Cylinder creation
*/
//		/*
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(0, 0, 100));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.3, 0.5, 0.6);
		rot_object(tmp->content, get_pos(90, 0, -45)); //Debug
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(0, 60, 150));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.3, 0.5, 0.6);
		rot_object(tmp->content, get_pos(90, 0, 45)); //Debug

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(150, 0, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.3, 0.5, 0.6);
		rot_object(tmp->content, get_pos(90, 0, 90)); //Debug
		
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newCylinder(get_pos(0, 0, 0), 30, 0, get_color(80, 60, 0));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.3, 0.5, 0.6);
		rot_object(tmp->content, get_pos(-90, 0, 0)); //Debug
//	*/
/*
**	Cone creation
*/
	/*
	*/
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newCone_std(get_pos(-1200, 0, 500), 1000, -1, get_color(150, 100, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.2, 0.5, 0.5);

		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		tmp->content = o = newCone_std(get_pos(1200, 0, 500), 1000, -1, get_color(150, 100, 255));
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.2, 0.5, 0.5);
	}
	ft_putendl("init_objs called"); //Debug
}

void		init_lights(t_list **lights)
{
	t_list	*tmp;
	t_light	*l;

	(void)lights;
	(void)l;
	tmp = NULL;
	l = NULL;
	if (lights)
	{
		if (!(*lights = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "lights", "init_var_02.c"); 
		(*lights)->content = l = new_omniLight(get_pos(0, 300, -800),
								get_inty(getI(0.4, 0.4, 0.4),
								getI(0, 0.2, 0.2)));
///*		
		if (!(tmp = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "lights", "init_var_02.c"); 
		ft_lstadd_end(lights, tmp);
		tmp->content = l = new_omniLight(get_pos(-500, 700, 1000),
								get_inty(getI(0.2, 0, 0),
								getI(0.2, 0, 0)));
		
		if (!(tmp = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "lights", "init_var_02.c"); 
		ft_lstadd_end(lights, tmp);
		tmp->content = l = new_omniLight(get_pos(500, 700, -1000),
								get_inty(getI(0, 0.2, 0),
								getI(0, 0.2, 0)));
		
		if (!(tmp = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "lights", "init_var_02.c"); 
		ft_lstadd_end(lights, tmp);
		tmp->content = l = new_omniLight(get_pos(400, 300, -1000),
								get_inty(getI(0, 0.2, 0),
								getI(0, 0.2, 0)));
//*/
	}
}
