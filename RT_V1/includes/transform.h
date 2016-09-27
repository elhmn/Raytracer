/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:06:50 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/27 10:36:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "rt.h"

/*
** transform_00.c
*/

t_pos		transform(t_base a, t_base b, t_pos pos, t_pos rot);
t_pos		transform_rev(t_base b, t_pos pos);
//void		test_transform(void); //Debug

#endif
