#include "libft.h"
#include "rt.h"
#include "put_var.h"
#include "check_errors.h"
#include <stdio.h>
#include <stdlib.h>

void	put_ray(t_ray ray)
{
	ft_putstr("camPos : ");
	put_pos(ray.camPos);
	ft_putstr("spPos : ");
	put_pos(ray.spPos);
	ft_putstr("col :");
	ft_putnbr(ray.col);
	ft_putendl("");
}

void	put_sphere(t_dataSphere *data)
{
	t_dataSphere *sp;

	sp = (t_dataSphere*)data;
	if (sp)
	{
		ft_putstr("radius =  [");
		ft_putdbl(sp->radius);
		ft_putendl("");
	}
}

void	put_type(int type)
{
	if (type == SPHERE)
		ft_putstr("Sphere");
	else
		ft_putstr("Unknown");
}

void	put_obj(void *obj)
{
	t_obj		*o;

	o = (t_obj*)obj;
	if (o)
	{
		ft_putstr("Obj : ");
		put_type(o->type);
		ft_putendl(" {\n");
		ft_putstr("camPos -> ");
		put_pos(o->camPos);
		ft_putstr("spPos -> ");
		put_pos(o->spPos);
		//put Data for each type //Debug
		if (o->type == SPHERE)
			put_sphere(o->data);
		ft_putendl("\n}\n");
	}
}
