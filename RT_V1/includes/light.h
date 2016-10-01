/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 12:04:54 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/01 13:49:10 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT
# define LIGHT

# include "rt.h"
# include "rt_color.h"
# include "object.h"

/*
** does not depends on light source
*/

# define				I_AMBIENT	0.3

enum					e_light
{
	OMNI
};

/*
** light intensity
*/

typedef struct			s_volSpot
{
	double				h;
	double				ang;
}						t_volSpot;

/*
** I = { I ambiant, I diffuse, I specular }
*/

typedef struct			s_inty
{
	t_sColor			Id;
	t_sColor			Is;
}						t_inty;

typedef struct			s_light
{
	t_inty				I;
	enum e_light		type;
	t_base				sp;
	void				*volume;
}						t_light;

/*
** new_omniLight.c
*/

t_light				*new_omniLight(t_pos pos, t_inty I);

/*
** light.c
*/

t_light				*newLight(void);

/*
** lighting.c
*/

t_sColor			diffuse_light(t_light *light, t_obj *o,
									t_pos l, t_pos n);
t_sColor			specular_light(t_light *light,
								t_obj *o, t_base b);

/*
** light_intensity.c
*/

void				inty_copy(t_inty *d, t_inty s);
t_inty				get_inty(t_sColor Id, t_sColor Is);
t_sColor			getI(double r, double g, double b);

#endif
