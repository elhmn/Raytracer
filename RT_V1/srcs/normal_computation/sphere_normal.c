/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_computation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 20:42:05 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 20:47:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "check_errors.h"
#include "normal_computation.h"

t_pos		sphere_normal(t_obj *o, t_pos r, t_pos p)
{
	t_pos			n;

	(void)n;
	(void)o;
	(void)r;
	(void)p;
	n = pos_vector(o->sp.o, p);
	n = pos_normalize(n);
	return (n);
}
