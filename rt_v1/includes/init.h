/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 21:47:26 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 03:08:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "rt.h"
# include "object.h"
# include "light.h"

void				init_scene(t_rt *rt, char *scene);

typedef struct		s_camTok
{
	t_pos			pos;
	t_pos			rot;
	char			*lookAt;
}					t_camTok;

typedef struct		s_lightTok
{
	enum e_light	type;
	t_pos			pos;
	t_pos			rot;
	t_pos			Id;
	void			*data;
}					t_lightTok;

typedef struct		s_objTok
{
	enum e_obj		type;
	char			*name;
	t_pos			pos;
	t_pos			rot;
	char			*lookAt;
	t_material		*mat;
	t_color			col;
	void			*data;
}					t_objTok;

typedef struct		s_sceneTok
{
	t_camTok		*camera;
	t_lightTok		**lightsTok;
	t_objTok		**objsTok;
}					t_sceneTok;


#endif
