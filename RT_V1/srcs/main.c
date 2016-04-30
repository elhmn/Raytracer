/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 08:33:16 by elhmn             #+#    #+#             */
/*   Updated: 2014/03/13 08:33:16 by elhmn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rt.h"
#include "check_errors.h"
#include <mlx.h>
#include <stdlib.h>

#define WIDTH 400
#define HEIGHT 400
#define TITLE "MY WINDOW"

/*
**			TO_DO
**	+Get scene from file
**	+Load scene
**	+Loop
**		- Raytracer
**		- Realtime events
**		- Simple Real Time Renderer
*/

int	main(int ac, char **av)
{
	t_env		*e;

	(void)av;
	(void)ac;
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		check_errors(MALLOC, "main.c", "e");
	if (!(e->mlx = mlx_init()))
		check_errors(MALLOC, "main.c", "mlx");
	if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, TITLE)))
		check_errors(MALLOC, "main.c", "win");
	mlx_loop(e->mlx); //Debug
	return (0);
}
