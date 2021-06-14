/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 12:04:54 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/17 17:53:33 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rt.h"
# include "rt_color.h"
# include "object.h"

/*
** does not depends on light source
*/

# define I_AMBIENT		0.3

enum					e_light
{
	OMNI
};

/*
** light intensity
*/

typedef struct			s_vol_spot
{
	double				h;
	double				ang;
}						t_vol_spot;

/*
** I = { I ambiant, I diffuse, I specular }
*/

typedef struct			s_inty
{
	t_s_color			id;
	t_s_color			is;
}						t_inty;

typedef struct			s_light
{
	int					id;
	t_inty				inty;
	enum e_light		type;
	t_base				sp;
	void				*volume;
}						t_light;

/*
** new_omniLight.c
*/

t_light					*new_omni_light(t_pos pos, t_inty i);

/*
** light.c
*/

t_light					*new_light(void);

/*
** lighting.c
*/

t_s_color				diffuse_light(t_light *light, t_obj *o,
									t_pos l, t_pos n);
t_s_color				specular_light(t_light *light,
									t_obj *o, t_base b);
/*
** light_intensity.c
*/

void					inty_copy(t_inty *d, t_inty s);
t_inty					get_inty(t_s_color id, t_s_color is);
t_s_color				get_i(double r, double g, double b);
int						enlightened(t_rt *rt, t_obj *o, t_ray r);
#endif
