/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:05:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/22 09:46:30 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_intersection(t_game *game, t_vect v1)
{
	dprintf(2, "Debug 2; v1.x = %d, v2.y = %d map = ", (int)v1.x, (int)v1.y);
	dprintf(2, "%c \n ", game->info.map[(int)v1.y][(int)v1.x]);
	if (game->info.map[(int)v1.y][(int)v1.x] == '1')
		return (1);
	return (0);
}

// t_vect	init_angle(double angle)
// {
// 	t_vect	angle_final;
// 	if (angle > M_PI_2 && angle < M_PI)
// 		angle_final.lenght = M_PI - angle;
// 	else if
// 	angle_final.x  = cos(angle_final.lenght);
// 	return angle_final;
// }

void	ft_raycast(t_game *game)
{
	t_vect	v1;
	// t_vect	ray_angle = init angle;
	double	temp;
	double	dx;
	int		obstacle;

	obstacle = 0;
	v1.x = game->info.pos_x;
	v1.y = game->info.pos_y;
	v1.lenght = 0;
	while (!obstacle)
	{
		if (game->info.orientation < M_PI_2 || \
		game->info.orientation > 3 * M_PI_2)
			dx = 1 - fmod(v1.x, 1);
		else
			dx = fmod(v1.x, 1);
		v1.x += dx;
		temp = dx / cos(game->info.orientation);
		v1.lenght += temp;
		v1.y += sin(game->info.orientation) * v1.lenght;
		printf("Debug lenght; %f, %d\n", v1.x, (int)v1.x);
		obstacle = ft_intersection(game, v1);
	}
	ft_draw_line(game, v1.lenght);
}
