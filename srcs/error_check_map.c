/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:02:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/08 14:41:03 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_player_check(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	game->info.pos_x = 0;
	game->info.pos_y = 0;
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
					if (game->info.map[i][j] == 'N')
						game->info.angle = (3 * M_PI) / 2;
					if (game->info.map[i][j] == 'S')
						game->info.angle = M_PI / 2;
					if (game->info.map[i][j] == 'E')
						game->info.angle = 0;
					if (game->info.map[i][j] == 'W')
						game->info.angle = M_PI;
					game->info.pos_x = j * 24;
					game->info.pos_y = i * 24;
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
	char	**dest;

	i = 0;
	dest = ft_calloc((ft_destlen(src1) + 2), sizeof(char *));
	while (src1[i])
	{
		dest[i] = ft_strdup(src1[i]);
		i++;
	}
	ft_free_split(src1);
	dest[i] = ft_strdup(s2);
	ft_supress_line_break(dest[i]);
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
	game->info.map = ft_calloc(1, sizeof(char *));
	game->info.map = ft_addline(game->info.map, line);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			break ;
		}
		else if (ft_is_charset(line))
		{
			free(line);
			ft_put_error(MSG_9, 2);
		}
		free(line);
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
	ft_player_check(game);
	ft_walls_check(game->info.map);
	return (0);
}
