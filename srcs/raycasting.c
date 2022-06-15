/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/15 13:13:21 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(position)
{
	
}

double	ft_raycast(t_game *game, int angle)
{
	double	pos_x;
	double	pos_y;
	double	x_ray;
	double	y_ray;
	double	temp;
	int		obstacle;

	x_ray = 0.0;
	y_ray = 0.0;
	temp = 0.0;
	pos_x = (double)game->info.pos_x;
	pos_y = (double)game->info.pos_y;
	obstacle = 0;
	while (!obstacle)
	{
		if (x_ray < y_ray)
		{
			temp = (game->info.u - fmod(pos_x, game->info.u)) / cos(angle);
			x_ray += temp;
			pos_x += (game->info.u - fmod(pos_x, game->info.u));
			pos_y += temp * sin(90 - angle);
		}
		else
		{
			temp = (10 - fmod(pos_y, 10)) / cos(90 - angle);
			y_ray += temp;
			pos_y += (game->info.u - fmod(pos_y, game->info.u));
			pos_x += temp * sin(angle);
		}
		obstacle = ft_intersection(position);
	}
	plus petit rayon;
}

void	raycasting_engine(t_game *game)
{
	double	ray;
	int		i;

	while (i < 1024)
	{
		angle = formule_de_fou_malade;
		ray = ft_raycast(game, angle);
		ft_drawline(ray, i);
		i++;
	}
}
