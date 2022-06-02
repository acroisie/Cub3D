/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:45:34 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/02 11:52:21 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_map_y_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

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

void	ft_walls_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (i == 0 || j == 0 || i == (ft_map_y_size(map) - 1) \
				|| !map[i][j - 1] || map[i][j - 1] == ' ' \
				|| !map[i][j + 1] || map[i][j + 1] == ' ' \
				|| !map[i - 1][j] || map[i - 1][j] == ' ' \
				|| !map[i + 1][j] || map[i + 1][j] == ' ' )
					ft_put_error(MSG_11, 2);
			}
			j++;
		}
		i++;
	}
}
