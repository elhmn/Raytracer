/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rotation_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:47:59 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 14:19:39 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "object.h"
#include "libft.h"
#include "check_errors.h"
#include "put_var.h"
#include <stdlib.h>

/*
** Plane rotation function
*/

void	rot_plane(t_obj *plane, t_pos r)
{
	t_dataPlane	*data;

	data = NULL;
	if (plane)
	{
		if (!(data = (t_dataPlane*)plane->data))
			check_errors(NUL, "plane->data", "obj_rotation_00.c");
		pos_rot_xyz(&(data->v_normal), plane->sp.o, r);
		pos_copy(&data->v_normal, pos_normalize(data->v_normal));
	}
}

/*
** Implement base rotation function 
*/

void	rot_object(t_obj *o, t_pos r)
{
	if (o)
	{
		rot_base(&(o->sp), r);
		pos_mult_to_number(&r, -1);
		init_base_self(&(o->o));
		rot_base(&o->o, r);
	}
}

void	rot_base(t_base *b, t_pos r)
{
	t_pos	*u;
	t_pos	*v;
	t_pos	*w;

	if (b)
	{
		u = &b->i;
		v = &b->j;
		w = &b->k;
		pos_rot_xyz(w, get_pos(0, 0, 0), r);
		pos_rot_xyz(u, get_pos(0, 0, 0), r);
		pos_rot_xyz(v, get_pos(0, 0, 0), r);
		*u = pos_normalize(*u);
		*v = pos_normalize(*v);
		*w = pos_normalize(*w);
	}
}

void	rot_camera(t_camera *cam, t_pos r)
{
	t_pos	*u;
	t_pos	*v;
	t_pos	*w;
	t_pos	e;

	if (cam)
	{
		u = &cam->sp.i;
		v = &cam->sp.j;
		w = &cam->sp.k;
		copy_pos(&e, cam->v_up);
		pos_rot_xyz(w, get_pos(0, 0, 0), r);
		pos_rot_xyz(u, get_pos(0, 0, 0), r);
		pos_rot_xyz(v, get_pos(0, 0, 0), r);
		*u = pos_normalize(*u);
		*v = pos_normalize(*v);
		*w = pos_normalize(*w);
	}
}
