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
	return (pow(e.y, 2) - (4. * e.x * e.z));
}

static double	getDist(t_pos e, double delta)
{
	double	d1;
	double	d2;
	double	q;
	double	rd;
	double	ret;

	q = (2. * e.x);
	rd = sqrt(delta);
	d1 = (-1. * e.y - rd) / q;
	d2 = (-1. * e.y + rd) / q;

	ret = d1;
	if (d1 > d2)
		ret = d2;
	return (ret);
}

//static t_pos		get_point(t_rt *rt, t_pos u, int d)
//{
//	t_pos		pos;
//	pos = rt->camera->o;
//	pos_mult_to_number(u, d);
//	return (pos_add_to_pos(&pos, u));
//}

static double		is_collision(t_ray *ray, t_dataSphere *data,
								t_obj *obj, t_rt *rt)
{
	double			ret;
	t_camera		*cam;
	t_pos			u;
	t_pos			v;
	t_pos			e;
	double			tmp;

	ret = -1.;
	if (rt && data)
	{
		cam = rt->camera;
		if (cam)
		{
			u = pos_vector(cam->spPos, ray->spPos);
			u = pos_normalize(u);
			v = pos_vector(obj->spPos, cam->spPos);
			e.x = pos_dot_product(u, u);
			e.y = 2. * pos_dot_product(u, v);
			e.z = pos_dot_product(v, v) - pow(data->radius, 2);
			if ((tmp = delta(e)) < 0.)
				ret = -1.;
			else if (tmp == 0.)
				ret = (-1. * e.y) / (2. * e.x);
			else
				ret = getDist(e, tmp);
		}
	}
	return (ret);
}

double		sphere_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt)
{
	double			d;
	t_dataSphere	*dat;

	d = -1;
	dat = (t_dataSphere*)data;
	if (ray && dat && rt && obj)
	{
		d = is_collision(ray, dat, obj, rt);
		//determiner si il y a des points d'intersection
		//determiner si les points 
	}
	return (d);
}
