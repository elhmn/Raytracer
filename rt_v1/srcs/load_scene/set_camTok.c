/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camTok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 02:48:52 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/03 17:03:43 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void					new_camTok(t_sceneTok *sTok)
{
	if (sTok)
	{
		if (!(sTok->camera = (t_camTok*)malloc(sizeof(t_camTok))))
			check_errors(MALLOC, "Tok->camera", "");
		sTok->camera->pos = get_pos(0, 0, 0);
		sTok->camera->rot = get_pos(0, 0, 0);
		sTok->camera->lookAt = NULL;
	}
}


void					set_camTok_var(t_camTok *cam, char *str)
{
	char		**tab;

	tab = NULL;
	if (cam && str)
	{
		tab = ft_strsplit(str, SEP_3);
		put_tab(tab); //Debug
		get_pos_tok(&(cam->pos), tab, A_POSITION);
		get_pos_tok(&(cam->rot), tab, A_ROTATION);
		get_label_tok(&(cam->lookAt), tab, A_LOOKAT);
		free_tab(tab);
	}
}

void					set_cameraTok(t_sceneTok *sTok, char **tab)
{
	char		*str;

	(void)sTok;
	str = NULL;
	if (tab)
		while (*tab)
			if ((str = find_type(*tab++, N_CAMERA, SEP_2)))
				break ;
	if (!str)
		check_errors(NUL, "no camera defined", "");
	new_camTok(sTok);
	set_camTok_var(sTok->camera, str);
	free(str);
}
