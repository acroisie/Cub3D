/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:16:29 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/30 15:55:23 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_wall_y(t_game	*game, t_vect *vect, int x, int y)
{
	game->y_on_tex = game->y_wall / game->h_of_wall;
	if (game->dir_x == 'E')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(&game->texture.ea,
				fmod(vect->y, 1) * game->texture.ea.width, \
				fmod(game->y_on_tex * game->texture.ea.width, \
				game->texture.ea.width)));
	else if (game->dir_x == 'W')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(&game->texture.we,
				fmod(vect->y, 1) * game->texture.we.width, \
				fmod(game->y_on_tex * game->texture.we.width, \
				game->texture.we.width)));
}

void	draw_wall_x(t_game	*game, t_vect *vect, int x, int y)
{
	game->y_on_tex = game->y_wall / game->h_of_wall;
	if (game->dir_y == 'N')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(&game->texture.no,
				fmod(vect->x, 1) * game->texture.no.width, \
				fmod(game->y_on_tex * game->texture.no.width, \
				game->texture.no.width)));
	else if (game->dir_y == 'S')
		my_put_pixel(game, x, y,
			get_pixel_from_texture(&game->texture.so,
				fmod(vect->x, 1) * game->texture.so.width, \
				fmod(game->y_on_tex * game->texture.so.width, \
				game->texture.so.width)));
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
	int		y;

	y = -1;
	game->h_of_wall = game->height / (fabs(vect.lenght) * \
	cos(fmod(game->info.orientation - angle, 2 * M_PI)));
	game->y_wall = 0;
	if (game->h_of_wall > game->height)
		game->y_wall = (game->h_of_wall - game->height) / 2;
	while (++y < game->height)
	{
		if (y >= 0 && y <= (game->height / 2) - game->h_of_wall / 2)
			my_put_pixel(game, x, y, game->texture.ceiling);
		else if (y > (game->height / 2 - game->h_of_wall / 2)
			&& y < (game->height / 2) + game->h_of_wall / 2)
		{
			draw_walls(game, &vect, x, y);
			game->y_wall++;
		}
		else if (y < game->height)
			my_put_pixel(game, x, y, game->texture.floor);
	}
}
