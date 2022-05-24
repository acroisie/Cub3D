/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:44:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/24 09:48:07 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_opening_check(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_folder_check(char *argv)
{
	int	fd;

	fd = open(argv, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_extension_check(char *argv)
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
		return (1);
	if (ft_strncmp(&argv[ft_strlen(argv) - 4], ".cub", 4))
		return (1);
	return (0);
}



int	ft_count_line(char *argv)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(argv, O_RDONLY);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	close(fd);
	return (count);
}