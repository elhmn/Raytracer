/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:13:08 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/26 10:00:12 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "rt.h"

/*
** Objet structure
*/

enum		e_type
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

typedef	struct	s_dataSphere
{
	double		radius;
}				t_dataSphere;

typedef	struct	s_dataCircle
{
	double		radius;
}				t_dataCircle;

typedef struct	s_dataPlane
{
	t_pos		v_normal;
}				t_dataPlane;

typedef struct	s_dataCylinder
{
	double		height;
	double		radius;
}				t_dataCylinder;

typedef struct	s_dataCone
{
	double		top;
	double		lim;
	double		ang;
}				t_dataCone;

/*
** object structure
*/

typedef struct s_obj	t_obj;

struct	s_obj
{
	/*
	** attributs
	*/

	int			type;
	void		*data;
	t_pos		rot;

	t_base		sp;
	t_base		o;
	t_color		col;

	/*
	** functions
	*/

	double		(*ifCollision)(t_ray *ray, void *data, t_obj *obj, t_rt *rt);

	/*
	** Later i want each object to have their own
	** 3D base vector like when as mod1 objects
	*/
};

/*
** obj_function_00.c
*/

void			*new_obj(int type, void *data, t_pos pos, t_color col);

/*
** obj_function_01.c
*/

//double			get_d(t_pos n, t_pos p);
t_obj			*newSphere(t_pos pos, int radius, t_color col);
t_obj			*newPlane(t_pos pos, t_pos v_normal, t_color col);
t_obj			*newCylinder(t_pos pos, double r, double h, t_color col);
t_obj			*newCone_std(t_pos pos, double top,
							double lim, t_color col);
t_obj			*newCone(t_pos pos, t_pos var, t_color col);

/*
** obj_function_02.c
*/

void			rot_plane(t_obj *plane, t_pos r);
void			rot_camera(t_camera *cam, t_pos r);
void			rot_object(t_obj *obj, t_pos r);
void			rot_base(t_base *b, t_pos r);

/*
** objects collision functions
*/

/*
** 	collision_function/sphere_collision.c
*/

double			sphere_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt);

/*
** 	collision_function/plane_collision.c
*/

double			plane_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt);

/*
** 	collision_function/cylinder_collision.c
*/

double			cylinder_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt);

/*
** 	collision_function/cone_collision.c
*/

double			cone_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt);

#endif
