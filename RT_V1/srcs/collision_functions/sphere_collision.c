#include "rt.h"
#include "object.h"
#include "put_var.h"
#include "check_errors.h"
#include "libft.h"

/*
** sphere collision function
*/

static int		is_collision(t_ray *ray, void *data, t_obj *obj, t_rt *rt)
{
	int			ret;
	float		h;
	t_camera	*cam;
	t_pos		u; //vector
	t_pos		v; //vector

	h = ;
	ret = -1;
	if (rt)
	{
		cam = rt->camera;
		if (cam)
		{

		}
	}
	calcul det;
	
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
		//determiner si il y a des points d'intersection
		//determiner si les points 
		d = 10;
	}
	ft_putendl("sphere collision"); //Debug
	return (d);
}
