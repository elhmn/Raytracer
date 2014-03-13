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

NAME = Raytracer

SRC = main.c

OBJ = $(SRC:.c=.o)

OBJDIR = ./objs/

SRCDIR = ./srcs/

OBJS = $(addprefix $(OBJDIR), $(OBJ))

SRCS = $(addprefix $(SRCDIR), $(SRC))

FLAG = -Wall -Werror -Wextra

INCLUDES = -I includes/

LIB = -L ./libft/ -lft

all: $(NAME)

$(NAME): object lib
	@gcc $(FLAG) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

lib:
	@make -C ./libft

object: $(SRCS)
	@gcc $(FLAG) -c $(SRCS) && mv $(OBJ) $(OBJDIR)

clean:
	@make clean -C ./libft
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft

re: fclean all
