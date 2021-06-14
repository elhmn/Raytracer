/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_lights_tok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 19:23:42 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 19:26:55 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "init.h"
#include "libft.h"
#include "check_errors.h"
#include "load_scene.h"
#include "put_var.h"
#include <stdlib.h>

void				init_light_tok(t_light_tok *t)
{
	if (t)
	{
		t->type = T_OMNI;
		t->pos = get_pos(0, 400, 0);
		t->trans = get_pos(0, 0, 0);
		t->rot = get_pos(0, 0, 0);
		t->id = get_pos(60, 60, 60);
		t->is = get_pos(40, 40, 40);
	}
}

void				new_lights_tok(t_scene_tok *s_tok, int len)
{
	int				i;

	if (s_tok)
	{
		if (!(s_tok->lights_tok =
				(t_light_tok**)malloc(sizeof(t_light_tok*) * (len + 1))))
			check_errors(MALLOC, "s_tok->lights_tok", "set_light_tok");
		s_tok->lights_tok[len] = NULL;
		i = -1;
		while (++i < len)
		{
			if (!(s_tok->lights_tok[i] =
					(t_light_tok*)malloc(sizeof(t_light_tok))))
				check_errors(MALLOC, "s_tok->lights_tok[i]", "set_light_tok");
			init_light_tok(s_tok->lights_tok[i]);
		}
	}
}
