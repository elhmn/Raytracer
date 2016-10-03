/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:13:08 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 02:58:53 by bmbarga          ###   ########.fr       */
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

enum		e_obj
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

	char		*name;
	int			id;

	int			type;
	void		*data;
	t_pos		rot;

	/*
	** o base is origin base expressed with obj base
	*/

	t_base		sp;
	t_base		o;
	t_color		col;
	t_sColor	sCol;
	t_material	*material;

	/*
	** functions
	*/

	double		(*ifCollision)(t_ray *ray, void *data, t_obj *obj, t_rt *rt);
	t_pos		(*normal)(t_obj *o, t_pos r, t_pos p);

	/*
	** Later i want each object to have their own
	** 3D base vector like when as mod1 objects
	*/
};

/*
** obj_function_00.c
*/

t_obj			*new_obj(int type, t_pos pos, t_color col);

/*
** obj_function_01.c
*/

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

/*
** obj_move_00.c
*/

void			move_base(t_base *b, t_pos pos);
void			move_camera(t_camera *c, t_pos pos);
void			move_obj(t_obj *o, t_pos pos);
#endif
