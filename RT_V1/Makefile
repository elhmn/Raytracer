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

NAME = RTV1

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
	

MAIN = main.c loop.c

ERR = check_errors.c fun_err_01.c

INIT = init_var_00.c init_var_01.c init_var_02.c

MLX = mlx_callback_00.c

POS = pos_function_00.c pos_function_01.c pos_function_02.c pos_function_03.c

SET = set_var_00.c

OBJFUNC = obj_function_00.c obj_function_01.c

PUT = put_var_00.c put_var_01.c

DRAW = draw.c color.c

RAYTRACER = raytracer.c show.c

COLL = sphere_collision.c plane_collision.c

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

SRC_OBJ = $(MAIN) $(ERR) $(INIT) $(MLX) $(POS) $(OBJFUNC) \
			$(SET) $(PUT) $(DRAW) $(RAYTRACER) $(COLL)

SRC = 	$(MAINS) $(ERRS) $(INITS) $(MLXS) $(POSS) $(OBJFUNCS) \
		$(SETS) $(PUTS) $(DRAWS) $(RAYTRACERS) $(COLLS)
		

OBJ = $(SRC_OBJ:.c=.o)

OBJDIR = ./objs/

REPS =  $(addprefix $(OBJ_DIR), $(REP))

SRCDIR = ./srcs/

OBJS = $(addprefix $(OBJDIR), $(OBJ))

SRCS = $(addprefix $(SRCDIR), $(SRC))

FLAG = -Wall -Werror -Wextra

INCLUDES = -I ./includes/

LIB = -lm -L ./libft/ -lft -L /usr/lib64/ -lmlx -lX11 -lXext

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAG) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

$(OBJS): $(SRCS)
	make -C ./libft
	gcc $(FLAG) -c $(SRCS) $(INCLUDES) &&  mv $(OBJ) $(OBJDIR)

clean:
	make clean -C ./libft
	rm -f $(OBJS)
	rm -f $(OBJ)
	rm -f ./*.o

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
