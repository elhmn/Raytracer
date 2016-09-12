#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "rt.h"
#include "libft.h"

/*
** rotation de centre o et d'angle r en degre
*/

double	deg_to_rad(double r)
{
	return ((double)(r * M_PI) / (double)180.);
}

void	pos_rot_x(t_pos *src, t_pos o, double r)
{
	if (src && r)
	{
		r = deg_to_rad(r);
		src->y = src->y * cos(r) - src->z * sin(r) + o.y;
		src->z = src->y * sin(r) + src->z * cos(r) + o.z;
		src->x += o.x;
	}
}

void	pos_rot_y(t_pos *src, t_pos o, double r)
{
	if (src && r)
	{
		r = deg_to_rad(r);
		src->x = src->x * cos(r) - src->z * sin(r) + o.x;
		src->z = src->x * sin(r) + src->z * cos(r) + o.z;
		src->y += o.y;
	}
}

void	pos_rot_z(t_pos *src, t_pos o, double r)
{
	if (src && r)
	{
		r = deg_to_rad(r);
		src->x = src->x * cos(r) - src->y * sin(r) + o.x;
		src->y = src->x * sin(r) + src->y * cos(r) + o.y;
		src->z += o.z;
	}
}

void	pos_rot_xyz(t_pos *src, t_pos o, t_pos r)
{
	pos_rot_x(src, o, r.x);
	pos_rot_y(src, o, r.y);
	pos_rot_z(src, o, r.z);
}
