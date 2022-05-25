/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:08:32 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/25 11:16:02 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
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
	char	**path;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	char	*floor;
	char	*ceiling;
}t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_window;
	t_info		info;
	t_texture	texture;
}t_game;

t_game	ft_errors_check(int argc, char **argv);
int		ft_opening_check(char *argv);
int		ft_folder_check(char *argv);
int		ft_extension_check(char *argv);
int		ft_count_line(char *argv);
void	ft_textures_check(char *argv, t_game *game);
void	ft_put_error(int msg_id);
char	*get_next_line(int fd);

#endif
