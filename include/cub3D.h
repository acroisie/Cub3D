/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:08:32 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/23 15:06:08 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_info
{
	char	**map;
}t_info;

typedef struct s_texture
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_window;
	t_info		info;
	t_texture	texture;
}t_game;

t_info	ft_errors_check(int argc, char **argv);
void	ft_put_error(int msg_id);
char	*get_next_line(int fd);

#endif
