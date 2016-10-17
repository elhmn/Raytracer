/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam_tok.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:59:21 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 18:02:26 by bmbarga          ###   ########.fr       */
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

void					new_cam_tok(t_scene_tok *s_tok)
{
	if (s_tok)
	{
		if (!(s_tok->camera = (t_cam_tok*)malloc(sizeof(t_cam_tok))))
			check_errors(MALLOC, "Tok->camera", "");
		init_cam_tok(s_tok->camera);
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
		get_label_tok(&(cam->lookat), tab, A_LOOKAT);
		free_tab(&tab);
	}
}

void					set_camera_tok(t_scene_tok *s_tok, char **tab)
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
		s_tok->camera = NULL;
	else
	{
		new_cam_tok(s_tok);
		set_cam_tok_var(s_tok->camera, str);
		free(str);
	}
}
