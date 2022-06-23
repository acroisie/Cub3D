/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/23 13:53:52 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(t_game *game, t_vect *ray)
{
	if (ray->y < 0)
		ray->y = 0;
	else if (ray->y > 11)
		ray->y = 11;
	if (ray->x < 0)
		ray->x = 0;
	else if (ray->x > 15)
		ray->x = 15;
	if (game->info.map[(int)ray->y][(int)ray->x])
		if (game->info.map[(int)ray->y][(int)ray->x] == '1')
			return (1);
	return (0);
}

void	ft_raycast(t_game *game, double angle)
{
	t_vect	v1;
	t_vect	v2;
	double	temp;
	int		obstacle1;
	int		obstacle2;
	double vreangle = angle;

	ft_init_ray_x(&v1, game, angle);
	ft_init_ray_y(&v2, game, angle);
	obstacle1 = 0;
	obstacle2 = 0;
	angle = ft_init_angle(angle);
	temp = 0;
	while (1)
	{
		if (!obstacle1)
		{
			v1.x += ((0.01 + v1.delta) * v1.x_sign);
			temp = v1.delta / cos(angle);
			v1.y += (v1.y_sign * (temp * sin(angle)));
			v1.lenght += temp;
			v1.delta = 1;
			obstacle1 = ft_intersection(game, &v1);
		}
		else if (!obstacle2)
		{
			v2.y += ((0.01 + v2.delta) * v2.y_sign);
			temp = v2.delta / sin(angle);
			v2.x += (v2.x_sign * (temp * cos(angle)));
			v2.lenght += temp;
			v2.delta = 1;
			obstacle2 = ft_intersection(game, &v2);
		}
		if (obstacle1 && obstacle2)
			break ;
	}
	if (v1.lenght < v2.lenght)
		temp = v1.lenght;
	else
		temp = v2.lenght;
	double tmp = game->info.orientation;
	game->info.orientation = vreangle;
	ft_draw_line(game, temp);
	game->info.orientation = tmp;
}
