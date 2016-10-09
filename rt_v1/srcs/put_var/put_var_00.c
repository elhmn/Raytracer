/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var_00.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:15:33 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:23:24 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_putstr("\nspace \n{\n");
	ft_putstr("pos -> ");
	put_pos(camera.sp.o);
	ft_putstr("\ni -> ");
	put_pos(camera.sp.i);
	ft_putstr("\nj -> ");
	put_pos(camera.sp.j);
	ft_putstr("\nk -> ");
	put_pos(camera.sp.k);
	ft_putstr("}\n");
	ft_putstr("\nv_up \n{\n");
	put_pos(camera.v_up);
	ft_putstr("}\n");
	ft_putstr("\ndist = [");
	ft_putdbl(camera.dist);
	ft_putendl("]");
	ft_putstr("\nfield_of_view = [");
	ft_putdbl(camera.field_of_view);
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
	ft_putstr("pixel_width = [");
	ft_putdbl(screen.pixel_width);
	ft_putendl("]");
	ft_putstr("pixel_height = [");
	ft_putdbl(screen.pixel_height);
	ft_putendl("]");
	ft_putstr("width = [");
	ft_putdbl(screen.width);
	ft_putendl("]");
	ft_putstr("height = [");
	ft_putdbl(screen.height);
	ft_putendl("]");
	ft_putstr("res_x = [");
	ft_putdbl(screen.res_x);
	ft_putendl("]");
	ft_putstr("res_y = [");
	ft_putdbl(screen.res_y);
	ft_putendl("]");
	ft_putstr("\n} END\n");
}
