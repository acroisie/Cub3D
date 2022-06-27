/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/27 13:35:03 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(t_game *game, t_vect *ray)
{
	if (ray->y < 0)
		ray->y = 0;
	//else if (ray->y >)
	//	ray->y = game->info.heigth - 1;
	if (ray->x < 0)
		ray->x = 0;
	//else if (ray->x > game->info.width - 1)
	//	ray->x = game->info.width - 1;
	if (game->info.map[(int)ray->y][(int)ray->x] == '1')
		return (1);
	return (0);
}

void	ft_calcul_v1(double angle, t_vect *v1, double temp)
{
	temp = v1->delta / cos(angle);
	v1->x += ((0.01 + v1->delta) * v1->x_sign);
	v1->y += (v1->y_sign * (temp * sin(angle)));
	v1->lenght += temp;
	v1->delta = 1;
}

void	ft_calcul_v2(double angle, t_vect *v2, double temp)
{
	temp = v2->delta / sin(angle);
	v2->y += ((0.01 + v2->delta) * v2->y_sign);
	v2->x += (v2->x_sign * (temp * cos(angle)));
	v2->lenght += temp;
	v2->delta = 1;
}

double	ft_raycast(t_game *game, double angle)
{
	t_vect	v1;
	t_vect	v2;
	double	temp;

	ft_init_ray_x(&v1, game, angle);
	ft_init_ray_y(&v2, game, angle);
	temp = 0;
	angle = ft_init_angle(angle);
	while (!(ft_intersection(game, &v1) && ft_intersection(game, &v2)))
	{
		if (!ft_intersection(game, &v1))
			ft_calcul_v1(angle, &v1, temp);
		else if (!ft_intersection(game, &v2))
			ft_calcul_v2(angle, &v2, temp);
	}
	if (v1.lenght < v2.lenght)
	{
		game->vector = 'x';
		return (fabs(v1.lenght));
	}
	game->vector = 'y';
	return (fabs(v2.lenght));
}

void	ft_raycast_engine(t_game *game)
{
	double	step;
	int		ray_ind;
	double	angle;

	angle = fmod(game->info.orientation - (FOV / 2), 2 * M_PI);
	ray_ind = 0;
	step = FOV / (UNIT * 16);
	if (angle < 0)
		angle = 2 * M_PI + angle;
	while (ray_ind < (UNIT * 16))
	{
		ft_draw_wall(game, (ft_raycast(game, angle)) * \
			cos(fmod(game->info.orientation - angle, 2 * M_PI)), ray_ind);
		angle += step;
		angle = fmod(angle, 2 * M_PI);
		ray_ind++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, \
	game->img.img_ptr, 0, 0);
}
