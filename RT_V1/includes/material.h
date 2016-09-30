/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:21:55 by bmbarga           #+#    #+#             */
/*   Updated: 2016/09/30 14:40:16 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# define LIMIT_COEF(x) (x > 1. && x < 0.) ? ((x > 1.) ? 1. : 0.) : x

/*
** material struct : 
**	- ka ambiant material coef
**	- kd diffuse material coef
**	- ks specular material coef
*/

typedef struct		s_material
{
	char			*name;
	double			ka;
	double			ks;
	double			kd;
}					t_material;

/*
** new_material.c
*/

t_material			*new_material(char *name, double ka,
									double ks, double kd);

#endif
