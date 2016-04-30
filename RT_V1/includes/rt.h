#ifndef RT_H
# define RT_H

/*
** s_screen define
*/

# define RESX			400
# define RESY			400
# define SCREEN_WIDTH	400
# define SCREEN_HEIGHT	400
# define PIXEL_HEIGHT	1
# define PIXEL_WIDTH	1

/*
** s_camera define
*/

# define FOV			60
# define RAD(x)			(x * M_PI) / 180.0

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
	t_base		self;
	t_base		space;
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
** Ray structure
*/

/*
** tmp color structure
*/

typedef long	t_col;

typedef struct	s_ray
{
	t_pos		camPos;
	t_pos		spPos;
	t_col		col;
}				t_ray;

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
}				t_env;

typedef struct s_rt
{
	t_env		*env;
	t_screen	*screen;
	t_camera	*camera;
	t_space		*space;
	t_ray		**ray;

	//and maybe something to store pixels color
	//char		**pixels;
}				t_rt;

/*
** mlx_callback_00.c
*/

int			loop_hook(void *param);

/*
** init_var_00.c
*/

void		init_rt(t_rt **rt);
void		init_env(t_env **env);
void		init_screen(t_screen **screen);
void		init_camera(t_camera **camera, t_screen screen);

/*
** init_var_01.c
*/

void		init_ray(t_ray ***ray);
void		init_space(t_space **space);
void		init_base_self(t_base *b);
void		init_base_zero(t_base *b);

#endif
