/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:36:41 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/27 16:02:43 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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

void	ft_init_ray_x(t_vect *v1, t_game *game, double angle)
{
	v1->x = game->info.pos_x;
	v1->y = game->info.pos_y;
	v1->lenght = 0;
	v1->y_sign = 1;
	game->dir_y = 'T';
	if (angle > M_PI)
	{
		v1->y_sign = -1;
		game->dir_y = 'B';
	}
	if (angle < M_PI_2 || angle > 3 * M_PI_2)
	{
		v1->delta = 1 - fmod(v1->x, 1);
		v1->x_sign = 1;
		game->dir_x = 'R';
	}
	else
	{
		v1->delta = fmod(v1->x, 1);
		v1->x_sign = -1;
		game->dir_x = 'L';
	}
}

void	ft_init_ray_y(t_vect *v2, t_game *game, double angle)
{
	v2->x = game->info.pos_x;
	v2->y = game->info.pos_y;
	v2->lenght = 0;
	if (angle > M_PI)
	{
		v2->delta = fmod(v2->y, 1);
		v2->y_sign = -1;
		game->dir_y = 'T';
	}
	else
	{
		v2->delta = 1 - fmod(v2->y, 1);
		v2->y_sign = 1;
		game->dir_y = 'B';
	}
	if (angle < M_PI_2 || angle > 3 * M_PI_2)
	{
		v2->x_sign = 1;
		game->dir_x = 'L';
	}
	else
	{
		v2->x_sign = -1;
		game->dir_x = 'R';
	}
}
