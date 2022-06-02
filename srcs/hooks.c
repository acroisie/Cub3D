/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:38:33 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/02 18:24:53 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	forward(t_game *game)
{
	game->info.pos_y -= 1;
	ft_display_map(game);
	draw_player(game, game->info.pov);
}

void	back(t_game *game)
{
	game->info.pos_y += 1;
	ft_display_map(game);
	draw_player(game, game->info.pov);
}

void	left(t_game *game)
{
	game->info.pos_x -= 1;
	ft_display_map(game);
	draw_player(game, game->info.pov);
}

void	right(t_game *game)
{
	game->info.pos_x += 1;
	ft_display_map(game);
	draw_player(game, game->info.pov);
}

void	turn_left(t_game *game)
{
	game->info.angle -= 0.08;
	//dprintf(2, "%f\n", game->info.angle);
	ft_display_map(game);
	ft_display_map(game);
	draw_player(game, game->info.pov);
}

void	turn_right(t_game *game)
{
	game->info.angle += 0.08;
	ft_display_map(game);
	draw_player(game, game->info.pov);
}


int	ft_key_hook(int keycode, t_game *game)
{
	dprintf(2, "%d\n", keycode);
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
