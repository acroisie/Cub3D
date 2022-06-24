/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 14:07:16 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/24 15:38:24 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_map(t_game *game)
{
	game->img.img_ptr = mlx_new_image(game->mlx, 16 * UNIT, 12 * UNIT);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr, \
	&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
}

void	ft_draw_grid(t_game *game, int map_x, int map_y, int color)
{
	int		x;
	int		y;

	x = 0;
	while (x < UNIT)
	{
		y = 0;
		while (y < UNIT)
		{
			if (y == 0 || y == UNIT)
				my_put_pixel(game, x + map_x, y + map_y, 68248);
			else
				my_put_pixel(game, x + map_x, y + map_y, color);
			if (x == 0 || x == UNIT)
				my_put_pixel(game, x + map_x, y + map_y, 68248);
			y++;
		}
		x++;
	}
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = -1;
	while (game->info.map[++i])
	{
		x = 0;
		j = -1;
		while (game->info.map[i][++j])
		{
			if (game->info.map[i][j] == '1')
				ft_draw_grid(game, x, y, my_color(game->texture.path[4]));
			if (game->info.map[i][j] == '0' || game->info.map[i][j] == 'N'
				|| game->info.map[i][j] == 'S' || game->info.map[i][j] == 'E'
				|| game->info.map[i][j] == 'W')
				ft_draw_grid(game, x, y, my_color(game->texture.path[5]));
			x += UNIT;
		}
		y += UNIT;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, \
	game->img.img_ptr, 0, 0);
}
