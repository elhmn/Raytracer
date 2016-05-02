#ifndef RT_H
# define RT_H

/*
** s_screen define
*/

# define RESX			600
# define RESY			400
# define SCREEN_WIDTH	600
# define SCREEN_HEIGHT	400
# define PIXEL_HEIGHT	1
# define PIXEL_WIDTH	1

/*
** s_camera define
*/

# define FOV			60
# define RAD(x)			(x * M_PI) / 180.0
# define SAFE_DIST		200

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

int				loop_hook(void *param);

/*
** init_var_00.c
*/

void			init_rt(t_rt **rt);
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
void			init_camera_base(t_camera *cam, t_base *space);

/*
** put_var_00.c
*/

void			put_pos(t_pos pos);
void			put_base(t_base base);
void			put_camera(t_camera camera);
void			put_space(t_space space);
void			put_screen(t_screen screen);

/*
** put_var_01.c
*/

void			put_ray(t_ray ray);

/*
** set_var_00.c
*/

void			set_pos(t_pos *pos, double x,
				double y, double z);

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

/*
** pos_function_02.c
*/

t_pos			pos_cross_product(t_pos p1, t_pos p2);
void			pos_copy(t_pos *dest, t_pos src);
t_pos			pos_vector(t_pos p1, t_pos p2);
t_pos			pos_normalize(t_pos pos);
double			pos_norme(t_pos pos);
#endif
