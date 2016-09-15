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
	return ((double)((double)r * (double)M_PI) / (double)180.);
}

void	pos_rot_x(t_pos *src, t_pos o, double r)
{
	double	y;
	double	z;

	if (src && r)
	{
		y = src->y;
		z = src->z;
		r = RAD(r);
		src->y = y * cos(r) - z * sin(r) + o.y;
		src->z = y * sin(r) + z * cos(r) + o.z;
		src->x += o.x;
	}
}

void	pos_rot_y(t_pos *src, t_pos o, double r)
{
	double	z;
	double	x;

	if (src && r)
	{
		z = src->z;
		x = src->x;
		r = RAD(r);
		src->z = z * cos(r) - x * sin(r) + o.z;
		src->x = z * sin(r) + x * cos(r) + o.x;
		src->y += o.y;
	}
}

void	pos_rot_z(t_pos *src, t_pos o, double r)
{
	double	x;
	double	y;

	if (src && r)
	{
		x = src->x;
		y = src->y;
		r = RAD(r);
		src->x = x * cos(r) - y * sin(r) + o.x;
		src->y = x * sin(r) + y * cos(r) + o.y;
		src->z += o.z;
	}
}

void	pos_rot_xyz(t_pos *src, t_pos o, t_pos r)
{
	pos_rot_x(src, o, r.x);
	pos_rot_y(src, o, r.y);
	pos_rot_z(src, o, r.z);
}
