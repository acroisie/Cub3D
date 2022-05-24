/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:40:28 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/24 13:53:33 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_find_texture(char *line)
{
	if (strncmp(line, "NO", 2))
		return (1);
	else if (strncmp(line, "SO", 2))
		return (1);
	else if (strncmp(line, "WE", 2))
		return (1);
	else if (strncmp(line, "EA", 2))
		return (1);
	return (0);
}

int	ft_textures_check(char *argv, t_game *game)
{
	char	*line;
	int		i;
	int		j;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line || i < 4)
	{
		j = 0;
		if (ft_find_texture(line))
		{
			while (line[j] && (line[j] != '.'))
			{
				j++;
				if (line[j] == '\0')
				{
					close(fd);
					ft_put_error(7);
				}
			}
			if (open(&line[j], O_RDONLY) > 0)
			{
				if (strncmp(line, "NO", 2))
				
				i++;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
