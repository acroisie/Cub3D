/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/16 17:35:33 by acroisie         ###   ########lyon.fr   */
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
			// if (y == 0 || y == UNIT)
			// {
			// 	dst = game->img.img_addr + ((y + map_y) * game->img.size_line \
			// 	+ (x + map_x) * (game->img.bits_per_pixel / 8));
			// 	*(unsigned int *)dst = 68248;
			// }
			// else
			// {
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line \
				+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = color;
			// }
			// if (x == 0 || x == UNIT)
			// {
			// 	dst = game->img.img_addr + ((y + map_y) * game->img.size_line \
			// 	+ (x + map_x) * (game->img.bits_per_pixel / 8));
			// 	*(unsigned int *)dst = 68248;
			// }
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
			mlx_pixel_put(game->mlx, game->mlx_window, (x + (UNIT / 2) + \
			(game->info.pos_x * UNIT) - 3), y + ((UNIT / 2) + \
			(game->info.pos_y * UNIT) - 3), 5454548);
			y++;
		}
		x++;
	}
}

void	draw_line(t_game *game, double x2, double y2)
{
	double	dx;
	double	dy;
	double	x;
	double	y;
	double	step;
	double	i;

	printf("x1; %f, y1; %f\n", game->info.pos_x, game->info.pos_y);
	printf("x2; %f, y2; %f\n", x2, y2);
	dx = fabs(x2 - game->info.pos_x * UNIT);
	dy = fabs(y2 - game->info.pos_y * UNIT);
	if (dx >= dy)
		step = dx;
	else
		step = dy;
	dx = dx / step;
	dy = dy / step;
	x = game->info.pos_x * UNIT;
	y = game->info.pos_y * UNIT;
	i = 1;
	while (i <= step)
	{
		mlx_pixel_put(game->mlx, game->mlx_window, x, y, 0);
		x += dx;
		y += dy;
		i++;
	}
}

void	ft_display_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

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
	draw_line(game, game->info.pos_x * UNIT, game->info.pos_y * UNIT - 100);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
}
