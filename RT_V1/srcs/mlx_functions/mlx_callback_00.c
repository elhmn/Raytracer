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

	rt = (t_rt*)param;
	ft_putendl("loop_hook enter"); //Debug
	if (rt)
	{
		raytracer(rt);
		//put_ray_image();
		//put_image_to_window;
	}
	ft_putendl("loop_hook exit"); //Debug
	return (0);
}
