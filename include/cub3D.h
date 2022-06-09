/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:08:32 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/09 11:33:09 by acroisie         ###   ########lyon.fr   */
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
# define BUFFER_SIZE 42
# define CHARSET "10NSEW \n"
# define CHARSET_2 "NSEW"
# define MSG_1 "Argument missing"
# define MSG_2 "Too many arguments"
# define MSG_3 "Wrong map exstension, you must provide a .cub"
# define MSG_4 "You must provide a file, not a folder"
# define MSG_5 "Cannot open the file"
# define MSG_6 "File is empty"
# define MSG_7 "Wrong texture path"
# define MSG_8 "Wrong color format"
# define MSG_9 "Wrong character used, you must use \"N,S,E,W,1,0,' ',\\n\""
# define MSG_10 "Cut a map by newline is forbidden"
# define MSG_11 "Map is invalid"

typedef struct s_info
{
	char	**map;
	double	pos_x;
	double	pos_y;
	double	vect_p_x;
	double	vect_p_y;
	double	angle;
	double	ray_len_x;
	double	ray_len_y;
	int		size_h_map;
	int		size_l_map;
	char	pov;
	double	rays[1024];
	double	fov;
}t_info;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}t_img;

typedef struct s_texture
{
	char	**path;
	char	**colors;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	char	*floor;
	char	*ceiling;
}t_texture;

typedef struct s_game
{
	int			fd;
	void		*mlx;
	void		*mlx_window;
	t_info		info;
	t_img		img;
	t_texture	texture;
}t_game;

t_game	ft_errors_check(int argc, char **argv);
void	ft_opening_check(char *argv, t_game *game);
void	ft_folder_check(char *argv, t_game *game);
void	ft_extension_check(char *argv, t_game *game);
int		ft_count_line(char *argv, t_game *game);
void	ft_textures_check(char *argv, t_game *game);
void	ft_store_texture(char *line, int i, int out, t_game *game);
void	ft_put_error(char *err_msg, int fd, t_game *game);
int		the_luther(int i, char *temp);
char	*get_next_line(int fd);
int		ft_init_check_map(t_game *game);
int		ft_destlen(char **s);
void	ft_walls_check(char **map, t_game *game);
void	ft_supress_line_break(char *str);
void	ft_display_map(t_game *game);
void	my_put_pixel(t_game *game, int map_x, int map_y, int color);
void	ft_pos_player(t_game *game);
void	draw_player(t_game *game);
int		ft_clean_exit(t_game *game);
int		ft_key_hook(int keycode, t_game *game);

#endif
