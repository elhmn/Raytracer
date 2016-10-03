/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 22:56:51 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 02:57:09 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_SCENE_H
# define LOAD_SCENE_H

# define	N_CAMERA		"camera"

# define	A_POSITION		"position"
# define	A_ROTATION		"rotation"
# define	A_LOOKAT		"lookat"

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

/*
** set_camTok.c
*/

void					set_camTok_var(t_camTok *cam, char *str);
void					set_cameraTok(t_sceneTok *sTok, char **tab);
void					new_camTok(t_sceneTok *sTok);
void					get_lookAt(char **s, char **tab);

/*
** set_tok_var.c
*/

void					get_rotation(t_pos *p, char **tab);
void					get_position(t_pos *p, char **tab);
#endif
