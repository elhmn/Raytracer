#include "libft.h"
#include "rt.h"
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

//void	put_plane(t_planeData *data)
//{

//}

//void	put_obj(void *obj, int type, void *data)
//{
//	if (type == SPHERE)
//		put_sphere();
//	else if (type == CIRCLE)
//		put_circle();
//	else if (type == PLANE)
//		put_plane();
//}
