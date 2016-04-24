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
#include <mlx.h>

#define WIDTH 400
#define HEIGHT 400
#define TITLE "MY WINDOW"

int	main(int ac, char **av)
{
	void	*win;
	void	*mlx;



	win = NULL;
	mlx = NULL;
	
	(void)ac;
	(void)av;
	(void)mlx;
	(void)win;

	if (!(mlx = mlx_init()))
	{
		ft_putendl("Error while loading mlx"); //Debug
		return (-1);
	}
	if (!(win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE)))
	{
		ft_putendl("Error while creating window"); //Debug
		return (-1);
	}
	mlx_loop(mlx); //Debug
	return (0);
}
