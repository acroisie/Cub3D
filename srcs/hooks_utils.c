/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:55:42 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/23 15:44:31 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	forward(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_y + sin(game->info.orientation) \
	/ 5)][(int)(game->info.pos_x + cos(game->info.orientation) / 5)] != '1')
	{
		game->info.pos_x += cos(game->info.orientation) / 5;
		game->info.pos_y += sin(game->info.orientation) / 5;
		ft_display_map(game);
	}
}

void	back(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_y - sin(game->info.orientation) \
	/ 5)][(int)(game->info.pos_x - cos(game->info.orientation) / 5)] != '1')
	{
		game->info.pos_x -= cos(game->info.orientation) / 5;
		game->info.pos_y -= sin(game->info.orientation) / 5;
		ft_display_map(game);
	}
}

void	left(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_y - sin(game->info.orientation \
	+ M_PI_2) / 5)][(int)(game->info.pos_x - cos(game->info.orientation + \
	M_PI_2) / 5)] != '1')
	{
		game->info.pos_x -= cos(game->info.orientation + M_PI_2) / 5;
		game->info.pos_y -= sin(game->info.orientation + M_PI_2) / 5;
		ft_display_map(game);
	}
}

void	right(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_y + sin(game->info.orientation \
	+ M_PI_2) / 5)][(int)(game->info.pos_x + cos(game->info.orientation + \
	M_PI_2) / 5)] != '1')
	{
		game->info.pos_x += cos(game->info.orientation + M_PI_2) / 5;
		game->info.pos_y += sin(game->info.orientation + M_PI_2) / 5;
		ft_display_map(game);
	}
}
