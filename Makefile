# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 08:07:28 by acroisie          #+#    #+#              #
#    Updated: 2022/05/23 12:26:10 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc 

CC_FLAGS = -Wall -Werror -Wextra

NAME := cub3D

SRCS := errors_check_args.c \
		get_next_line \
		main.c

OBJS := $(SRCS:.c=.o)

all : libft mlx $(NAME)

$(NAME):		$(addprefix objs/, $(OBJS))
					$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit

objs/%.o:		srcs/%.c include/cub3D.h libft/libft.a mlx/libmlx.a Makefile
					@mkdir -p objs
					$(CC) $(CC_FLAGS) -c $< -o $@
					
libft :	
		$(MAKE) -C libft

mlx :	
		$(MAKE) -C mlx

clean :
		rm -rf objs
		make clean -C libft
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		make fclean -C libft
		make clean -C mlx

re : fclean all

.PHONY : re clean fclean libft mlx all