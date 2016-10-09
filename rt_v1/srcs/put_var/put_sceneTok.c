/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_scene_tok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 13:37:22 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/09 22:56:06 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "rt.h"
#include "load_scene.h"
#include "init.h"

void		put_scene_tok(t_scene_tok *s)
{
	if (!s)
		return ;
	ft_putendl("scene : \n{");
	put_cam_tok(s->camera);
	put_lights_tok(s->lights_tok);
	put_objs_tok(s->objs_tok);
	ft_putendl("}\n");
}
