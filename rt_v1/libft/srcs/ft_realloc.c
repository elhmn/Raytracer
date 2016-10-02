/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 11:08:55 by mcanal            #+#    #+#             */
/*   Updated: 2016/10/02 19:28:40 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The realloc() function tries to change the size of the allocation pointed
** to by ptr to size, and returns ptr. If there is not enough room to enlarge
** the memory allocation pointed to by ptr, realloc() creates a new allocation,
** copies as much of the old data pointed to by ptr as will fit to the new
** allocation, frees the old allocation, and returns a pointer to the allocated
** memory. If ptr is NULL, realloc() is identical to a call to malloc() for size
** bytes. If size is zero and ptr is not NULL, a new, minimum sized object is
** allocated and the original object is freed.
*/

#include "libft.h"

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	void	*new;

	if (!(new = (void *)ft_memalloc(new_size ? sizeof(old) * new_size : 1)))
		return (NULL);
	if (old)
	{
		ft_memcpy(new, old, (old_size > new_size) ? (new_size) : (old_size));
		ft_memdel((void*)&old);
	}
	return (new);
}
