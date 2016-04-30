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

SRC = main.c check_errors.c fun_err_01.c mlx_callback_00.c init_var_00.c \
		init_var_01.c put_var_00.c

OBJ = $(SRC:.c=.o)

OBJDIR = ./objs/

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

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all
