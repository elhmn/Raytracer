#include "libft.h"
#include "check_errors.h"
#include "rt.h"
#include <mlx.h>
#include <stdlib.h>

void		init_ray(t_ray ***ray)
{
	(void)ray;
	if (ray)
	{
		if (!(*ray = (t_ray**)malloc(sizeof(t_ray))))
			check_errors(MALLOC, "init_var_00.c", "ray");
	}
	ft_putendl("init_ray called"); //Debug
}

void		init_base_self(t_base *b)
{
	b->o.x = 0;
	b->o.y = 0;
	b->o.z = 0;

	b->i.x = 1;
	b->i.y = 0;
	b->i.z = 0;
	
	b->j.x = 0;
	b->j.y = 1;
	b->j.z = 0;
	
	b->k.x = 0;
	b->k.y = 0;
	b->k.z = 1;
}

void		init_base_zero(t_base *b)
{
	b->o.x = 0;
	b->o.y = 0;
	b->o.z = 0;

	b->i.x = 0;
	b->i.y = 0;
	b->i.z = 0;
	
	b->j.x = 0;
	b->j.y = 0;
	b->j.z = 0;
	
	b->k.x = 0;
	b->k.y = 0;
	b->k.z = 0;
}

void		init_space(t_space **space)
{
	if (space)
	{
		if (!(*space = (t_space*)malloc(sizeof(t_space))))
			check_errors(MALLOC, "init_var_00.c", "space");
		init_base_self(&(space[0]->self));
		init_base_zero(&(space[0]->camera));
	}
	ft_putendl("init_space called"); //Debug
}
