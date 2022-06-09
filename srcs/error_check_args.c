/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:44:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/09 11:32:49 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_opening_check(char *argv, t_game *game)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_put_error(MSG_5, 2, game);
	}
	close(fd);
}

void	ft_folder_check(char *argv, t_game *game)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		ft_put_error(MSG_4, 2, game);
	}
	close(fd);
}

void	ft_extension_check(char *argv, t_game *game)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.')
			break ;
		i++;
	}
	if (argv[i] == '\0')
		ft_put_error(MSG_3, 2, game);
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".cub", 4))
		ft_put_error(MSG_3, 2, game);
}

int	ft_count_line(char *argv, t_game *game)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(argv, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_gc_free(line);
		line = get_next_line(fd);
		count++;
	}
	ft_gc_free(line);
	close(fd);
	if (!count)
		ft_put_error(MSG_6, 2, game);
	return (count);
}
