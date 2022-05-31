/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:45:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/05/31 17:28:50 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
