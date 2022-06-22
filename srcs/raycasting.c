/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/22 15:32:18 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(t_game *game, t_vect v1)
{
	if (v1.y < 12 && v1.y >= 0)
	{
		if (v1.x < 16 && v1.x >= 0)
		{
			if (game->info.map[(int)v1.y][(int)v1.x])
			{	
				if (game->info.map[(int)v1.y][(int)v1.x] == '1')
				{
					dprintf(2, "Debug 2; v1.x = %d, v2.y = %d\n", (int)v1.x, (int)v1.y);
						return (1);
				}
			}
		}
	}
	return (0);
}

double	ft_init_angle(double angle)
{
	if (angle > M_PI_2 && angle <= M_PI)
		angle = M_PI - angle;
	if (angle > M_PI && angle <= 3 * M_PI_2)
		angle = angle - M_PI;
	if (angle > 3 * M_PI_2 && angle <= 2 * M_PI)
		angle = 2 * M_PI - angle;
	return (angle);
}

void	ft_raycast(t_game *game, double angle)
{
	t_vect	v1;
	double	temp;
	double	dx;
	int		obstacle;
	int		sign;
	int		y_sign;

	obstacle = 0;
	v1.x = game->info.pos_x;
	v1.y = game->info.pos_y;
	v1.lenght = 0;
	if (angle < M_PI_2 || angle > 3 * M_PI_2)
	{
		dx = 1 - fmod(v1.x, 1);
		sign = 1;
	}
	else
	{
		dx = fmod(v1.x, 1);
		sign = -1;
	}
	y_sign = 1;
	if (angle > M_PI)
		y_sign = -1;
	angle = ft_init_angle(angle);
	while (!obstacle)
	{
		v1.x += (dx * sign);
		temp = dx / cos(angle);
		v1.y += (y_sign * (temp * sin(angle)));
		v1.lenght += temp;
		obstacle = ft_intersection(game, v1);
		dx = 1;
	}
	ft_draw_line(game, v1.lenght);
}
