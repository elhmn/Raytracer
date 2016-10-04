/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:40:58 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 13:42:12 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_VAR_H
# define PUT_VAR_H

# include "rt.h"
# include "light.h"
# include "rt_color.h"
# include "object.h"
# include "init.h"

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

/*
** put_lightsTok.c
*/

void			put_lightsTok(t_lightTok **t);
void			put_lightTok(t_lightTok *t);

/*
** put_objsTok.c
*/

void			put_objsTok(t_objTok **t);
void			put_objTok(t_objTok *t);

/*
** put_camTok.c
*/

void			put_camTok(t_camTok *t);

/*
** put_sceneTok.c
*/

void			put_sceneTok(t_sceneTok *s);

#endif
