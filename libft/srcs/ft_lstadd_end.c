/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 20:37:26 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/05 20:24:04 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list *list_tmp;

	list_tmp = *alst;
	while (list_tmp->next)
		list_tmp = list_tmp->next;
	alst = &list_tmp;
	(*alst)->next = new;
}
