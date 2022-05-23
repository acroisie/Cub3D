# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 08:07:28 by acroisie          #+#    #+#              #
#    Updated: 2022/05/23 10:16:44 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc 

CC_FLAGS = -Wall -Werror -Wextra

NAME := cub3D

SRCS := errors.c \
		main.c

OBJS := $(SRCS:.c=.o)

all : mlx $(NAME)

$(NAME):		$(addprefix objs/, $(OBJS))
					$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) mlx/libmlx.a -framework OpenGL -framework AppKit

objs/%.o:		srcs/%.c include/cub3D.h mlx/libmlx.a Makefile
					@mkdir -p objs
					$(CC) $(CC_FLAGS) -c $< -o $@

mlx :	
		$(MAKE) -C mlx

clean :
		rm -rf objs
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make clean -C mlx

re : fclean all

.PHONY : re clean fclean libft mlx all