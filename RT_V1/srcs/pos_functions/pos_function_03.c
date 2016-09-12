#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"

/*
** rotation de centre o et d'angle r en degre
*/

void	pos_rot_x(t_pos o, double r)
{
	(void)o;
	(void)r;
}

void	pos_rot_y(t_pos o, double r)
{
	(void)o;
	(void)r;
}

void	pos_rot_z(t_pos o, double r)
{
	(void)o;
	(void)r;
}

void	pos_rot_xyz(t_pos o, double rx, double ry, double rz)
{
	pos_rot_x(o, rx);
	pos_rot_y(o, ry);
	pos_rot_z(o, rz);
}
