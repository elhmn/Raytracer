#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "check_errors.h"

void	loop(t_rt *rt)
{
	ft_putendl("loop_hook enter"); //Debug
	if (rt)
	{
		raytracer(rt);
		show(rt);
		/* put mlx->img to window*/
		if (rt->env
			&& rt->env->mlx
			&& rt->env->win
			&& rt->env->img)
			mlx_put_image_to_window(rt->env->mlx, rt->env->win,
								rt->env->img, 0, 0);
		else
			check_errors(NUL, "loop.c", "rt->env struct");
	}
	ft_putendl("loop_hook exit"); //Debug
}
