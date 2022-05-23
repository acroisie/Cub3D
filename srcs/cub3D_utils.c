/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:54:51 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/23 13:55:42 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_count_line(char *argv)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(argv, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}
