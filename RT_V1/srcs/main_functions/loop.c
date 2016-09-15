#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "put_var.h"
#include "check_errors.h"

//Debug
/*
static void	put_rays(t_ray **ray)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 50)
	{
		j = -1;
		while (++j < 50)
			put_ray(ray[i][j]);
	}
}
*/

void	loop(t_rt *rt)
{
//	ft_putendl("loop_hook enter"); //Debug
	if (rt)
	{
		raytracer(rt);
		show(rt);
//		put_rays(rt->ray);
		/* put mlx->img to window*/
		if (rt->env
			&& rt->env->mlx
			&& rt->env->win
			&& rt->env->img)
			mlx_put_image_to_window(rt->env->mlx, rt->env->win,
								rt->env->img, 0, 0);
		else
			check_errors(NUL, "loop.c", "rt->env struct");
		rt = NULL; //Debug used to stop loop
	}
//	ft_putendl("loop_hook exit"); //Debug
}
