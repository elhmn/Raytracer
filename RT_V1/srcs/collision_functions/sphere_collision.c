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
	d2 = (-1. * e.y + rd) / q;
	ft_putstr("d1 = ");
	ft_putdbl(d1); //Debug
	ft_putendl("");
	ft_putstr("d2 = ");
	ft_putdbl(d2); //Debug
	ft_putendl("");
	ft_putendl("");
	ft_putendl("");
	if (d1 > d2)
		return (d2);
	return (d1);
}

static double		is_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt)
{
	double			ret;
	t_camera		*cam;
	t_pos			u; //vector
	t_pos			v; //vector
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
//			put_pos(u); //debug
			u = pos_normalize(u);
			v = pos_vector(cam->space.o, obj->spPos);
//			put_pos(u); //debug
			e.x = pos_dot_product(u, u); // a
//	ft_putstr("a = ");
//	ft_putdbl(e.x); //Debug
//	ft_putendl("");
			e.y = 2. * pos_dot_product(u, v);//b
//	ft_putstr("b = ");
//	ft_putdbl(e.y); //Debug
//	ft_putendl("");
			e.z = pos_dot_product(v, v) - pow(dat->radius, 2);// c
//	ft_putstr("c = ");
//	ft_putdbl(e.z); //Debug
//	ft_putendl("");
			if ((tmp = delta(e)) < 0.)
				ret = -1.;
			else if (tmp == 0.)
				ret = -1. * e.y / 2. * e.x;
			else
				ret = getDist(e, tmp);
//			ft_putdbl(tmp);//debug
//			ft_putendl("");//debug
			if (tmp == 0)
			{
				ft_putdbl(tmp); //debug
				ft_putendl("");//debug
			}
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
