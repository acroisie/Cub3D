/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:40:28 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/30 15:02:20 by lnemor           ###   ########lyon.fr   */
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

int	ft_strl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			return (i + 1);
		i++;
	}
	return (i);
}

int	ft_is_texture_flag(char *line, t_texture *texture, t_game *game)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] == ' ')
		i++;
	line = &line[i];
	if (ft_set_output(line) < 0)
		return (1);
	else if (ft_set_output(line) < 4)
	{
		while (ft_isspace(line[j + 2]))
			j++;
		temp = ft_strndup(&line[j + 2], ft_strl(&line[j + 2]) - 1);
		if (open(temp, O_RDONLY) < 0)
			return (the_luther(1, temp));
		else
			texture->path[ft_set_output(line)] = ft_strndup(&line[j + 2], \
			ft_strl(&line[j + 2]) - 1);
		return (the_luther(0, temp));
	}
	ft_store_texture(line, i, ft_set_output(line), game);
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
