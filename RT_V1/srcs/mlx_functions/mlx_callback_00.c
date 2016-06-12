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
	loop(rt);
	return (0);
}
