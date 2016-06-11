#include <mlx.h>
#include <stdlib.h>
#include "check_errors.h"
#include "libft.h"
#include "rt.h"
#include "put_var.h"

static void	rt_check_error(t_rt *rt)
{
	if (!rt)
		check_errors(NUL, "raytracer.c", "rt");
	if (!rt->screen)
		check_errors(NUL, "raytracer.c", "rt->screen");
	if (!rt->objs)
		check_errors(NUL, "raytracer.c", "rt->objs");
	if (!rt->ray)
		check_errors(NUL, "raytracer.c", "rt->ray");
}

static int	get_distance(t_ray *r, t_obj *obj, t_rt *rt)
{
	int		d;

	d = -1;
	if (obj != NULL)
	{
		if (obj->ifCollision)
			d = obj->ifCollision(r, obj->data, obj, rt);
	}
	return (d);
}

static void	rt_get_ray_color(t_ray *r, t_list *o, t_rt *rt)
{
	t_list	*list;
	t_obj	*obj;
	float	ret;
	float	d;

	list = o;
	d = 3.402823e+38;
//	pour chaque objet
//	set distance to inf ou max float
	while (list != NULL)
	{
		obj = (t_obj*)list->content;
		if (d > (ret = get_distance(r, obj, rt))
			&& ret >= 0)
		{
			r->col = obj->col;
		}
		else if (ret < 0)
		{
			r->col = NULL; // replace NULL by black
		}
		// if prev_distance < distance
		// ray colored as the object
		//determine color with more RT algorithms
		list = list->next;
	}
}

static void	rt_set_ray_pos(int incX, int incY, t_ray *r, t_rt *rt)
{
	int		pX;
	int		pY;
	double	x;
	double	y;
	double	z;
	t_pos	*c;

	if (!r)
		check_errors(NUL, "raytracer.c", "r");
	c = &(rt->camera->space.o);
	pX = rt->screen->pixelWidth;
	pY = rt->screen->pixelHeight;

	x = c->x - ((pX * (rt->screen->resX + 1)) / 2.) + incX * pX;
	y = c->y + ((pY * (rt->screen->resY - 1)) / 2.) + incY * pY;
	z = c->z + rt->camera->dist;
	set_pos(&(r->camPos), incX, incY, c->z);
	set_pos(&(r->spPos), x, y, z);
}

void		raytracer(t_rt *rt)
{
	int		i;
	int		j;
	t_ray	**r;
	t_list	*o;

	i = -1;
	rt_check_error(rt);
	r = rt->ray;
	o = rt->objs;
	(void)o;
	//pour chaque rayon
	while (++i < rt->screen->resY)
	{
		j = -1;
		while (++j < rt->screen->resX)
		{
			rt_set_ray_pos(j, i, r[i] + j, rt);
//			if (i == 0) //Debug
//				put_ray(r[i][j]); //Debug
			rt_get_ray_color(r[i] + j, o, rt);
		}
	}
	ft_putendl("raytracer");
}
