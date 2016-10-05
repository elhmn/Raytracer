/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:13:08 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/06 00:04:58 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "rt.h"
# include "rt_color.h"
# include "material.h"

/*
** Objet structure
*/

enum				e_obj
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
	TORE,
	NONE
};

/*
** Objects data structures
*/

typedef	struct		s_data_sphere
{
	double		radius;
}					t_data_sphere;

typedef	struct		s_data_circle
{
	double		radius;
}					t_data_circle;

typedef struct		s_data_plane
{
	t_pos		v_normal;
}					t_data_plane;

typedef struct		s_data_cylinder
{
	double		height;
	double		radius;
}					t_data_cylinder;

typedef struct		s_data_cone
{
	double		top;
	double		lim;
	double		ang;
}					t_data_cone;

/*
** object structure
*/

typedef struct s_obj	t_obj;

struct				s_obj
{
	char		*name;
	int			id;
	int			type;
	void		*data;
	t_pos		rot;
	t_base		sp;
	t_base		o;
	t_color		col;
	t_s_color	s_col;
	t_material	*material;
	double		(*if_collision)(t_ray *ray, void *data,
				t_obj *obj, t_rt *rt);
	t_pos		(*normal)(t_obj *o, t_pos r, t_pos p);
};

/*
** obj_function_00.c
*/

t_obj				*new_obj(int type, t_pos pos, t_color col);

/*
** obj_function_01.c
*/

t_obj				*new_sphere(t_pos pos, int radius, t_color col);
t_obj				*new_plane(t_pos pos, t_pos v_normal, t_color col);
t_obj				*new_cylinder(t_pos pos, double r, double h, t_color col);
t_obj				*new_cone_std(t_pos pos, double top,
					double lim, t_color col);
t_obj				*new_cone(t_pos pos, t_pos var, t_color col);

/*
** obj_function_02.c
*/

void				rot_plane(t_obj *plane, t_pos r);
void				rot_camera(t_camera *cam, t_pos r);
void				rot_object(t_obj *obj, t_pos r);
void				rot_base(t_base *b, t_pos r);

/*
** objects collision functions
*/

/*
** 	collision_function/sphere_collision.c
*/

double				sphere_collision(t_ray *ray, void *data,
					t_obj *obj, t_rt *rt);

/*
** 	collision_function/plane_collision.c
*/

double				plane_collision(t_ray *ray, void *data,
					t_obj *obj, t_rt *rt);

/*
** 	collision_function/cylinder_collision.c
*/

double				cylinder_collision(t_ray *ray, void *data,
					t_obj *obj, t_rt *rt);

/*
** 	collision_function/cone_collision.c
*/

double				cone_collision(t_ray *ray, void *data,
					t_obj *obj, t_rt *rt);

/*
** obj_move_00.c
*/

void				move_base(t_base *b, t_pos pos);
void				move_camera(t_camera *c, t_pos pos);
void				move_obj(t_obj *o, t_pos pos);
#endif
