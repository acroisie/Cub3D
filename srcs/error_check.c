/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:21:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/30 10:12:37 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

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
	if (msg_id == 6)
		printf("File is empty\n");
	if (msg_id == 7)
		printf("Wrong texture path\n");
	if (msg_id == 8)
		printf("Missing texture\n");
	if (msg_id == 9)
		printf("Wrong color format\n");
	// if (msg_id == 7)
	// 	printf("Wrong character used, you must use \"E,C,P,1,0\"\n");
	// if (msg_id == 8)
	// 	printf("Map is not closed\n");
	// if (msg_id == 9)
	// 	printf("Wrong number of items, put 1*P & at least 1*C, 1*E\n");
	exit (1);
}

t_game	ft_errors_check(int argc, char **argv)
{
	t_game	game;

	// game.info.map = NULL; //To delete
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
	else if (!ft_count_line(argv[1]))
		ft_put_error(6);
	ft_textures_check(argv[1], &game);
	// ft_init_map(argv[1], &map);
	// ft_check_map(&map);
	return (game);
}
