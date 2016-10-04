/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sceneTok.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 13:37:22 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 13:47:25 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_var.h"
#include "rt.h"
#include "load_scene.h"
#include "init.h"

void		put_sceneTok(t_sceneTok *s)
{
	if (!s)
		return ;
	ft_putendl("scene : \n{");
	put_camTok(s->camera);
	put_lightsTok(s->lightsTok);
	put_objsTok(s->objsTok);
	ft_putendl("}\n");
}
