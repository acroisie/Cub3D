/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:07:45 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/08 17:02:49 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_clean_exit(t_game *game)
{
	ft_free_split(game->info.map);
	ft_gc_destroy();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = ft_errors_check(argc, argv);
	(void)game;
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, (600),
			(game.info.size_h_map), "cub3D");
	ft_display_map(&game);
	draw_player(&game);
	mlx_hook(game.mlx_window, 17, 0L, ft_clean_exit, &game);
	mlx_hook(game.mlx_window, 2, 1L << 0, ft_key_hook, &game);
	mlx_loop(game.mlx);
	//ft_free_split(game.info.map);// penser a ft_gc_free map a la fin du prog
	return (0);
}

/*
/------- To do list -------/
- Leaks
- Close fd
- Norm
*/