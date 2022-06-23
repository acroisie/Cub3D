/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:38:33 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/23 14:10:29 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	turn_left(t_game *game)
{
	game->info.orientation -= 0.1;
	if (game->info.orientation < 0)
		game->info.orientation = 2 * M_PI;
	ft_display_map(game);
}

void	turn_right(t_game *game)
{
	game->info.orientation += 0.1;
	if (game->info.orientation > 2 * M_PI)
		game->info.orientation = 0;
	ft_display_map(game);
}

int	ft_key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		ft_clean_exit(game);
	if (keycode == 13 || keycode == 126)
		forward(game);
	if (keycode == 1 || keycode == 125)
		back(game);
	if (keycode == 0)
		left(game);
	if (keycode == 2)
		right(game);
	if (keycode == 124)
		turn_right(game);
	if (keycode == 123)
		turn_left(game);
	return (0);
}
