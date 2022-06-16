/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/15 18:20:39 by lnemor           ###   ########lyon.fr   */
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
			x += U;
			j++;
		}
		y += U;
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
	while (x < U)
	{
		y = 0;
		while (y < U)
		{
			if (y == 0 || y == U)
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
			if (x == 0 || x == U)
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

int	ft_intersection(t_game *game, double pos_x, double pos_y)
{
		dprintf(2, "\npos_y:%d\n",(int)pos_y / 24);
		dprintf(2, "pos_x:%d\n",(int)pos_x / 24);
	if (game->info.map[(int)pos_y / U][(int)pos_x / U] == '1')
		return (1);
	return (0);
}

void	draw_player(t_game *game)
{
	double	x;
	double	y;
	double	pos_x;
	double	pos_y;
	double	x_ray;
	double	y_ray;
	double	temp;
	int		obstacle;
	int		i;

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
	x_ray = 0;
	y_ray = 0;
	temp = 0;
	pos_x = game->info.pos_x;
	pos_y = game->info.pos_y;
	obstacle = 0;
	game->info.step = 0;
	i = 0;
	while (i < 1024)
	{	
		while (!obstacle)
		{
			if (x_ray < y_ray)
			{
				temp = (U - fmod(pos_x, U))
					/ sin(game->info.angle + game->info.step);
				x_ray += temp;
				pos_x += (U - fmod(pos_x, U));
				pos_y += temp * cos(game->info.angle + game->info.step);
				dprintf(2, "\nangle 1: %f\n", game->info.angle);
				dprintf(2, "step 1: %f\n", game->info.step);
				dprintf(2, "pos_y 1:%d\n", (int)pos_y/24);
				dprintf(2, "pos_x 1:%d\n", (int)pos_x/24);
			}	
			else
			{
				temp = (U - fmod(pos_y, U))
					* sin(game->info.angle + game->info.step);
				y_ray += temp;
				pos_x += temp * sin(game->info.angle + game->info.step);
				pos_y += (U - fmod(pos_y, U));
				dprintf(2, "\nangle 2: %f\n", game->info.angle);
				dprintf(2, "step 2: %f\n", game->info.step);
				dprintf(2, "pos_y 2:%d\n", (int)pos_y/24);
				dprintf(2, "pos_x 2:%d\n", (int)pos_x/24);
			}
			obstacle = ft_intersection(game, pos_x, pos_y);
		}
		mlx_pixel_put(game->mlx, game->mlx_window, pos_x,
			pos_y, 0xFFFFFF);
		game->info.step += (M_PI / 3) / 1024;
		i++;
	}
}
