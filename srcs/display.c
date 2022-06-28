/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/28 18:09:24 by lnemor           ###   ########lyon.fr   */
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
	return (*(int *)(game->texture.ea.img_ptr \
				+ (4 * 256 * y) \
				+ 4 * x));
	return (0xFFFFFFF);
}

void	ft_draw_wall(t_game *game, t_vect vect, int x, double angle)
{
	double	h_of_wall;
	int		y;
	double	heigth;
	double		y_wall;

	y = 0;
	y_wall = 0;
	heigth = UNIT * 9;
	h_of_wall = heigth / (fabs(vect.lenght) * \
	cos(fmod(game->info.orientation - angle, 2 * M_PI)));
	while (y < heigth)
	{
		if (y > 9 * UNIT)
			break ;
		if (y >= 0 && y <= (heigth / 2) - h_of_wall / 2)
			my_put_pixel(game, x, y, game->texture.ceiling);
		else if (y > (heigth / 2 - h_of_wall / 2) && y < (heigth / 2) + h_of_wall / 2)
		{
			y_wall = y_wall * UNIT / h_of_wall;
			if (game->vector == 'y')
			{
				if (game->dir_x == 'E')
					my_put_pixel(game, x, y, 0x236c87);
				else if (game->dir_x == 'W')
					my_put_pixel(game, x, y, 0x873e23);
			}
			else if (game->vector == 'x')
			{
				if (game->dir_y == 'N')
					my_put_pixel(game, x, y, get_pixel_from_texture(game,
							fmod(vect.x, UNIT), fmod(y_wall, UNIT)));
				else if (game->dir_y == 'S')
					my_put_pixel(game, x, y, 0x3a8723);
			}
			y_wall++;
		}
		else if (y < heigth)
			my_put_pixel(game, x, y, game->texture.floor);
		y++;
	}
}
