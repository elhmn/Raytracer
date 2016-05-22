#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include <math.h>

t_pos	pos_cross_product(t_pos p1, t_pos p2)
{
	t_pos	ret;

	ret.x = p1.y * p2.z - p1.z * p1.y;
	ret.y = p1.z * p2.x - p1.x * p2.z;
	ret.z = p1.x * p2.y - p1.y * p2.x;
	return (ret);
}

void	pos_copy(t_pos *dest, t_pos src)
{
	dest->x = src.x;
	dest->y = src.y;
	dest->z = src.z;
}

t_pos	pos_normalize(t_pos pos)
{
	pos_div_to_number(&pos, pos_norme(pos));
	return (pos);
}

double	pos_norme(t_pos pos)
{
	double	ret;

	ret = sqrt(pow(pos.x, 2) + pow(pos.y, 2) + pow(pos.z, 2));
	return (ret);
}

/*
** pos_vector allow you to have a vector with two points
*/

t_pos	pos_vector(t_pos p1, t_pos p2)
{
	t_pos	ret;
	
	pos_copy(&ret, p2);
	pos_sub_to_pos(&ret, p1);
	return (ret);
}
