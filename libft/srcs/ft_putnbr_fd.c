/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 01:54:18 by bmbarga           #+#    #+#             */
/*   Updated: 2013/11/29 09:29:40 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static void	ft_put_aux_nbr_fd(int n, int fd)
{
	if (n >= 10)
	{
		ft_put_aux_nbr_fd(n / 10, fd);
		ft_put_aux_nbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_put_aux_nbr_fd(n * -1, fd);
	}
	else
		ft_put_aux_nbr_fd(n, fd);
}

