/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_computation.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:23:25 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 00:34:42 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_COMPUTATION
# define NORMAL_COMPUTATION

# include "rt.h"
# include "object.h"

t_pos		plane_normal(t_obj *o, t_pos r, t_pos p);
t_pos		sphere_normal(t_obj *o, t_pos r, t_pos p);
t_pos		cylinder_normal(t_obj *o, t_pos r, t_pos p);

#endif
