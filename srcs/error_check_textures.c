/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:40:28 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/28 17:27:50 by acroisie         ###   ########lyon.fr   */
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
	while (line[i] != ',' && line[i])
		i++;
	if (line[i])
		while (line[i + j] != ',' && line[i + j])
			j++;
	if (line[i])
		while (line[i + j + k] != '\n' && line[i + j + k])
			k++;
	if ((i - 1) <= 0 || i > 3)
		return (1);
	if ((j - 1) <= 0 || j > 3)
		return (1);
	if (k == 0 || k > 3)
		return (1);
	return (0);
}

int	ft_is_texture_flag(char *line, t_texture *texture)
{
	char	*temp;
	int		i;
	int		test; //To delete
	int		save;
	int		out;

	temp = NULL;
	i = 0;
	save = 0;
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
	else if (out < 4)
	{
		temp = ft_strndup(&line[i + 5], 20);
		test = open(&line[i + 2], O_RDONLY);
		printf("Debug: temp = %s, test = %d\n", temp, test); // To delete
		if (open(&line[i + 2], O_RDONLY) < 0)
			return (1);
		else
			texture->path[out] = ft_strdup(temp);
		return (0);
	}
	else
	{
		// temp = ft_strndup(&line[i + 3], 14);
		save = i + 1;
		while (line[i] != '\n' || line[i])
			i++;
		temp = ft_strndup(&line[save], (i - save));
		printf("Debug: temp = %s\n", temp); // To delete
		if (ft_check_format_color(temp))
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
				close(fd);
				ft_put_error(7);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (i < 6)
	{
		ft_free_split(game->texture.path);
		ft_put_error(8);
	}
}
