/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:40:28 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/25 13:58:59 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_is_texture_flag(char *line, t_texture *texture)
{
	char	*temp;
	int		i;
	int		out;

	i = 0;
	out = -1;
	while (line[i] == ' ')
		i++;
	if (strncmp(&line[i], "NO", 2))
		out = 0;
	else if (strncmp(&line[i], "SO", 2))
		out = 1;
	else if (strncmp(&line[i], "WE", 2))
		out = 2;
	else if (strncmp(&line[i], "EA", 2))
		out = 3;
	else if (strncmp(&line[i], "F", 1))
		out = 4;
	else if (strncmp(&line[i], "C", 1))
		out = 5;
	if (out < 0)
		return (1);
	else if (out < 4) //Make temp
	{
		if (open(&line[i + 2], O_RDONLY) < 0)
			return (1);
		else
			texture->path[out] = ft_strdup(temp);
		return (0);
	}
	else
	{
		//Cut temp different here
		if (!ft_check_color_format(temp))
			ft_put_error(9);
		else
			texture->path[out] = ft_strdup(temp);
	}
	return (0);
}

void	ft_textures_check(char *argv, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	game->texture.path = ft_calloc(7, sizeof(char *));
	while (line && i < 6)
	{
		if (ft_strlen(line) > 1)
		{
			if (!ft_is_texture_flag(line, &game->texture))
				i++;
			else
			{
				ft_free_split(game->texture.path);
				ft_put_error(7);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (i < 6)
	{
		ft_free_split(game->texture.path);
		ft_put_error(8);
	}
}
