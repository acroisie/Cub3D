/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:08:32 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/23 12:25:25 by acroisie         ###   ########lyon.fr   */
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

typedef struct s_map
{
	char	**map;
}t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_window;
	t_map	map;
}t_game;

t_map	ft_errors_check(int argc, char **argv);
void	ft_put_error(int msg_id);
char	*get_next_line(int fd);

#endif
