/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:40:28 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/01 14:39:04 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_check_format_color(char *line)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (line[i] == ' ')
		i++;
	line = &line[i];
	i = 0;
	while (line[i] != ',' && line[i])
	{
		if (!ft_isdigit(line[i]) || i > 2)
			return (1);
		i++;
	}
	if (line[i + 1])
	{
		line = &line[i + 1];
		while (line[j] != ',' && line[j])
		{
			if (!ft_isdigit(line[j]) || j > 2)
				return (1);
			j++;
		}
	}
	if (line[j + 1])
	{
		line = &line[j + 1];
		while (line[k] != '\n' && line[k])
		{
			if (!ft_isdigit(line[k]) || k > 2)
				return (1);
			k++;
		}
	}
	if (i == 0 || k == 0 || j == 0)
		return (1);
	return (0);
}

int	ft_is_texture_flag(char *line, t_texture *texture)
{
	char	*temp;
	int		i;
	int		save;
	int		out;

	i = 0;
	save = 0;
	out = -1;
	while (line[i] == ' ')
		i++;
	if (!strncmp(&line[i], "NO", 2))
		out = 0;
	else if (!strncmp(&line[i], "SO", 2))
		out = 1;
	else if (!strncmp(&line[i], "WE", 2))
		out = 2;
	else if (!strncmp(&line[i], "EA", 2))
		out = 3;
	else if (!strncmp(&line[i], "F", 1))
		out = 4;
	else if (!strncmp(&line[i], "C", 1))
		out = 5;
	if (out < 0)
		return (1);
	else if (out < 4)
	{
		temp = ft_strndup(&line[i + 5], 20);
		if (open(temp, O_RDONLY) < 0)
		{
			free(temp);
			return (1);
		}
		else
		{
			free(temp);
			texture->path[out] = ft_strdup(temp);
		}
		return (0);
	}
	else
	{
		save = i + 2;
		while (line[i] != '\n' && line[i])
			i++;
		temp = ft_strndup(&line[save], (i - save));
		if (ft_check_format_color(temp))
		{
			ft_free_split(texture->path);
			ft_put_error(MSG_8, 2);
		}
		else
			texture->path[out] = ft_strdup(temp);
		free(temp);
	}
	return (0);
}

void	ft_textures_check(char *argv, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	game->fd = open(argv, O_RDONLY);
	line = get_next_line(game->fd);
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
				ft_put_error(MSG_7, 2);
			}
		}
		free(line);
		line = get_next_line(game->fd);
	}
	free(line);
}
