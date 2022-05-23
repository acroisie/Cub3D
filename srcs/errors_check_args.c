/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:21:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/23 15:09:08 by acroisie         ###   ########lyon.fr   */
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

void	ft_put_error(int msg_id)
{
	printf("Error\n");
	if (msg_id == 1)
		printf("Argument missing\n");
	if (msg_id == 2)
		printf("Too many arguments\n");
	if (msg_id == 3)
		printf("Wrong map exstension, you must provide a .cub\n");
	if (msg_id == 4)
		printf("You must provide a file, not a folder\n");
	if (msg_id == 5)
		printf("Cannot open the file\n");
	// if (msg_id == 6)
	// 	printf("Map not rectangular\n");
	// if (msg_id == 7)
	// 	printf("Wrong character used, you must use \"E,C,P,1,0\"\n");
	// if (msg_id == 8)
	// 	printf("Map is not closed\n");
	// if (msg_id == 9)
	// 	printf("Wrong number of items, put 1*P & at least 1*C, 1*E\n");
	// if (msg_id == 10)
	// 	printf("File is empty\n");
	exit (1);
}

t_info	ft_errors_check(int argc, char **argv)
{
	t_info	info;

	info.map = NULL;
	if (argc < 2)
		ft_put_error(1);
	else if (argc > 2)
		ft_put_error(2);
	else if (ft_extension_check(argv[1]))
		ft_put_error(3);
	else if (ft_folder_check(argv[1]))
		ft_put_error(4);
	else if (ft_opening_check(argv[1]))
		ft_put_error(5);
	// else if (!ft_count_line(argv[1]))
	// 	ft_put_error(10);
	// ft_init_map(argv[1], &map);
	// ft_check_map(&map);
	return (info);
}
