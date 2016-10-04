/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:28:49 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 22:09:18 by bmbarga          ###   ########.fr       */
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
	t_list	*tmp;
	t_obj	*o;

	tmp = NULL;
	o = NULL;
	if (objs)
	{
		if (!(*objs = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "init_var_02.c", "objs");
		o = newSphere(get_pos(0, 300, 0), 100, get_color(100, 0, 0));
		(*objs)->content = o;
		if (!(*objs)->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.4, 0.4, 0.6);
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
		o = newPlane(get_pos(0, 0, 0), get_pos(0, -1, 0), get_color(80, 60, 0));
		tmp->content = o;
		if (!tmp->content)
			check_errors(MALLOC, "init_var_02.c", "objs->content");
		o->material = new_material(NULL, 0.4, 0.2, 0.6);
		tmp = ft_lstnew(NULL, 0);
		ft_lstadd_end(objs, tmp);
	}
}

void		init_lights(t_list **lights)
{
	if (lights)
	{
		if (!(*lights = ft_lstnew(NULL, 0)))
			check_errors(MALLOC, "lights", "init_var_02.c"); 
		(*lights)->content = new_omniLight(get_pos(0, 800, -400),
								get_inty(getI(0.5, 0.5, 0),
							getI(0.5, 0.5, 0.5)));
	}
}
