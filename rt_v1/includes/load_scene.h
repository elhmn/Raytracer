/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 22:56:51 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/05 23:35:35 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_SCENE_H
# define LOAD_SCENE_H

# define N_CAMERA		"camera"
# define N_LIGHT		"light"
# define N_OBJECT		"object"

# define A_POSITION		"position"
# define A_ROTATION		"rotation"
# define A_LOOKAT		"lookat"
# define A_TYPE			"type"
# define A_NAME			"name"
# define A_MATERIAL		"material"

# define A_DATA			"data"
# define A_RADIUS		"radius"
# define A_NORMAL		"normal"
# define A_AXIS			"axis"
# define A_HEIGHT		"height"
# define A_ANGLE		"angle"
# define A_TOP			"top"

# define A_TRANSLATION	"translation"

# define A_COLOR		"color"
# define A_ID			"id"
# define A_IS			"is"

# define T_OMNI			"omni"
# define T_PLANE		"plane"
# define T_SPHERE		"sphere"
# define T_CONE			"cone"
# define T_CYLINDER		"cylinder"

# define O_NAME			"zboob"

# define SEP_1			'}'
# define SEP_2			'{'
# define SEP_3			')'
# define SEP_4			'('
# define SEP_5			','

# define LIMIT_100(x)	(x > 100 || x < 0) ? (((x > 100) ? 100 : 0)) : x

# define CONV_100(x)	(x / 100.)

/*
** load_scene.c
*/

void					load_scene(t_rt *rt, char *scene);
void					build_scene_tok(t_scene_tok *stok, char *scene);
char					*find_type(char *src, char *f, char c);

/*
** str_function.c
*/

int						tab_len(char **tab);
void					put_tab(char **tab);
void					cust_epurstr(char *s);
void					str_lower(char *s);
void					free_tab(char ***tab);

/*
** set_camTok.c
*/

void					set_cam_tok_var(t_cam_tok *cam, char *str);
void					set_camera_tok(t_scene_tok *stok, char **tab);
void					new_cam_tok(t_scene_tok *stok);

/*
** set_lightTok.c
*/

void					get_index(char **tab, int *t, char *type);
int						obj_number(char **tab, char *type);
void					set_light_tok(t_scene_tok *stok, char **tab);
void					set_obj_tok(t_scene_tok *stok, char **tab);

/*
** get_tok_var.c
*/

void					get_dbl_tok(double *p, char **tab, char *type);

void					get_pos_tok(t_pos *p, char **tab, char *type);
void					get_label_tok(char **s, char **tab, char *type);

/*
** load_camera.c
*/

void					load_camera(t_camera *c, t_cam_tok *t);

/*
** load_lights.c
*/

void					load_lights(t_list **list, t_light_tok **t);

/*
** load_objs.c
*/

void					load_objs(t_list **list, t_obj_tok **t);

#endif
