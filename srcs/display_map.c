/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/03 15:33:10 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	my_color(char *rgb)
{
	char	**colors;
	int		i;
	int		color;
	int		color_tab[3];

	i = 0;
	color = 0;
	colors = ft_split(rgb, ',');
	color_tab[0] = atoi(colors[0]);
	color_tab[1] = atoi(colors[1]);
	color_tab[2] = atoi(colors[2]);
	i = 0;
	while (i < 3)
	{
		color_tab[i] = color | (color_tab[i] << (16 - (i * 8)));
		color += color_tab[i];
		i++;
	}
	return (color);
}

void	ft_display_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	game->img.img_ptr = mlx_new_image(game->mlx, 600, game->info.size_h_map);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.size_line,
			&game->img.endian);
	while (game->info.map[i])
	{
		x = 0;
		j = 0;
		while (game->info.map[i][j])
		{
			if (game->info.map[i][j] == '1')
				my_put_pixel(game, x, y, my_color(game->texture.path[4]));
			if (game->info.map[i][j] == '0' || game->info.map[i][j] == 'N'
				|| game->info.map[i][j] == 'S' || game->info.map[i][j] == 'E'
				|| game->info.map[i][j] == 'W')
				my_put_pixel(game, x, y, my_color(game->texture.path[5]));
			x += 24;
			j++;
		}
		y += 24;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.img_ptr, 0, 0);
}

void	my_put_pixel(t_game *game, int map_x, int map_y, int color)
{
	int		x;
	int		y;
	char 	*dst;

	x = 0;
	(void)color;
	while (x < 24)
	{
		y = 0;
		while (y < 24)
		{
			if (y == 0 || y == 24)
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line
						+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = 68248;
			}
			else
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line
						+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = color;
			}
			if (x == 0 || x == 24)
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line
						+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = 68248;
			}
			y++;
		}
		x++;
	}
}

void	draw_player(t_game *game, char pov)
{
	int		x;
	int		y;
	int		wall_x;
	int		wall_y;

	x = 0;
	while (x < 5)
	{
		y = 0;
		while (y < 5)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x + game->info.pos_x,
				y + game->info.pos_y, 5454548);
			y++;
		}
		x++;
	}
	x = 0;
	y = 0;
	if (pov == 'E')
	{
		while (x < 30)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x + game->info.pos_x,
				y + game->info.pos_y, 5454548);
			x++;
		}
	}
	else if (pov == 'O')
	{
		while (x > -30)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x + game->info.pos_x,
				y + game->info.pos_y, 5454548);
			x--;
		}
	}
	else if (pov == 'N')
	{
		game->info.vect_p_x = game->info.pos_x + (x * cos(game->info.angle));
		game->info.vect_p_y = game->info.pos_y + (y * sin(game->info.angle));
		wall_x = (int)game->info.vect_p_x / 24;
		wall_y = (int)game->info.vect_p_y / 24;
		while (1)
		{
			if (game->info.map[wall_y][wall_x] == '1')
				break;
			game->info.vect_p_x = game->info.pos_x + (x * cos(game->info.angle));
			game->info.vect_p_y = game->info.pos_y + (y * sin(game->info.angle));
			mlx_pixel_put(game->mlx, game->mlx_window, game->info.vect_p_x,
				game->info.vect_p_y, 5454548);
			wall_x = (int)game->info.vect_p_x / 24;
			wall_y = (int)game->info.vect_p_y / 24;
			x++;
			y++;
		}
		game->info.ray_len = (game->info.pos_x - game->info.vect_p_x)
			/ (x * cos(game->info.angle));
	}
	else if (pov == 'S')
	{
		while (y < 30)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x + game->info.pos_x,
				y + game->info.pos_y, 5454548);
			y++;
		}
	}
}
