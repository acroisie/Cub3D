/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/22 17:10:07 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(t_game *game, t_vect v1)
{
	if (game->info.map[(int)v1.y][(int)v1.x])
	{
		if (game->info.map[(int)v1.y][(int)v1.x] == '1')
		{
			dprintf(2, "Debug 2; v1.x = %d, v2.y = %d\n", (int)v1.x, (int)v1.y);
				return (1);
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

void	ft_init_rays(t_vect *v1, t_game	*game, double angle)
{
	v1->x = game->info.pos_x;
	v1->y = game->info.pos_y;
	v1->lenght = 0;
	v1->y_sign = 1;
	if (angle > M_PI)
		v1->y_sign = -1;
	if (angle < M_PI_2 || angle > 3 * M_PI_2)
	{
		v1->delta = 1 - fmod(v1->x, 1);
		v1->x_sign = 1;
	}
	else
	{
		v1->delta = fmod(v1->x, 1);
		v1->x_sign = -1;
	}
}

void	ft_raycast(t_game *game, double angle)
{
	t_vect	v1;
	double	temp;
	int		obstacle;

	ft_init_rays(&v1, game, angle);
	obstacle = 0;
	angle = ft_init_angle(angle);
	while (!obstacle)
	{
		v1.x += ((0.01 + v1.delta) * v1.x_sign);
		temp = v1.delta / cos(angle);
		v1.y += (v1.y_sign * (temp * sin(angle)));
		v1.lenght += temp;
		obstacle = ft_intersection(game, v1);
		v1.delta = 1;
	}
	ft_draw_line(game, v1.lenght);
}
