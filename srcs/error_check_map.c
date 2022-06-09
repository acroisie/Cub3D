/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:02:20 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/09 11:25:20 by acroisie         ###   ########lyon.fr   */
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
					game->info.pos_x = j * 24;//To delete when 3d is ok
					game->info.pos_y = i * 24;//To delete when 3d is ok
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

char	*pass_empty_line(t_game *game)
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

	game->info.size_h_map = 0;//To delete when 3d is ok
	line = ft_gc_strdup(pass_empty_line(game));
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
		game->info.size_h_map += 24; //To delete when 3d is ok
	}
	line = pass_empty_line(game);
	if (line)
		ft_put_error(MSG_10, 2, game);
	ft_player_check(game);
	ft_walls_check(game->info.map, game);
	return (0);
}
