/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/01 17:28:58 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	my_color(char *rgb)
{
	char	**colors;
	int		i;
	int		j;
	int		color;
	int		color_tab[3];

	i = 0;
	j = 0;
	color = 0;
	colors = ft_split(rgb, ',');
	color_tab[0] = atoi(colors[0]);
	color_tab[1] = atoi(colors[1]);
	color_tab[2] = atoi(colors[2]);
	
	dprintf(2, "%d\n", color_tab[0]);
	dprintf(2, "%d\n", color_tab[1]);
	dprintf(2, "%d\n", color_tab[2]);
	i = 0;
	while (i < 3)
	{
		color_tab[i] = color | (color_tab[i] << (16 - (i  * 8)));
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
	x = 0;
	i = 0;
	j = 0;
	while (game->info.map[i])
	{
		x = 0;
		j = 0;
		while (game->info.map[i][j])
		{
			if (game->info.map[i][j] == '1')
				my_put_pixel(game, x, y, my_color(game->texture.path[4]));
			if (game->info.map[i][j] == '0')
				my_put_pixel(game, x, y, my_color(game->texture.path[5]));
			x += 24;
			j++;
		}
		y += 24;
		i++;
	}
}

void	my_put_pixel(t_game *game, int map_x, int map_y, int color)
{
	int	x;
	int	y;

	x = 0;
	(void)color;
	while (x < 24)
	{
		y = 0;
		while (y < 24)
		{
			mlx_pixel_put(game->mlx, game->mlx_window,
				x + map_x, y + map_y, color);
			y++;
		}
		x++;
	}
}
