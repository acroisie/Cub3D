/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:21:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/23 10:53:51 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

t_map	ft_errors_check(int argc, char **argv)
{
	t_map map;

	
}

void	ft_puterror(int msg_id)
{
	printf("Error\n");
	if (msg_id == 1)
		printf("Too few arguments\n");
	if (msg_id == 2)
		printf("Too many arguments\n");
	if (msg_id == 3)
		printf("Wrong map exstension, you must provide a .ber\n");
	if (msg_id == 4)
		printf("You must provide a file, not a folder\n");
	if (msg_id == 5)
		printf("Cannot open the file\n");
	if (msg_id == 6)
		printf("Map not rectangular\n");
	if (msg_id == 7)
		printf("Wrong character used, you must use \"E,C,P,1,0\"\n");
	if (msg_id == 8)
		printf("Map is not closed\n");
	if (msg_id == 9)
		printf("Wrong number of items, put 1*P & at least 1*C, 1*E\n");
	if (msg_id == 10)
		printf("File is empty\n");
	exit (1);
}
