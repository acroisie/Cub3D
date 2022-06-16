/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:55:42 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/16 16:26:06 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	forward(t_game *game)
{
	// game->info.pos_y -= sin(game->info.r_angle + (game->info.fov / 2));
	// game->info.pos_x -= cos(game->info.r_angle + (game->info.fov / 2));
	game->info.pos_y -= 0.1;
	ft_display_map(game);
}

void	back(t_game *game)
{
	// game->info.pos_y += sin(game->info.r_angle + (game->info.fov / 2));
	// game->info.pos_x += cos(game->info.r_angle + (game->info.fov / 2));
	game->info.pos_y += 0.1;
	ft_display_map(game);
}

void	left(t_game *game)
{
	// game->info.pos_y -= sin(game->info.r_angle + (game->info.fov / 2) - M_PI_2);
	// game->info.pos_x -= cos(game->info.r_angle + (game->info.fov / 2) - M_PI_2);
	game->info.pos_x -= 0.1;
	ft_display_map(game);
}

void	right(t_game *game)
{
	// game->info.pos_y -= sin(game->info.r_angle + (game->info.fov / 2) + M_PI_2);
	// game->info.pos_x -= cos(game->info.r_angle + (game->info.fov / 2) + M_PI_2);
	game->info.pos_x += 0.1;
	ft_display_map(game);
}
