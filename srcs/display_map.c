/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 10:21:02 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/01 12:57:29 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//char	*ft_add_char(char *s1, char c)
//{
//	int		i;
//	char	*str;
//
//	i = 0;
//	if (!s1)
//		return (ft_strdup(&c));
//	if (!c)
//		return (s1);
//	str = ft_calloc((ft_strlen(s1) + 2), sizeof(char));
//	while (s1[i])
//	{
//		str[i] = s1[i];
//		i++;
//	}
//	str[i] = c;
//	i++;
//	str[i] = '\0';
//	ft_free(s1);
//	return (str);
//}
//
//char	*ft_convert_base(unsigned long int n, char *base)
//{
//	unsigned long int	size;
//	unsigned long int	num;
//	char				*dest;
//
//	size = 0;
//	if (!dest)
//		dest = ft_strdup("");
//	while (base[size])
//		size++;
//	num = 0;
//	if (n < 0)
//	{
//		dest = ft_add_char(dest, '-');
//		num = -n;
//	}
//	else
//		num = n;
//	if (num >= size)
//	{
//		ft_convert_base(num / size, base);
//		dest = ft_add_char(dest, *((num % size) + base));
//	}
//	if (num < size)
//		dest = ft_add_char(dest, *((num % size) + base));
//	return (dest);
//}
//
//void	my_color(t_game *game)
//{
//	int		r;
//	int		g;
//	int		b;
//	char	**colors;
//	char	*hexa;
//
//	colors = ft_split(game->texture->path[4]);
//	r = atoi(colors[0]);
//	g = atoi(colors[1]);
//	b = atoi(colors[2]);
//	hexa = ft_strjoin("0x", ft_convert_base(r));
//}
//

void	ft_display_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	x = 0;
	i = 0;
	j = 0;
	while (game->info.map[i])
	{
		x = 0;
		j = 0;
		while (game->info.map[i][j])
		{
			if (game->info.map[i][j] == '1')
				my_put_pixel(game, x, y, atoi(game->texture.path[4]));
			if (game->info.map[i][j] == '0')
				my_put_pixel(game, x, y, atoi(game->texture.path[5]));
			x += 24;
			j++;
		}
		y += 24;
		i++;
	}
}

void	my_put_pixel(t_game *game, int map_x, int map_y, int color)
{
	int	x;
	int	y;

	x = 0;
	(void)color;
	while (x < 24)
	{
		y = 0;
		while (y < 24)
		{
			mlx_pixel_put(game->mlx, game->mlx_window,
				x + map_x, y + map_y, 0x5ACEB4);
			y++;
		}
		x++;
	}
}
