/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:21:54 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/09 11:00:36 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_put_error(char *err_msg, int fd, t_game *game)
{
	if (game->fd)
		close(game->fd);
	ft_putendl_fd("Error", fd);
	ft_putendl_fd(err_msg, fd);
	ft_gc_destroy();
	exit (1);
}

t_game	ft_errors_check(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		ft_put_error(MSG_1, 2, &game);
	else if (argc > 2)
		ft_put_error(MSG_2, 2, &game);
	else if (ft_extension_check(argv[1]))
		ft_put_error(MSG_3, 2, &game);
	else if (ft_folder_check(argv[1]))
		ft_put_error(MSG_4, 2, &game);
	else if (ft_opening_check(argv[1]))
		ft_put_error(MSG_5, 2, &game);
	else if (!ft_count_line(argv[1]))
		ft_put_error(MSG_6, 2, &game);
	ft_textures_check(argv[1], &game);
	ft_init_check_map(&game);
	return (game);
}
