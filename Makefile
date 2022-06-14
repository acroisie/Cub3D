# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 08:07:28 by acroisie          #+#    #+#              #
#    Updated: 2022/06/14 11:33:26 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC = gcc 

CC_FLAGS = -Wall -Werror -Wextra

NAME := cub3D

		
		
SRCS := main.c \
		error_check_args.c \
		error_check_map.c \
		error_check_textures.c \
		error_check_utils.c \
		error_check_walls.c \
		error_check.c \
		get_next_line.c \
		raycasting.c
		
OBJS := $(SRCS:.c=.o)

all : libft mlx $(NAME)

$(NAME):		$(addprefix objs/, $(OBJS))
					$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit
#					$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a mlx/libmlx.a -framework OpenGL -framework AppKit -g3 -fsanitize=address

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