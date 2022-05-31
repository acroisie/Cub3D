/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:02:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/31 15:05:20 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_is_charset(char *line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (line[i])
	{
		j = 0;
		k = 0;
		while (CHARSET[j])
		{
			if (line[i] != CHARSET[j])
				k++;
			j++;
		}
		if (k != 7)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_check_map(t_game *game)
{
	char	*line;

	(void)game;
	line = get_next_line(game->fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			line = get_next_line(game->fd);
			free(line);
		}
		else
			break ;
	}
	ft_count_line(game->fd);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		else if (ft_is_charset(line))
			ft_put_error(9);
		line = get_next_line(game->fd);
		free(line);
	}
	while (line)
	{
		if (line[0] == '\n')
		{
			line = get_next_line(game->fd);
			free(line);
		}
		else
			break ;
	}
	if (line)
		ft_put_error(10);
	return (0);
}
