/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:45:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/01 09:10:58 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_supress_line_break(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

void	ft_check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->info.map[i])
	{
		ft_supress_line_break(game->info.map[i]);
		j = 0;
		while (game->info.map[i][j])
		{
			if (game->info.map[i][j] == '0')
			{
				if (!game->info.map[i][j - 1] \
				|| game->info.map[i][j - 1] == ' ')
					ft_put_error(11);
				if (!game->info.map[i][j + 1] \
				|| game->info.map[i][j + 1] == ' ')
					ft_put_error(11);
				if (!game->info.map[i - 1][j] \
				|| game->info.map[i - 1][j] == ' ')
					ft_put_error(11);
				if (!game->info.map[i + 1][j] \
				|| game->info.map[i + 1][j] == ' ')
					ft_put_error(11);
			}
			j++;
		}
		i++;
	}
}
// void ft_check_walls(t_game *game)
// {
// 	char	**temp;
// 	int		x;
// 	int		y;
// 	int		i;
// 	int		j;

// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	j = 0;
// 	while (game->info.map[i])
// 	{
// 		while (ft_strlen(game->info.map[i]) < ft_strlen(game->info.map[j + 1]))
// 			j++;
// 	}
// 	while (game->info.map[y][x])
// 	{
// 		while(game->info.map[y])
// 		{
// 			temp[y][x] = game->info.map[y][x];
// 			y++;
// 		}
// 		x++;
// 	}
// 	temp = ft_calloc((ft_destlen(game.)), sizeof(char *));

// } 

/******
 * pour tourner la map : remplir less collonnes dans un tableau temp
 * touver la plus grande ligne
******/
