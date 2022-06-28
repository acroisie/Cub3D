/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/28 13:29:09 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_my_color(char *rgb)
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
		color = color_tab[i];
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

int	get_pixel_from_texture(t_game *game, int x, int y)
{
	if (x >= 0 && x < UNIT && y >= 0 && y < UNIT)
		return (*(int *)(game->texture.ea + (4 * (int)y) * UNIT) + (4 * (int)x * UNIT));
	return (0xFFFFFFF);
}


void	ft_draw_wall(t_game *game, t_vect vect, int x, double angle)
{
	double	h;
	int		i;
	int		y;
	double	heigth;
	int		xt;
	int		yt;
	int		ratio;

	y = 0;
	xt = x;
	yt = 0;
	heigth = UNIT * 9;
	h = heigth / (fabs(vect.lenght) * \
	cos(fmod(game->info.orientation - angle, 2 * M_PI)));
	i = 0;
	ratio = 0;
	while (i < heigth)
	{
		ratio = UNIT / h;
		if (i > 9 * UNIT)
			break ;
		if (i >= 0 && i <= (heigth / 2) - h / 2)
			my_put_pixel(game, x, y, game->texture.ceiling);
		else if (i > (heigth / 2 - h / 2) && i < (heigth / 2) + h / 2)
		{
			if (game->vector == 'x')
			{
				xt = x;
				yt = y;
				if (game->dir_x == 'R')
					my_put_pixel(game, x, y, get_pixel_from_texture(game, (xt % UNIT), (yt % UNIT)));
				else if (game->dir_x == 'L')
					my_put_pixel(game, x, y, 0x236c87);
			}
			else if (game->vector == 'y')
			{
				if (game->dir_y == 'T')
					my_put_pixel(game, x, y, 0x873e23);
				else if (game->dir_y == 'B')
					my_put_pixel(game, x, y, 0x3a8723);
			}
		}
		else if (i < heigth)
			my_put_pixel(game, x, y, game->texture.floor);
		i++;
		y++;
	}
}
