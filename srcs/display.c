/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/27 13:17:15 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_my_color(char *rgb)
{
	char	**colors;
	int		i;
	int		color;
	int		color_tab[3];

	i = 0;
	color = 0;
	colors = ft_split(rgb, ',');
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

void	my_put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.img_addr + y * game->img.size_line \
	+ x * (game->img.bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void	ft_draw_wall(t_game *game, double lenght, int x)
{
	double	h;
	int		i;
	int		y;
	double	heigth;

	y = 0;
	heigth = UNIT * 9;
	h = heigth / lenght;
	i = 0;
	while (i < heigth)
	{
		if (i > 9 * UNIT)
			break ;
		if (i >= 0 && i <= (heigth / 2) - h / 2)
			my_put_pixel(game, x, y, 0xabdbe3);
		else if (i > (heigth / 2 - h / 2) && i < (heigth / 2) + h / 2)
			my_put_pixel(game, x, y, 0x21130d);
		else if (i < heigth)
			my_put_pixel(game, x, y, 0xE28743);
		i++;
		y++;
	}
}
