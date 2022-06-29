/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:02:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/29 14:19:14 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	init_orientation_player(t_game *game, int i, int j)
{
	if (game->info.map[i][j] == 'N')
		game->info.orientation = 3 * M_PI_2;
	if (game->info.map[i][j] == 'S')
		game->info.orientation = M_PI_2;
	if (game->info.map[i][j] == 'E')
		game->info.orientation = 0;
	if (game->info.map[i][j] == 'W')
		game->info.orientation = M_PI;
	game->info.pos_x = j + 0.5;
	game->info.pos_y = i + 0.5;
	game->info.map[i][j] = '0';
	return (1);
}

void	ft_player_check(t_game *game)
{
	int	i;
	int	j;
	int	k;
	int	player;

	i = -1;
	player = 0;
	game->info.pos_x = 0;
	game->info.pos_y = 0;
	while (game->info.map[++i])
	{
		j = -1;
		while (game->info.map[i][++j])
		{
			k = -1;
			while (CHARSET_2[++k])
				if (CHARSET_2[k] == game->info.map[i][j])
					player += init_orientation_player(game, i, j);
		}
	}
	if (!player)
		ft_put_error(MSG_12, 2, game);
	if (player > 1)
		ft_put_error(MSG_13, 2, game);
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

char	*skip_empty_line(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	while (line)
	{
		if (line[0] == '\n')
		{
			line = get_next_line(game->fd);
			ft_gc_free(line);
		}
		else
			break ;
	}
	return (line);
}

int	ft_init_check_map(t_game *game)
{
	char	*line;

	line = ft_gc_strdup(skip_empty_line(game));
	game->info.map = ft_gc_calloc(1, sizeof(char *));
	game->info.map = ft_addline(game->info.map, line);
	while (line)
	{
		if (line[0] == '\n')
		{
			ft_gc_free(line);
			break ;
		}
		else if (ft_is_charset(line))
			ft_put_error(MSG_9, 2, game);
		ft_gc_free(line);
		line = get_next_line(game->fd);
		if (line && line[0] != '\n')
			game->info.map = ft_addline(game->info.map, line);
	}
	line = skip_empty_line(game);
	if (line)
		ft_put_error(MSG_10, 2, game);
	ft_player_check(game);
	ft_walls_check(game->info.map, game);
	return (0);
}
