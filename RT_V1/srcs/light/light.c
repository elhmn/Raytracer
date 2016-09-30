/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 12:21:54 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 14:11:21 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "check_errors.h"
#include <stdlib.h>

t_light			*newLight(void)
{
	t_light		*l;

	l = NULL;
	if (!(l = (t_light*)malloc(sizeof(t_light))))
		check_errors(MALLOC, "l", "light.c");
	return (l);
}
