/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 22:42:19 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 22:10:34 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static t_sceneTok		*new_sceneTok(void)
{
	t_sceneTok		*s;

	s = NULL;
	if (!(s = (t_sceneTok*)malloc(sizeof(t_sceneTok))))
		check_errors(MALLOC, "s", "LOAD_SCENE");
	s->objsTok = NULL;
	s->lightsTok = NULL;
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

void					build_sceneTok(t_sceneTok *sTok, char *scene)
{
	char		**tab;

	tab = NULL;
	cust_epurstr(scene);
	str_lower(scene);
	if (!(tab = ft_strsplit(scene, SEP_1)))
		check_errors(NUL, "scene file Error", "");
	set_cameraTok(sTok, tab);
	set_lightTok(sTok, tab);
	set_objTok(sTok, tab);
	free_tab(&tab);
}

void		load_scene(t_rt *rt, char *scene)
{
	t_sceneTok		*sTok;

	(void)rt;
	sTok = NULL;
	if (scene)
	{
		sTok = new_sceneTok();
		if (!sTok)
			check_errors(MALLOC, "sTok", "load_scene.c");
		build_sceneTok(sTok, scene);
		
		put_sceneTok(sTok); //Debug

		load_camera(rt->camera, sTok->camera);
		load_lights(&rt->lights, sTok->lightsTok);
		load_objs(&rt->objs, sTok->objsTok);
		rt->tok = sTok;
	}
}
