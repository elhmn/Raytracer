#include "libft.h"
#include "rt.h"
#include "put_var.h"
#include "check_errors.h"
#include <stdio.h>
#include <stdlib.h>

void	put_ray(t_ray ray)
{
	ft_putstr("pos : ");
	put_pos(ray.pos);
	ft_putstr("col :");
	ft_putnbr(ray.col.color);
	ft_putendl("");
}

void	put_dataSphere(t_dataSphere *data)
{
	t_dataSphere *sp;

	sp = (t_dataSphere*)data;
	if (sp)
	{
		ft_putstr("radius =  [");
		ft_putdbl(sp->radius);
		ft_putendl("]");
	}
}

void	put_dataPlane(t_dataPlane *data)
{
	t_dataPlane	*pl;

	pl = (t_dataPlane*)data;
	if (pl)
	{
		ft_putstr("v_normal -> ");
		put_pos(pl->v_normal);
	}
}


void	put_type(int type)
{
	if (type == SPHERE)
		ft_putstr("Sphere");
	else if (type == PLANE)
		ft_putstr("Plane");
	else
		ft_putstr("Unknown");
}

/*
** put Data for each tyo->sp** clean that code to avoid if forest
*/

void	put_obj(void *obj)
{
	t_obj		*o;

	o = (t_obj*)obj;
	if (o)
	{
		ft_putstr("Obj : ");
		put_type(o->type);
		ft_putendl(" {\n");
		ft_putstr("pos -> ");
		put_pos(o->sp.o);
		ft_putstr("base \n{\n");
		put_base(o->sp);
		ft_putstr("}\n");
		if (o->type == SPHERE)
			put_dataSphere(o->data);
		if (o->type == PLANE)
			put_dataPlane(o->data);
		ft_putendl("\n}\n");
	}
}
