/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/16 21:06:58 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	my_color(char *rgb)
{
	char	**colors;
	int		i;
	int		color;
	int		color_tab[3];

	i = 0;
	color = 0;
	colors = ft_split(rgb, ',');
	if (!colors)// retour d'erreur
		return (0);// retour d'erreur
	color_tab[0] = atoi(colors[0]);
	color_tab[1] = atoi(colors[1]);
	color_tab[2] = atoi(colors[2]);
	i = 0;
	while (i < 3)
	{
		color_tab[i] = color | (color_tab[i] << (16 - (i * 8)));
		color += color_tab[i];
		i++;
	}
	ft_free_split(colors);
	return (color);
}

void	ft_display_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	game->img.img_ptr = mlx_new_image(game->mlx, 1024, game->info.size_h_map);
	game->img.img_addr = mlx_get_data_addr(game->img.img_ptr,
			&game->img.bits_per_pixel, &game->img.size_line,
			&game->img.endian);
	while (game->info.map[i])
	{
		x = 0;
		j = 0;
		while (game->info.map[i][j])
		{
			if (game->info.map[i][j] == '1')
				my_put_pixel(game, x, y, my_color(game->texture.path[4]));
			if (game->info.map[i][j] == '0' || game->info.map[i][j] == 'N'
				|| game->info.map[i][j] == 'S' || game->info.map[i][j] == 'E'
				|| game->info.map[i][j] == 'W')
				my_put_pixel(game, x, y, my_color(game->texture.path[5]));
			x += UNIT;
			j++;
		}
		y += UNIT;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img_ptr);
}

void	my_put_pixel(t_game *game, int map_x, int map_y, int color)
{
	int		x;
	int		y;
	char	*dst;

	x = 0;
	(void)color;
	while (x < UNIT)
	{
		y = 0;
		while (y < UNIT)
		{
			if (y == 0 || y == UNIT)
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line
						+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = 68248;
			}
			else
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line
						+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = color;
			}
			if (x == 0 || x == UNIT)
			{
				dst = game->img.img_addr + ((y + map_y) * game->img.size_line
						+ (x + map_x) * (game->img.bits_per_pixel / 8));
				*(unsigned int *)dst = 68248;
			}
			y++;
		}
		x++;
	}
}

int	ft_intersection(t_game *game, int pos_x, int pos_y)
{
	dprintf(2, "intercept y:%d\n",(int)pos_y);
	dprintf(2, "intercept x:%d\n",(int)pos_x);
	if (game->info.map[(int)pos_y][(int)pos_x] == '1')
		return (1);
	return (0);
}

void	draw_player(t_game *game)
{
	double	x;
	double	y;
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	double	tile_step_x;
	double	tile_step_y;
	int		i;
	double 	dx;
	double 	dy;

	x = 0;
	while (x < 5)
	{
		y = 0;
		while (y < 5)
		{
			mlx_pixel_put(game->mlx, game->mlx_window, x + game->info.pos_x,
				y + game->info.pos_y, 5454548);
			y++;
		}
		x++;
	}
	game->info.fov = M_PI / 3;
	game->info.r_step = 0;
	i = 0;
	tile_step_x = UNIT;
	tile_step_y = UNIT;
	dx = (UNIT - fmod(game->info.pos_x, UNIT));
	dy = (UNIT - fmod(game->info.pos_y, UNIT));
	x_step = UNIT - fmod(game->info.pos_x, UNIT) * tan(game->info.r_angle);
	y_step = UNIT - fmod(game->info.pos_y, UNIT) / tan(game->info.r_angle);
	x_intercept = game->info.pos_x + dx + (-dy
		/ tan(game->info.r_angle));
	y_intercept = game->info.pos_y + dy + dy
		/ tan(game->info.r_angle);
	dprintf(2, "angle: %f\n", game->info.r_angle);
	dprintf(2, "pos_x: %d\n", (int)game->info.pos_x);
	dprintf(2, "pos_y: %d\n", (int) game->info.pos_y);
	dprintf(2, "dx: %f\n", dx);
	dprintf(2, "dy: %f\n", dy);
	dprintf(2, "xstep: %f\n", x_step);
	dprintf(2, "ystep: %f\n", y_step);
	dprintf(2, "x_intercept: %f\n", x_intercept);
	dprintf(2, "y_intercept: %f\n", y_intercept);
	while (i < 3)
	{	
		
		//while (y_intercept < y)
		//{
		//	if (game->info.map[(int)x/UNIT][(int)y_intercept/UNIT] == '1')
		//		dprintf(2, "hitVertical\n");
		//	x += tile_step_x;
		//	y_intercept += y_step;
		//}
		//while (x_intercept < x)
		//{
		//	if (game->info.map[(int)x_intercept/UNIT][(int)y/UNIT] == '1')
		//		dprintf(2, "hitHorizontal\n");
		//	x += tile_step_x;
		//	y_intercept += y_step;
		//}
		game->info.r_step += game->info.fov / 3;
		//dprintf(2, " r_step %f\n", game->info.r_step);
		i++;
	}
}
