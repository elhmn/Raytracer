#include <stdlib.h>
#include "libft.h"
#include <mlx.h>
#include "rt.h"

void	set_pos(t_pos *pos, double x, double y, double z)
{
	if (pos)
	{
		pos->x = x;
		pos->y = y;
		pos->z = z;
	}
}
