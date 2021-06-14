/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:40:58 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/05 23:42:22 by bmbarga          ###   ########.fr       */
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
void			put_data_sphere(t_data_sphere *data);
void			put_type(int type);
void			put_obj(void *obj);
void			put_data_plane(t_data_plane *data);

/*
** put_var_02.c
*/

void			put_var_dbl(char *var, double val);
void			put_s_color(t_s_color s);
void			put_light(t_light *l);
void			put_data_cone(t_data_cone *data);
void			put_data_cylinder(t_data_cylinder *data);

/*
** put_var_03.c
*/

void			put_material(t_material m);
void			end_block(char *str);
void			start_block(char *str);

/*
** put_lights_tok.c
*/

void			put_lights_tok(t_light_tok **t);
void			put_light_tok(t_light_tok *t);

/*
** put_objs_tok.c
*/

void			put_objs_tok(t_obj_tok **t);
void			put_obj_tok(t_obj_tok *t);

/*
** put_cam_tok.c
*/

void			put_cam_tok(t_cam_tok *t);

/*
** put_scene_tok.c
*/

void			put_scene_tok(t_scene_tok *s);

#endif
