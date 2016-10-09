/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 22:42:19 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:56:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static t_scene_tok		*new_scene_tok(void)
{
	t_scene_tok		*s;

	s = NULL;
	if (!(s = (t_scene_tok*)malloc(sizeof(t_scene_tok))))
		check_errors(MALLOC, "s", "LOAD_SCENE");
	s->objs_tok = NULL;
	s->lights_tok = NULL;
	s->camera = NULL;
	return (s);
}

char			*find_type(char *src, char *f, char c)
{
	char	**tab;
	char	*ret;

	tab = ft_strsplit(src, c);
	if (tab && tab[0] && tab[1])
	{
		if (ft_strcmp(tab[0], f) == 0)
		{
			ret = ft_strdup(tab[1]);
			free_tab(&tab);
			return (ret);
		}
		else
		{
			free_tab(&tab);
			return (NULL);
		}
	}
	free_tab(&tab);
	return (NULL);
}

void					build_scene_tok(t_scene_tok *sTok, char *scene)
{
	char		**tab;

	tab = NULL;
	cust_epurstr(scene);
	str_lower(scene);
	if (!(tab = ft_strsplit(scene, SEP_1)))
		check_errors(NUL, "scene file Error", "");
	set_cameraTok(sTok, tab);
	set_light_tok(sTok, tab);
	set_obj_tok(sTok, tab);
	free_tab(&tab);
}

void		load_scene(t_rt *rt, char *scene)
{
	t_scene_tok		*sTok;

	(void)rt;
	sTok = NULL;
	if (scene)
	{
		sTok = new_scene_tok();
		if (!sTok)
			check_errors(MALLOC, "sTok", "load_scene.c");
		build_scene_tok(sTok, scene);
		
		put_scene_tok(sTok); //Debug

		load_camera(rt->camera, sTok->camera);
		load_lights(&rt->lights, sTok->lights_tok);
		load_objs(&rt->objs, sTok->objs_tok);
		rt->tok = sTok;
	}
}
