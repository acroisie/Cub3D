/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:02:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/30 16:13:59 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

//int	is_charset(char *line)
//{
//	int	i;
//
//	i = 0;
//	while (line[i])
//	{
//		if (line[i] != '1' || line[i] != '0' || line[i] != 'N'
//			|| line[i] != 'S' || line[i] != 'E' || line[i] != 'O'
//			|| line[i] != ' ' || line[i] != '\n')
//			return (0);
//		i++;
//	}
//	return (1);
//}
//
//int	ft_init_check_map(t_game *game)
//{
//	char	*line;
//	int		i;
//	int		j;
//
//	(void)game;
//	i = 0;
//	j = 0;
//	line = get_next_line(game->fd);
//	while (line[i] == '\n' && ft_strlen(line) == 1 && line)
//	{
//		line = get_next_line(game->fd);
//		free(line);
//	}
//	while (line)
//	{
//		if (is_charset(line) == 0)
//			return (-1);
//		else
//			line = get_next_line(game->fd);
//	}
//	return (0);
//}
