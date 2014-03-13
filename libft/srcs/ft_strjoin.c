/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <bmbarga@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 04:42:54 by bmbarga           #+#    #+#             */
/*   Updated: 2013/12/05 14:08:29 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp_s1;

	tmp_s1 = ft_strnew(ft_strlen(s2) + ft_strlen(s1));
	if (!tmp_s1)
		return (NULL);
	ft_strcpy(tmp_s1, s1);
	ft_strcat(tmp_s1, s2);
	return (tmp_s1);
}
