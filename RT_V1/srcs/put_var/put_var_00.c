#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

void		put_pos(t_pos pos)
{
	ft_putstr("(");
	ft_putdbl(pos.x);
	ft_putstr(", ");
	ft_putdbl(pos.y);
	ft_putstr(", ");
	ft_putdbl(pos.z);
	ft_putstr(")");
	ft_putendl("");
}

void		put_base(t_base base)
{
	ft_putstr("o -> ");
	put_pos(base.o);
	ft_putstr("i -> ");
	put_pos(base.i);
	ft_putstr("j -> ");
	put_pos(base.j);
	ft_putstr("k -> ");
	put_pos(base.k);
}

/*
** do the same thing with the function bellow
*/

void		put_camera(t_camera camera)
{
	ft_putstr("CAMERA \n{\n");
	ft_putstr("\nself \n{\n");
	put_base(camera.self);
	ft_putstr("}\n");
	ft_putstr("\nspace \n{\n");
	put_base(camera.space);
	ft_putstr("}\n");
	ft_putstr("\nv_up \n{\n");
	put_pos(camera.v_up);
	ft_putstr("}\n");
	ft_putstr("\ndist = [");
	ft_putdbl(camera.dist);
	ft_putendl("]");
	ft_putstr("\nfieldOfView = [");
	ft_putdbl(camera.fieldOfView);
	ft_putendl("]");
	ft_putstr("\n} END\n");
}

void	put_space(t_space space)
{
	ft_putstr("SPACE \n{\n");
	ft_putstr("\nself \n{\n");
	put_base(space.self);
	ft_putstr("}\n");
	ft_putstr("\ncamera \n{\n");
	put_base(space.camera);
	ft_putstr("}\n");
	ft_putstr("\n} END\n");
}

void	put_screen(t_screen screen)
{
	ft_putstr("SCREEN \n{\n\n");
	ft_putstr("pixelWidth = [");
	ft_putdbl(screen.pixelWidth);
	ft_putendl("]");
	ft_putstr("pixelHeight = [");
	ft_putdbl(screen.pixelHeight);
	ft_putendl("]");
	ft_putstr("width = [");
	ft_putdbl(screen.width);
	ft_putendl("]");
	ft_putstr("height = [");
	ft_putdbl(screen.height);
	ft_putendl("]");
	ft_putstr("resX = [");
	ft_putdbl(screen.resX);
	ft_putendl("]");
	ft_putstr("resY = [");
	ft_putdbl(screen.resY);
	ft_putendl("]");
	ft_putstr("\n} END\n");
}
