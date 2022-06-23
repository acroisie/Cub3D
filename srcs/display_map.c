/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/23 15:55:50 by acroisie         ###   ########lyon.fr   */
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
	ft_free_split(colors);
	return (color);
}

void	my_put_pixel(t_game *game, int map_x, int map_y, int color)
{
	int		x;
	int		y;
	char	*dst;

	x = 0;
	while (x < UNIT)
	{
		y = 0;
		while (y < UNIT)
		{
			if (y == 0 || y == UNIT)
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line \
				+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = 68248;
			}
			else
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line \
				+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = color;
			}
			if (x == 0 || x == UNIT)
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line \
				+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = 68248;
			}
			y++;
		}
		x++;
	}
}

void	draw_player(t_game *game)
{
	double	x;
	double	y;

	x = 0;
	while (x < 6)
	{
		y = 0;
		while (y < 6)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x + \
			(game->info.pos_x * UNIT) - 3, y + \
			(game->info.pos_y * UNIT) - 3, 5454548);
			y++;
		}
		x++;
	}
}

void	ft_draw_line(t_game *game, double angle, double lenght)
{
	double	x;
	double	y;
	double	i;

	lenght *= UNIT;
	x = game->info.pos_x * UNIT;
	y = game->info.pos_y * UNIT;
	i = 0;
	if (lenght > 0)
	{
		while (i < lenght)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x, y, 0xFF0000);
			x += cos(angle);
			y += sin(angle);
			i++;
		}	
	}
	else
	{
		while (i > lenght)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x, y, 0xFF0000);
			x += cos(angle);
			y += sin(angle);
			i--;
		}
	}
}

void	ft_display_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;
	double	step;


	y = 0;
	i = 0;
	game->img.img_ptr = mlx_new_image(game->mlx, 16 * UNIT, 12 * UNIT);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr, \
	&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
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
			x += UNIT;
			j++;
		}
		y += UNIT;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, \
	game->img.img_ptr, 0, 0);
	draw_player(game);
	step = FOV / 150;
	int ray_ind = 0;
	double angle = fmod(game->info.orientation - (FOV / 2), 2 * M_PI);
	if (angle < 0)
		angle = 2 * M_PI + angle;
	while (ray_ind < 150)
	{
		ft_draw_line(game, angle, ft_raycast(game, angle));
		angle += step;
		angle = fmod(angle, 2 * M_PI);
		ray_ind++;
	}
	mlx_destroy_image(game->mlx, game->img.img_ptr);
}
