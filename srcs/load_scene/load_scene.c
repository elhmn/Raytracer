/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 22:42:19 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/20 21:21:54 by bmbarga          ###   ########.fr       */
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

char					*find_type(char *src, char *f, char c)
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

void					build_scene_tok(t_scene_tok *s_tok, char *scene)
{
	char		**tab;

	tab = NULL;
	cust_epurstr(scene);
	str_lower(scene);
	if (!(tab = ft_strsplit(scene, SEP_1)))
		check_errors(NUL, "scene file Error", "");
	set_camera_tok(s_tok, tab);
	set_light_tok(s_tok, tab);
	set_obj_tok(s_tok, tab);
	free_tab(&tab);
}

void					load_scene(t_rt *rt, char *scene)
{
	t_scene_tok		*s_tok;

	(void)rt;
	s_tok = NULL;
	if (scene)
	{
		s_tok = new_scene_tok();
		if (!s_tok)
			check_errors(MALLOC, "sTok", "load_scene.c");
		build_scene_tok(s_tok, scene);
		load_camera(rt->camera, s_tok->camera);
		load_lights(&rt->lights, s_tok->lights_tok);
		load_objs(&rt->objs, s_tok->objs_tok);
		rt->tok = s_tok;
	}
}
