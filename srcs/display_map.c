/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/24 16:32:47 by lnemor           ###   ########lyon.fr   */
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

void	my_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.img_addr + y * game->img.size_line \
	+ x * (game->img.bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void	ft_draw_player(t_game *game)
{
	double	x;
	double	y;

	x = 0;
	while (x < 6)
	{
		y = 0;
		while (y < 6)
		{
			my_put_pixel(game, x + \
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
	while (i < lenght)
	{
		my_put_pixel(game, x, y, 0xFF0000);
		x += cos(angle);
		y += sin(angle);
		i++;
	}	
}

void	ft_draw_wall(t_game *game, double lenght, int x)
{
	double	h;
	int		i;
	int		y;
	double	heigth;

	y = 0;
	heigth = UNIT * 12;
	h = heigth / lenght;
	//dprintf(2, "h : %f\n", h);
	i = 0;
	while (i < heigth)
	{
		if (i > 12 * UNIT)
			break ;
		if (i >= 0 && i <= (heigth / 2) - h / 2)
			my_put_pixel(game, x, y, 0x1E81B0);
		else if (i > (heigth / 2 - h / 2) && i < (heigth / 2) + h / 2)
			my_put_pixel(game, x, y, 0xEEEEE4);
		else if (i < heigth)
			my_put_pixel(game, x, y, 0xE28743);
		i++;
		y++;
	}
}

void	ft_display_map(t_game *game)
{
	double	step;
	int		ray_ind;
	double	angle;

	ft_draw_map(game);
	angle = fmod(game->info.orientation - (FOV / 2), 2 * M_PI);
	ray_ind = 0;
	ft_draw_player(game);
	step = FOV / 1024;
	if (angle < 0)
		angle = 2 * M_PI + angle;
	while (ray_ind < 1024)
	{
		ft_draw_wall(game, ft_raycast(game, angle), ray_ind);
		angle += step;
		angle = fmod(angle, 2 * M_PI);
		ray_ind++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, \
	game->img.img_ptr, 0, 0);
}
