/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_computation.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 17:23:25 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/05 23:27:57 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_COMPUTATION_H
# define NORMAL_COMPUTATION_H

# include "rt.h"
# include "object.h"

t_pos		plane_normal(t_obj *o, t_pos r, t_pos p);
t_pos		sphere_normal(t_obj *o, t_pos r, t_pos p);
t_pos		cylinder_normal(t_obj *o, t_pos r, t_pos p);
t_pos		cone_normal(t_obj *o, t_pos r, t_pos p);

#endif
