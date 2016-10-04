/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmbarga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 17:03:22 by bmbarga           #+#    #+#             */
/*   Updated: 2016/10/04 21:44:31 by bmbarga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "libft.h"

/*
**	Variable limits define
*/

# define MAX_DBL			3.402823e+38
# define SHADOW_COEF		5.

/*
** s_color n define
*/

# define MASK_A			0xFF000000
# define MASK_R			0x00FF0000
# define MASK_G			0x0000FF00
# define MASK_B			0x000000FF

/*
** s_screen define
*/

# define RESX			800
# define RESY			600
# define SCREEN_WIDTH	RESX	
# define SCREEN_HEIGHT	RESY
# define PIXEL_HEIGHT	1
# define PIXEL_WIDTH	1

/*
** KeyCode define
*/

# define K_QUIT			53
# define K_R			15
# define K_LEFT			123
# define K_RIGHT		124
# define K_UP			126
# define K_DOWN			125

# define MOVE			100
# define ROT			10

# define K_A			0
# define K_S			1
# define K_D			2
# define K_W			13
# define K_Q			12
# define K_E			14

# define K_1			18
# define K_2			19
# define K_3			20

/*
** s_camera define
*/

# define FOV			60
# define RAD(x)			((double)x * (double)M_PI) / (double)180.0
# define ABS(x)			(x < 0) ? -x : x
# define SAFE_DIST		400.

typedef unsigned int		t_uint;
typedef struct s_obj		t_obj;
typedef struct s_sceneTok	t_sceneTok;

/*
** 3D coordinate structure
*/

typedef struct	s_pos
{
	double		x;
	double		y;
	double		z;
}				t_pos;

/*
** s_base structure describes a coordinate systeme
** an origin and 3 vectors
*/

typedef struct	s_base
{
	t_pos		o;
	t_pos		i;
	t_pos		j;
	t_pos		k;
}				t_base;

/*
** Camera structure
*/

typedef struct	s_camera
{
	t_base		sp;
	t_pos		v_up;

	double		dist;
	double		fieldOfView;
}				t_camera;

/*
** Space origin structure
*/

typedef struct	s_space
{
	t_base		self;
	t_base		camera;
}				t_space;

/*
** structure de stockage de couleur
*/

typedef struct		s_color
{
	unsigned int	alpha;
	unsigned int	color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_color;

/*
** Ray structure
*/

/*
** tmp color structure
*/

typedef long	t_col;

typedef struct	s_ray
{
	t_pos		pos;
	t_pos		rd;
	t_pos		ro;
	t_color		col;
}				t_ray;

/*
** layer struct
** depht  =>layer depht
** img ==> img is not appropriate for this program
*/

typedef struct		s_lay
{
	void		*img;
	int			bpp;
	int			line;
	int			endian;
	int			depht;
}					t_lay;

/*
** screen
*/

typedef struct	s_screen
{
	int			pixelWidth;
	int			pixelHeight;
	int			width;
	int			height;
	int			resX;
	int			resY;
}				t_screen;

/*
** mlx environnement structure
*/

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_env;

typedef struct s_rt
{
	t_env		*env;
	t_screen	*screen;
	t_camera	*camera;
	t_space		*space;
	t_ray		**ray;
	t_list		*objs;
	t_list		*lights;

	t_lay		lay;
	char		*img;
	int			refresh;

	t_sceneTok	*tok;

/*
**		Raytracer render option
*/
	int			render;
	int			diffuse;
	int			specular;
}				t_rt;

/*
** loop.c
*/

void			loop(t_rt *rt);

/*
** mlx_callback_00.c
*/

int				loop_hook(void *param);
int				key_hook(int keyCode, void *param);
int				expose_hook(void *param);

/*
** init_var_00.c
*/

void			init_rt(t_rt **rt, char *scene);
void			init_env(t_env **env);
void			init_screen(t_screen **screen);
void			init_camera(t_camera **camera, t_screen screen, t_space *space);

/*
** init_var_01.c
*/

void			init_ray_array(t_ray ***ray, t_screen *screen);
void			set_ray_array_zero(t_ray **ray, t_screen *screen);
void			init_space(t_space **space);
void			init_base_self(t_base *b);
void			set_base_zero(t_base *b);

/*
** init_var_02.c
*/

void			init_ray(t_ray *ray);
void			init_objs(t_list **objs);
void			init_lights(t_list **lights);

/*
** init_scene.c
*/

void			init_scene(t_rt *rt, char *scene);

/*
** set_var_00.c
*/

void			set_pos(t_pos *pos, double x,
				double y, double z);
void			copy_pos(t_pos *dst, t_pos src);
void			set_img(char **img, void *voidImg, t_lay *lay);

/*
** pos_function_00.c
*/

void			pos_add_to_pos(t_pos *p1, t_pos p2);
void			pos_add_to_pos_values(t_pos *pos,
				double x, double y, double z);
void			pos_sub_to_pos(t_pos *p1, t_pos p2);
void			pos_sub_to_pos_values(t_pos *pos,
				double x, double y, double z);
double			pos_dot_product(t_pos p1, t_pos p2);

/*
** pos_function_01.c
*/

void			pos_add_to_number(t_pos *pos, double nbr);
void			pos_sub_to_number(t_pos *pos, double nbr);
void			pos_mult_to_number(t_pos *pos, double nbr);
void			pos_div_to_number(t_pos *pos, double nbr);
t_pos			get_pos(double x, double y, double z);

/*
** pos_function_02.c
*/

t_pos			pos_cross_product(t_pos p1, t_pos p2);
void			pos_copy(t_pos *dest, t_pos src);
t_pos			pos_vector(t_pos p1, t_pos p2);
t_pos			pos_normalize(t_pos pos);
double			pos_norme(t_pos pos);

/*
** pos_function_03.c
*/

void			pos_rot_x(t_pos *src, t_pos o, double r);
void			pos_rot_y(t_pos *src, t_pos o, double r);
void			pos_rot_z(t_pos *src, t_pos o, double r);
void			pos_rot_xyz(t_pos *src, t_pos o, t_pos r);

/*
** draw.c
*/

void			pixel_put_img(t_rt *rt, int x, int y, t_color *col);

/*
** color.c
*/

t_color			get_color(t_uint r, t_uint g, t_uint b);
t_uint			rgb_to_color(t_uint r, t_uint g, t_uint b);
void			set_color(t_color *col);
t_color			get_reshaped_color(t_color col);

/*
** raytracer.c
*/

void			raytracer(t_rt *rt);
void			show(t_rt *rt);
int				get_distance(t_ray *r, t_obj *obj, t_rt *rt);

/*
** release_mlx.c
*/

void			clear_image(t_rt *rt);
void			release_mlx(t_rt *rt);
#endif
