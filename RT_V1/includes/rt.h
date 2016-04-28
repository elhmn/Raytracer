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

# define FOV			30

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
** mlx environnement structure
*/

typedef struct s_env
{
	void	*mlx;
	void	*win;
}				t_env;

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


#endif
