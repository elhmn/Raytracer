#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"

void	pos_add_to_number(t_pos *pos, double nbr)
{
	if (pos)
	{
		pos->x += nbr;
		pos->y += nbr;
		pos->z += nbr;
	}
}

void	pos_sub_to_number(t_pos *pos, double nbr)
{
	if (pos)
	{
		pos->x -= nbr;
		pos->y -= nbr;
		pos->z -= nbr;
	}
}

void	pos_mult_to_number(t_pos *pos, double nbr)
{
	if (pos)
	{
		pos->x *= nbr;
		pos->y *= nbr;
		pos->z *= nbr;
	}
}

/*
** I know it does'nt make sense
*/

void	pos_div_to_number(t_pos *pos, double nbr)
{
	if (pos)
	{
		pos->x /= nbr;
		pos->y /= nbr;
		pos->z /= nbr;
	}
}
