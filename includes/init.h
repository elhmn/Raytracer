/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 21:47:26 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/05 23:20:29 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "rt.h"
# include "object.h"
# include "light.h"

void				init_scene(t_rt *rt, char *scene);

typedef struct		s_cam_tok
{
	t_pos			pos;
	t_pos			rot;
	t_pos			trans;
	char			*lookat;
}					t_cam_tok;

typedef struct		s_light_tok
{
	char			*type;
	t_pos			pos;
	t_pos			trans;
	t_pos			rot;
	t_pos			id;
	t_pos			is;
}					t_light_tok;

typedef struct		s_obj_tok
{
	char			*type;
	char			*name;
	t_pos			pos;
	t_pos			rot;
	t_pos			trans;
	t_pos			mat;
	t_pos			col;
	double			radius;
	t_pos			normal;
	char			*axis;
	double			height;
	double			angle;
	double			top;

}					t_obj_tok;

typedef struct		s_scene_tok
{
	t_cam_tok		*camera;
	t_light_tok		**lights_tok;
	t_obj_tok		**objs_tok;
}					t_scene_tok;

#endif
