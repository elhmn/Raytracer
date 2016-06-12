#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "check_errors.h"

//gerer correctement l expose
//
int		loop_hook(void *param)
{
	t_rt	*rt;
//	t_color	*col;

//	col = (t_color*)malloc(sizeof(t_color));
//	col->color = rgb_to_color(255, 255, 255);
//	set_color(col);

	rt = (t_rt*)param;
	ft_putendl("loop_hook enter"); //Debug
	if (rt)
	{
		raytracer(rt);
		show(rt);
//		put_ray_image();
//		pixel_put_img(rt, 200, 200, col);
		mlx_put_image_to_window(rt->env->mlx, rt->env->win,
								rt->env->img, 0, 0);
	}
//	free(col);
	ft_putendl("loop_hook exit"); //Debug
	return (0);
}
