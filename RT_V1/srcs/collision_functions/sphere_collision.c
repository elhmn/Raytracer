#include "rt.h"
#include "object.h"
#include "put_var.h"
#include "check_errors.h"
#include "libft.h"
#include <math.h>

/*
** sphere collision function
*/

static double	delta(t_pos e)
{
	return (pow(e.y, 2.) - (4. * e.x * e.z));
}

static double	getDist(t_pos e, double delta)
{
	double	d1;
	double	d2;
	double	q;
	double	rd;

	q = (2. * e.x);
	rd = sqrt(delta);
	d1 = (-1. * e.y - rd) / q;
	if (d1 > (d2 = (-1. * e.y + rd) / q))
		return (d2);
	return (d1);
}

static double		is_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt)
{
	double			ret;
	t_camera		*cam;
	t_pos			u; //vector
	t_dataSphere	*dat;
	t_pos			e;
	double			tmp;			

	ret = -1.;
	if (rt && data)
	{
		cam = rt->camera;
		dat = (t_dataSphere*)data;
		if (cam)
		{
			u = pos_vector(cam->space.o, ray->spPos);
			u = pos_normalize(u);
			e.x = pow(u.x, 2) + pow(u.y, 2) + pow(u.z, 2); // a
			e.y = -1. * 2. * (obj->spPos.x * u.x + obj->spPos.y * u.y + obj->spPos.z * u.z);// b
			e.z = pow(obj->spPos.x, 2) + pow(obj->spPos.y, 2) + pow(obj->spPos.z, 2) - pow(dat->radius, 2);// c
			if ((tmp = delta(e)) < 0.)
				ret = -1.;
			else if (tmp == 0.)
				ret = -1. * e.y / 2. * e.x;
			else
				ret = getDist(e, tmp);
			ft_putdbl(ret); //debug
			ft_putendl("");//debug
		}
	}
	return (ret);
}

float		sphere_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt)
{
	float			d;
	t_dataSphere	*dat;

	d = -1;
	dat = (t_dataSphere*)data;
	(void)rt;
	if (ray && dat && rt && obj)
	{
		is_collision(ray, data, obj, rt);
		//determiner si il y a des points d'intersection
		//determiner si les points 
		d = 10;
	}
//	ft_putendl("sphere collision"); //Debug
	return (d);
}
