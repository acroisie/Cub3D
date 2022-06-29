/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:16:29 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/29 15:16:54 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_wall_y(t_game	*game, t_vect *vect, int x, int y)
{
	if (game->dir_x == 'E')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(game->texture.ea.img_addr,
				fmod(vect->y, 1) * UNIT, fmod(game->y_on_tex, UNIT)));
	else if (game->dir_x == 'W')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(game->texture.we.img_addr,
				fmod(vect->y, 1) * UNIT, fmod(game->y_on_tex, UNIT)));
}

void	draw_wall_x(t_game	*game, t_vect *vect, int x, int y)
{
	if (game->dir_y == 'N')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(game->texture.no.img_addr,
				fmod(vect->x, 1) * UNIT, fmod(game->y_on_tex, UNIT)));
	else if (game->dir_y == 'S')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(game->texture.so.img_addr,
				fmod(vect->x, 1) * UNIT, fmod(game->y_on_tex, UNIT)));
}

void	draw_walls(t_game *game, t_vect *vect, int x, int y)
{
	if (game->vector == 'y')
		draw_wall_y(game, vect, x, y);
	else if (game->vector == 'x')
		draw_wall_x(game, vect, x, y);
}

void	ft_draw_wall(t_game *game, t_vect vect, int x, double angle)
{
	double	h_of_wall;
	int		y;
	double	y_wall;

	y = -1;
	h_of_wall = game->height / (fabs(vect.lenght) * \
	cos(fmod(game->info.orientation - angle, 2 * M_PI)));
	y_wall = 0;
	if (h_of_wall > game->height)
		y_wall = (h_of_wall - game->height) / 2;
	while (++y < game->height)
	{
		if (y >= 0 && y <= (game->height / 2) - h_of_wall / 2)
			my_put_pixel(game, x, y, game->texture.ceiling);
		else if (y > (game->height / 2 - h_of_wall / 2)
			&& y < (game->height / 2) + h_of_wall / 2)
		{
			game->y_on_tex = (y_wall * UNIT) / h_of_wall;
			draw_walls(game, &vect, x, y);
			y_wall++;
		}
		else if (y < game->height)
			my_put_pixel(game, x, y, game->texture.floor);
	}
}
