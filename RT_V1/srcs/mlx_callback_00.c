#include <mlx.h>
#include <stdlib.h>
#include "rt.h"
#include "libft.h"
#include "check_errors.h"


int		loop_hook(void *param)
{
	(void)param;
	ft_putendl("je suis con"); //Debug
	return (0);
}
