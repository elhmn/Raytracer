## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: elhmn <marvin@42.fr>                       +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2014/03/13 07:58:39 by elhmn             #+#    #+#             ##
##   Updated: 2014/03/13 07:58:39 by elhmn            ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME = rtv1 

ERR_DIR = error_handling/
MAIN_DIR = main_functions/
INIT_DIR = init_var/
MLX_DIR = mlx_functions/
POS_DIR = pos_functions/
SET_DIR = set_var/
OBJFUNC_DIR = obj_functions/
PUT_DIR = put_var/
DRAW_DIR = draw/
RAYTRACER_DIR = raytracer/
COLL_DIR = collision_functions/
TRANS_DIR = transform/
DESTROY_DIR = destroy_var/
RT_COLOR_DIR = rt_color/
LIGHT_DIR = light/
MATERIAL_DIR = material/
NORMAL_COMP_DIR = normal_computation/
LOAD_SCENE_DIR = load_scene/
	

MAIN = main.c loop.c

ERR = check_errors.c fun_err_01.c

INIT = init_var_00.c init_var_01.c init_var_02.c init_scene.c

MLX = mlx_callback_00.c key_hook.c

POS = pos_function_00.c pos_function_01.c pos_function_02.c pos_function_03.c

SET = set_var_00.c

OBJFUNC = obj_function_00.c obj_function_01.c obj_rotation_00.c obj_move_00.c

PUT = put_var_00.c put_var_01.c put_var_02.c put_var_03.c put_cam_tok.c \
		put_objs_tok.c put_lights_tok.c put_scene_tok.c

DRAW = draw.c color.c

RAYTRACER = raytracer.c show.c rt_get_color.c rt_get_ray_color.c

COLL = sphere_collision.c plane_collision.c cylinder_collision.c cone_collision.c cone_collision_limit.c cylinder_collision_limit.c

TRANS = transform_00.c

DESTROY = release_mlx.c

RT_COLOR = rt_color.c rt_color_operation.c

LIGHT = light.c new_omni_light.c light_intensity.c lighting.c

MATERIAL = new_material.c

NORMAL_COMP = plane_normal.c sphere_normal.c cylinder_normal.c cone_normal.c

LOAD_SCENE = read_file.c load_scene.c str_function.c get_tok_var.c set_cam_tok.c set_light_tok.c\
			 set_obj_tok.c load_camera.c load_objs.c load_lights.c new_lights_tok.c

MAINS =  $(addprefix $(MAIN_DIR), $(MAIN))
ERRS =  $(addprefix $(ERR_DIR), $(ERR))
INITS =  $(addprefix $(INIT_DIR), $(INIT))
MLXS =  $(addprefix $(MLX_DIR), $(MLX))
POSS =  $(addprefix $(POS_DIR), $(POS))
SETS =  $(addprefix $(SET_DIR), $(SET))
OBJFUNCS =  $(addprefix $(OBJFUNC_DIR), $(OBJFUNC))
PUTS =  $(addprefix $(PUT_DIR), $(PUT))
DRAWS =  $(addprefix $(DRAW_DIR), $(DRAW))
RAYTRACERS =  $(addprefix $(RAYTRACER_DIR), $(RAYTRACER))
COLLS =  $(addprefix $(COLL_DIR), $(COLL))
TRANSS = $(addprefix $(TRANS_DIR), $(TRANS))
DESTROYS = $(addprefix $(DESTROY_DIR), $(DESTROY))
RT_COLORS = $(addprefix $(RT_COLOR_DIR), $(RT_COLOR))
LIGHTS = $(addprefix $(LIGHT_DIR), $(LIGHT))
MATERIALS = $(addprefix $(MATERIAL_DIR), $(MATERIAL))
NORMAL_COMPS = $(addprefix $(NORMAL_COMP_DIR), $(NORMAL_COMP))
LOAD_SCENES = $(addprefix $(LOAD_SCENE_DIR), $(LOAD_SCENE))

SRC_OBJ = $(MAIN) $(ERR) $(INIT) $(MLX) $(POS) $(OBJFUNC) \
			$(SET) $(PUT) $(DRAW) $(RAYTRACER) $(COLL) $(TRANS) \
			$(DESTROY) $(RT_COLOR) $(LIGHT) $(MATERIAL) $(NORMAL_COMP) \
			$(LOAD_SCENE)

SRC = 	$(MAINS) $(ERRS) $(INITS) $(MLXS) $(POSS) $(OBJFUNCS) \
		$(SETS) $(PUTS) $(DRAWS) $(RAYTRACERS) $(COLLS) $(TRANSS) \
		$(DESTROYS) $(RT_COLORS) $(LIGHTS) $(MATERIALS) $(NORMAL_COMPS) \
		$(LOAD_SCENES)

		
OBJ = $(SRC_OBJ:.c=.o)

OBJDIR = ./objs/

REPS =  $(addprefix $(OBJ_DIR), $(REP))

SRCDIR = ./srcs/

OBJS = $(addprefix $(OBJDIR), $(OBJ))

SRCS = $(addprefix $(SRCDIR), $(SRC))

FLAG = -Wall -Werror -Wextra

INCLUDES = -I ./includes/

LIB = -lm -L ./libft/ -lft -L /usr/lib64/ -lmlx -lX11 -lXext

LIBMAC = -lm -L ./libft/ -lft -lmlx  -framework OpenGL -framework appkit 

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAG) -g $(INCLUDES) -o $(NAME) $(OBJS) $(LIBMAC)

home: $(OBJS)
	gcc $(FLAG) -g $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

$(OBJS): $(SRCS)
	make -C ./libft
	gcc $(FLAG) -g -c $(SRCS) $(INCLUDES) &&  mv $(OBJ) $(OBJDIR)

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rm -f $(OBJ)
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
