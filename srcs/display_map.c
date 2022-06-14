/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/14 16:41:44 by lnemor           ###   ########lyon.fr   */
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
	if (!colors)// retour d'erreur
		return (0);// retour d'erreur
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
	mlx_destroy_image(game->mlx, game->img.img_ptr);
}

void	my_put_pixel(t_game *game, int map_x, int map_y, int color)
{
	int		x;
	int		y;
	char	*dst;

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

void	draw_player(t_game *game)
{
	int		i;
	int		touched;
	double	x = 0;
	double	ray_h_y = 0;
	double	ray_v_x = 0;
	double	y = 0;
	double	h_intercept = 0;
	double	v_intercept = 0;

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
	i = 0;
	while (i < 2)
	{
		game->info.fov += (M_PI / 3)/ 2;
		touched = 0;
		while (touched == 0)
		{	
			while (h_intercept <= y)
			{
				ray_h_y += 1 - fmod(game->info.pos_y, 1);
				x += ray_h_y * tan(game->info.fov);
				dprintf(2, "debug x : %d\n", (int)x);
				h_intercept = game->info.pos_x + x;
				dprintf(2, "debug hintercept : %d\n", (int)h_intercept);
				if (game->info.map[(int)h_intercept][(int)x] == '1')
					touched = 1;
				mlx_pixel_put(game->mlx, game->mlx_window, x,
					h_intercept, 0xFF0000);
			}
			while (v_intercept <= x)
			{
				ray_v_x += 1 - fmod(game->info.pos_x, 1);
				y += ray_v_x * tan(game->info.fov + game->info.angle);
				v_intercept = game->info.pos_y + y;
				if (game->info.map[(int)v_intercept][(int)y] == '1')
					touched = 1;
				mlx_pixel_put(game->mlx, game->mlx_window, v_intercept,
					y, 0xFF0000);
				dprintf(2, "debug x : %f\n", y);
				dprintf(2, "debug hintercept : %f\n", v_intercept);
			}
		}
		game->info.fov += (M_PI / 3)/ 2;
		i++;
	}
}
