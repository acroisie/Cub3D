/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:38:33 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/16 21:11:59 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	forward(t_game *game)
{
	game->info.pos_y += sin((game->info.r_angle));
	game->info.pos_x += cos((game->info.r_angle));
	ft_display_map(game);
	draw_player(game);
}

void	back(t_game *game)
{
	game->info.pos_y -= sin((game->info.r_angle));
	game->info.pos_x -= cos((game->info.r_angle));
	ft_display_map(game);
	draw_player(game);
}

void	left(t_game *game)
{
	game->info.pos_y += sin((game->info.r_angle) - (M_PI_2));
	game->info.pos_x += cos((game->info.r_angle) - (M_PI_2));
	ft_display_map(game);
	draw_player(game);
}

void	right(t_game *game)
{
	game->info.pos_y += sin((game->info.r_angle) + (M_PI_2));
	game->info.pos_x += cos((game->info.r_angle) + (M_PI_2));
	ft_display_map(game);
	draw_player(game);
}

void	turn_left(t_game *game)
{
	if (game->info.r_angle <= (-2 * M_PI))
		game->info.r_angle = 0;
	game->info.r_angle -= 0.05;
	dprintf(2, "angle hook left: %f\n", game->info.r_angle);
	dprintf(2, "mpi: %f\n", 2 * M_PI);
	ft_display_map(game);
	draw_player(game);
}

void	turn_right(t_game *game)
{
	if (game->info.r_angle >= 2 * M_PI)
		game->info.r_angle = 0;
	game->info.r_angle += 0.05;
	dprintf(2, "angle hook right: %f\n", game->info.r_angle);
	ft_display_map(game);
	draw_player(game);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_clean_exit(game);
	if (keycode == 13 || keycode == 126)
		forward(game);
	if (keycode == 0)
		left(game);
	if (keycode == 123)
		turn_left(game);
	if (keycode == 2)
		right(game);
	if (keycode == 124)
		turn_right(game);
	if (keycode == 1 || keycode == 125)
		back(game);
	return (0);
}
