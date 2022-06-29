/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:40:28 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/29 11:01:06 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_set_output(char *line)
{
	int	out;

	out = -1;
	if (!strncmp(line, "NO", 2))
		out = 0;
	else if (!strncmp(line, "SO", 2))
		out = 1;
	else if (!strncmp(line, "WE", 2))
		out = 2;
	else if (!strncmp(line, "EA", 2))
		out = 3;
	else if (!strncmp(line, "F", 1))
		out = 4;
	else if (!strncmp(line, "C", 1))
		out = 5;
	return (out);
}

int	ft_is_texture_flag(char *line, t_texture *texture, t_game *game)
{
	char	*temp;
	int		i;
	int		out;

	i = 0;
	while (line[i] == ' ')
		i++;
	line = &line[i];
	out = ft_set_output(line);
	if (out < 0)
		return (1);
	else if (out < 4)
	{
		temp = ft_strndup(&line[5], 20);
		if (open(temp, O_RDONLY) < 0)
			return (the_luther(1, temp));
		else
			texture->path[out] = ft_strndup(&line[3], 22);
		return (the_luther(0, temp));
	}
	ft_store_texture(line, i, out, game);
	return (0);
}

void	ft_textures_check(char *argv, t_game *game)
{
	int		i;
	char	*line;

	i = 0;
	game->fd = open(argv, O_RDONLY);
	line = get_next_line(game->fd);
	game->texture.path = ft_gc_calloc(7, sizeof(char *));
	while (line && i < 6)
	{
		if (ft_strlen(line) > 1)
		{
			if (!ft_is_texture_flag(line, &game->texture, game))
				i++;
			else
				ft_put_error(MSG_7, 2, game);
		}
		ft_gc_free(line);
		line = get_next_line(game->fd);
	}
	if (line)
		ft_gc_free(line);
}
