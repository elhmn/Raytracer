#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include <stdio.h>
#include <stdlib.h>

void	put_ray(t_ray ray)
{
	printf("camPos : ");
	put_pos(ray.camPos);
	printf("spPos : ");
	put_pos(ray.spPos);
	printf("col");
	printf("[%ld]\n", (long)ray.col);
	printf("\n");
}
