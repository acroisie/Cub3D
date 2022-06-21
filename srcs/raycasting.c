/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/21 17:50:49 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int		ft_intersection(t_game *game, t_vect v1)
{
	if (game->info.map[(int)v1.x][(int)v1.y])
		return (1);
	return (0);
}

void	ft_raycast(t_game *game)
{
	t_vect	v1;
	// t_vect	v2;
	double	temp;
	double	dx;
	// int		obstacle;

	// obstacle = 0;
	v1.x = game->info.pos_x;
	v1.y = game->info.pos_y;
	// v1.lenght = 0;
	// while (!obstacle)
	// {
		if (game->info.orientation < M_PI_2 || \
		game->info.orientation > 3 * M_PI_2)
			dx = UNIT - fmod(v1.x * UNIT, UNIT);
		else
			dx = fmod(v1.x * UNIT, UNIT);
		v1.x += dx;
		temp = dx / cos(game->info.orientation);
		v1.lenght += temp;
		v1.y += dx * tan(M_PI_2);
		// obstacle = ft_intersection(game, v1);
	// }
	ft_draw_line(game, v1.lenght * UNIT);
}
