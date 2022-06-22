/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/22 13:20:48 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(t_game *game, t_vect v1)
{
	dprintf(2, "Debug 2; v1.x = %d, v2.y = %d map = ", (int)v1.x, (int)v1.y);
	// if (v1.y < 12 && v1.y >= 0)
	// 	if (v1.x < 16 && v1.x >= 0)
			if (game->info.map[(int)v1.y][(int)v1.x])
				if (game->info.map[(int)v1.y][(int)v1.x] == '1')
					return (1);
	return (0);
}

double	ft_init_angle(double angle)
{
	if (angle > M_PI_2 && angle < M_PI)
		angle = M_PI - angle;
	if (angle > M_PI && angle < 3 * M_PI_2)
		angle = angle - M_PI;
	if (angle > 3 * M_PI_2 && angle < 2 * M_PI)
		angle = 2 * M_PI - angle;
	return (angle);
}

void	ft_raycast(t_game *game, double angle)
{
	t_vect	v1;
	// t_vect	v2;
	double	temp;
	double	dx;
	int		obstacle;

	obstacle = 0;
	v1.x = game->info.pos_x;
	v1.y = game->info.pos_y;
	v1.lenght = 0;
	angle = ft_init_angle(angle);
	while (!obstacle)
	{
		if (angle > M_PI_2 && \
		angle < 3 * M_PI_2)
			dx = 1 - fmod(v1.x, 1);
		else
			dx = fmod(v1.x, 1);
		// double tmp = game->info.orientation;
		// game->info.orientation = angle;
		// ft_draw_line(game , 1); //Angle
		// game->info.orientation = tmp;
		if (angle > M_PI_2 && \
		angle < 3 * M_PI_2)
			v1.x += dx;
		else
			v1.x += -dx;
		// v1.x += dx;
		temp = dx / cos(angle);
		v1.y += (temp * sin(angle));
		v1.lenght += temp;
		obstacle = ft_intersection(game, v1);
	}
	ft_draw_line(game, v1.lenght);
}
