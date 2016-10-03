/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 22:42:19 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 02:57:15 by bmbarga          ###   ########.fr       */
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

	tab = ft_strsplit(src, c);
	if (tab && tab[0] && tab[1])
	{
		if (ft_strcmp(tab[0], f) == 0)
			return (tab[1]);
		else
			return (NULL);
	}
	return (NULL);
}

void					build_sceneTok(t_sceneTok *sTok, char *scene)
{
	char		**tab;

	(void)sTok;
	(void)scene;
	(void)tab;
	cust_epurstr(scene);
	str_lower(scene);

	tab = NULL;
	if (!(tab = ft_strsplit(scene, SEP_1)))
		check_errors(NUL, "scene file Error", "");
	set_cameraTok(sTok, tab);
	free(scene);
	ft_putendl("------------------");
	put_tab(tab);
	ft_putendl("------------------");
}

t_sceneTok				*load_scene(char *scene)
{
	t_sceneTok		*sTok;

	sTok = NULL;
	if (scene)
	{
		sTok = new_sceneTok();
		build_sceneTok(sTok, scene);
	}
	return (sTok);
}
