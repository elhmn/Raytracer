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
	double	ret;
	double	d;

	list = o;
	d = 3.402823e+38;
	while (list != NULL)
	{
		obj = (t_obj*)list->content;
		if (d > (ret = get_distance(r, obj, rt))
			&& ret >= 0)
		{
			r->col = obj->col;
			d = ret;
		}
		// if prev_distance < distance
		// ray colored as the object
		//determine color with more RT algorithms
		list = list->next;
	}
}

//that fucking issue stands here
static void	rt_set_ray_pos(int incX, int incY, t_ray *r, t_rt *rt)
{
	int		pX;
	int		pY;
	t_pos	t; //tmp
	t_pos	c; //camera
	t_pos	u; //camera->i
	t_pos	v; //camera->j
	t_pos	w; //gaze direction

	if (!r)
		check_errors(NUL, "raytracer.c", "r");
	c = rt->camera->spPos;

	//set camera k i j with cross product
	//reshape pos function to let them give out put
	u = pos_normalize(rt->camera->u);
	v = pos_normalize(rt->camera->v);
	w = pos_normalize(rt->camera->w);
	pX = rt->screen->pixelWidth;
	pY = rt->screen->pixelHeight;
	pos_mult_to_number(&w, rt->camera->dist);
	pos_add_to_pos(&c, w);

	t = u;
	pos_mult_to_number(&t, - ((pX * (rt->screen->resX + 1)) / 2.) + incX * pX);
	pos_add_to_pos(&c, t);

	t = v;
	pos_mult_to_number(&t, ((pY * (rt->screen->resY - 1)) / 2.) - incY * pY);
	pos_add_to_pos(&c, t);

	set_pos(&(r->camPos), incX, incY, c.z);
	set_pos(&(r->spPos), c.x, c.y, c.z);
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
//	ft_putendl("raytracer"); //debug
}
