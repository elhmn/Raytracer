/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:40:58 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/02 21:20:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_VAR_H
# define PUT_VAR_H

# include "rt.h"
# include "light.h"
# include "rt_color.h"
# include "object.h"

/*
** put_var_00.c
*/

void			put_pos(t_pos pos);
void			put_base(t_base base);
void			put_camera(t_camera camera);
void			put_space(t_space space);
void			put_screen(t_screen screen);

/*
** put_var_01.c
*/

void			put_ray(t_ray ray);
void			put_dataSphere(t_dataSphere *data);
void			put_type(int type);
void			put_obj(void *obj);
void			put_dataPlane(t_dataPlane *data);

/*
** put_var_02.c
*/

void			put_var_dbl(char *var, double val);
void			put_sColor(t_sColor s);
void			put_light(t_light *l);
void			put_dataCone(t_dataCone *data);
void			put_dataCylinder(t_dataCylinder *data);

/*
** put_var_03.c
*/

void			put_material(t_material m);
void			end_block(char *str);
void			start_block(char *str);

#endif
