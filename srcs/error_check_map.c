/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:02:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/02 14:15:20 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_player_check(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (game->info.map[i])
	{
		j = 0;
		while (game->info.map[i][j])
		{
			k = 0;
			while (CHARSET_2[k])
			{
				if (CHARSET_2[k] == game->info.map[i][j])
				{
					game->info.pos_x = j;
					game->info.pos_y = i;
					game->info.pov = game->info.map[i][j];
					game->info.map[i][j] = '0';
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

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

int	ft_destlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_addline(char **src1, char *s2)
{
	int		i;
	int		j;
	char	**dest;

	i = 0;
	j = 0;
	dest = ft_calloc((ft_destlen(src1) + 2), sizeof(char *));
	if (dest == NULL)
		return (NULL);
	while (src1[j])
		dest[i++] = ft_strdup(src1[j++]);
	j = 0;
	dest[i] = ft_strdup(s2);
	ft_supress_line_break(dest[i]);
	dest[i + 1] = NULL;
	dest[ft_destlen(dest)] = NULL;
	ft_free_split(src1);
	free(s2);
	return (dest);
}

char	*pass_empty_line(t_game *game)
{
	char	*line;

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
	return (line);
}

int	ft_init_check_map(t_game *game)
{
	char	*line;

	game->info.size_h_map = 0;
	line = ft_strdup(pass_empty_line(game));
	game->info.map = ft_calloc((1), sizeof(char *));
	game->info.map = ft_addline(game->info.map, line);
	while (line)
	{
		if (line[0] == '\n')
			break ;
		else if (ft_is_charset(line))
			ft_put_error(MSG_9, 2);
		line = get_next_line(game->fd);
		if (line && line[0] != '\n')
			game->info.map = ft_addline(game->info.map, line);
		game->info.size_h_map += 24;
	}
	line = pass_empty_line(game);
	if (line)
	{
		ft_free_split(game->info.map);
		ft_put_error(MSG_10, 2);
	}
	ft_walls_check(game->info.map);
	return (0);
}
