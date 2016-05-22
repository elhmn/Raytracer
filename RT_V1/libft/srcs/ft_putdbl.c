/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 05:46:14 by mcanal            #+#    #+#             */
/*   Updated: 2016/05/01 15:09:52 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print a double on stdout
*/

#include "libft.h"

#define PRECISION 9

static size_t	length(size_t n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static char		*add_left(char *swap, size_t nbr)
{
	char	*end;

	end = swap + length(nbr);
	swap = end - 1;
	*swap = nbr % 10 + '0';
	while (nbr /= 10)
		*(--swap) = nbr % 10 + '0';
	return (end);
}

static void		add_right(char *swap, double nbr)
{
	size_t	pres;

	pres = PRECISION;
	while (pres--)
	{
		nbr *= 10;
		if (!(size_t)nbr)
			*(swap++) = '0';
	}
	add_left(swap, (size_t)nbr);
}

void			ft_putdbl(double nbr)
{
	char	buf[32 + PRECISION];
	char	*swap;

	ft_bzero((void *)buf, 32 + PRECISION);
	swap = buf;
	if (nbr < 0)
	{
		nbr *= -1;
		*(swap++) = '-';
	}
	swap = add_left(swap, (size_t)nbr);
	*(swap++) = '.';
	add_right(swap, nbr - (double)(size_t)nbr);
	ft_putstr(buf);
}