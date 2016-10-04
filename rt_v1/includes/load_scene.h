/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 22:56:51 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 12:18:13 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_SCENE_H
# define LOAD_SCENE_H

# define	N_CAMERA		"camera"
# define	N_LIGHT			"light"
# define	N_OBJECT		"object"

# define	A_POSITION		"position"
# define	A_ROTATION		"rotation"
# define	A_LOOKAT		"lookat"
# define	A_TYPE			"type"
# define	A_NAME			"name"
# define	A_MATERIAL		"material"

# define	A_DATA			"data"
# define	A_RADIUS		"radius"
# define	A_NORMAL		"normal"
# define	A_AXIS			"axis"
# define	A_HEIGHT		"height"
# define	A_ANGLE			"angle"

# define	A_COLOR			"color"
# define	A_ID			"id"
# define	A_IS			"is"

# define SEP_1		'}'
# define SEP_2		'{'
# define SEP_3		')'
# define SEP_4		'('
# define SEP_5		','

/*
** load_scene.c
*/

t_sceneTok				*load_scene(char *scene);
void					build_sceneTok(t_sceneTok *sTok, char *scene);
char					*find_type(char *src, char *f, char c);

/*
** str_function.c
*/

int						tab_len(char **tab);
void					put_tab(char **tab);
void					cust_epurstr(char *s);
void					str_lower(char *s);
void					free_tab(char **tab);

/*
** set_camTok.c
*/

void					set_camTok_var(t_camTok *cam, char *str);
void					set_cameraTok(t_sceneTok *sTok, char **tab);
void					new_camTok(t_sceneTok *sTok);

/*
** set_lightTok.c
*/

void					get_index(char **tab, int *t, char *type);
int						obj_number(char **tab, char *type);
void					set_lightTok(t_sceneTok *sTok, char **tab);
void					set_objTok(t_sceneTok *sTok, char **tab);

/*
** get_tok_var.c
*/

void					get_dbl_tok(double *p, char **tab, char *type);

void					get_pos_tok(t_pos *p, char **tab, char *type);
void					get_label_tok(char **s, char **tab, char *type);
#endif
