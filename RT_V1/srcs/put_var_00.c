#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void		put_pos(t_pos pos)
{
	(void)pos;

	//replace printf with ft_printf
	printf("(%lf, %lf, %lf)\n", pos.x, pos.y, pos.z);

//	ft_putendl("Put pos"); //Debug
}

void		put_base(t_base base)
{
	(void)base;
	
	//replace printf with ft_printf
	printf("o -> ");
	put_pos(base.o);
	printf("i -> ");
	put_pos(base.i);
	printf("j -> ");
	put_pos(base.j);
	printf("k -> ");
	put_pos(base.k);

//	ft_putendl("Put base"); //Debug
}

void		put_camera(t_camera camera)
{
	printf("CAMERA \n{\n");
	
	printf("\nself \n{\n");
	put_base(camera.self);
	printf("}\n");

	printf("\nspace \n{\n");
	put_base(camera.space);
	printf("}\n");

	printf("\nv_up \n{\n");
	put_pos(camera.v_up);
	printf("}\n");

	printf("\ndist = [%lf]\n", camera.dist);
	
	printf("\nfieldOfView = [%lf]\n", camera.fieldOfView);

	printf("\n} END\n");
}

void	put_space(t_space space)
{
	printf("SPACE \n{\n");

	printf("\nself \n{\n");
	put_base(space.self);
	printf("}\n");

	printf("\ncamera \n{\n");
	put_base(space.camera);
	printf("}\n");

	printf("\n} END\n");
}

void	put_screen(t_screen screen)
{
	printf("SCREEN \n{\n\n");

	printf("pixelWidth = [%d]\n", screen.pixelWidth);
	printf("pixelHeight = [%d]\n", screen.pixelHeight);
	printf("width = [%d]\n", screen.width);
	printf("height = [%d]\n", screen.height);
	printf("resX = [%d]\n", screen.resX);
	printf("resY = [%d]\n", screen.resY);

	printf("\n} END\n");
}
