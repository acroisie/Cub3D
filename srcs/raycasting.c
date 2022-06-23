/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/23 09:04:46 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(t_game *game, t_vect *v1)
{
	dprintf(2, "Debug 2; v1.x = %d, v1.y = %d\n", (int)v1->x, (int)v1->y);
	// dprintf(2, "Debug 2; v2.x = %d, v2.y = %d\n", (int)v2->x, (int)v2->y);
	// if (game->info.map[(int)v2->y][(int)v2->x])
	// 	if (game->info.map[(int)v2->y][(int)v2->x] == '1')
	if (game->info.map[(int)v1->y][(int)v1->x])
		if (game->info.map[(int)v1->y][(int)v1->x] == '1')
			return (1);
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

void	ft_init_ray_x(t_vect *v1, t_game	*game, double angle)
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

void	ft_init_ray_y(t_vect *v2, t_game	*game, double angle)
{
	v2->x = game->info.pos_x;
	v2->y = game->info.pos_y;
	v2->lenght = 0;
	if (angle > M_PI)
	{
		v2->delta = fmod(v2->y, 1);
		v2->y_sign = -1;
	}
	else
	{
		v2->delta = 1 - fmod(v2->y, 1);
		v2->y_sign = 1;
	}
	if (angle < M_PI_2 || angle > 3 * M_PI)
		v2->x_sign = 1;
	else
		v2->x_sign = -1;
}

void	ft_raycast(t_game *game, double angle)
{
	// t_vect	v1;
	t_vect	v2;
	double	temp;
	int		obstacle;

	// ft_init_ray_x(&v1, game, angle);
	ft_init_ray_y(&v2, game, angle);
	obstacle = 0;
	angle = ft_init_angle(angle);
	temp = 0;
	while (!obstacle)
	{
		// if (v1.lenght < v2.lenght)
		// {
			// v1.x += ((0.01 + v1.delta) * v1.x_sign);
			// temp = v1.delta / cos(angle);
			// v1.y += (v1.y_sign * (temp * sin(angle)));
			// v1.lenght += temp;
			// v1.delta = 1;
		// }
		// else
		// {
			v2.y += ((0.01 + v2.delta) * v2.y_sign);
			temp = v2.delta / sin(angle);
			v2.x += (v2.x_sign * (temp * cos(angle)));
			v2.lenght += temp;
			v2.delta = 1;
		// }
		obstacle = ft_intersection(game, &v2);
	}
	ft_draw_line(game, v2.lenght);
	// ft_draw_line(game, v2.lenght);
}
