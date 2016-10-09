/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam_tok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 02:48:52 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:55:37 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

static void				init_cam_tok(t_cam_tok *t)
{
	if (t)
	{
		t->pos = get_pos(0, 0, 0);
		t->rot = get_pos(0, 0, 0);
		t->trans = get_pos(0, 0, 0);
		t->lookat = NULL;
	}
}

void					new_cam_tok(t_scene_tok *sTok)
{
	if (sTok)
	{
		if (!(sTok->camera = (t_cam_tok*)malloc(sizeof(t_cam_tok))))
			check_errors(MALLOC, "Tok->camera", "");
		init_cam_tok(sTok->camera);
	}
}


void					set_cam_tok_var(t_cam_tok *cam, char *str)
{
	char		**tab;

	tab = NULL;
	if (cam && str)
	{
		tab = ft_strsplit(str, SEP_3);
		get_pos_tok(&(cam->pos), tab, A_POSITION);
		get_pos_tok(&(cam->rot), tab, A_ROTATION);
		get_pos_tok(&(cam->trans), tab, A_TRANSLATION);
		get_label_tok(&(cam->lookat), tab, A_lookat);
		free_tab(&tab);
	}
}

void					set_cameraTok(t_scene_tok *sTok, char **tab)
{
	char		*str;

	str = NULL;
	if (tab)
	{
		while (*tab)
		{
			if ((str = find_type(*tab++, N_CAMERA, SEP_2)))
				break ;
		}
	}
	if (!str)
		sTok->camera = NULL;
	else
	{
		new_cam_tok(sTok);
		set_cam_tok_var(sTok->camera, str);
		free(str);
	}
}
