#include "rt.h"
#include "object.h"

/*
** modifier la fonction show 
** et y ajouter la gestion
** de la taille des pixels = pixelRatio
*/

void	show(t_rt *rt)
{
	t_ray	**ray;
	int		i;
	int		j;
	int		w;
	int		h;

	ray = rt->ray;
	if (rt)
	{
		i = -1;
		w = rt->screen->resX;
		h = rt->screen->resY;
		while (++i < w)
		{
			j = -1;
			while (++j < h)
			{
				pixel_put_img(rt, i, j, ray[j][i].col);
			}
		}
	}
}
