#ifndef OBJECT_H
# define OBJECT_H

# include "rt.h"

/*
** Objet structure
*/

enum		e_type
{
	CIRCLE,
	SPHERE,
	PLANE,
	SQUARE,
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

	t_pos		camPos;
	t_pos		spPos;
	t_color		col;

	/*
	** functions
	*/

	double		(*ifCollision)(t_ray *ray, void *data, t_obj *obj, t_rt *rt);
};

/*
** obj_function_00.c
*/

void			*new_obj(int type, void *data, t_pos spPos, t_color col);

/*
** obj_function_01.c
*/

t_obj			*newSphere(t_pos spPos, int radius, t_color col);


/*
** objects collision functions
*/

/*
** 		collision_function/sphere_collision.c
*/

double			sphere_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt);

#endif
