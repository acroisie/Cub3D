/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/20 16:30:20 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

double	ft_raycast(t_game *game, int angle)
{
	t_vect	vx;
	t_vect	vy;
	double	temp;
	int		obstacle;

	vx.lenght = 0;
	vy.lenght = 0;
	obstacle = 0;
	while (!obstacle)
	{
		if (vx.lenght < vy.lenght)
		{
			temp = (UNIT - fmod(game->info.pos_x, UNIT)) / cos(game->info.orientation);
			vx.lenght += temp;
		}
		else
		{
			temp = (UNIT - fmod(game->info.pos_x, UNIT)) / sin(game->info.orientation);
			vx.lenght += temp;
		}
		obstacle = ft_intersection(position);
	}
	plus petit rayon;
}