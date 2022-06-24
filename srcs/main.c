/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:07:45 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/24 14:35:29 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_clean_exit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->fd)
		close(game->fd);
	ft_gc_destroy();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = ft_errors_check(argc, argv);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, 16 * UNIT, 12 * UNIT, "cub3D");
	ft_init_map(&game);
	ft_display_map(&game);
	mlx_hook(game.mlx_window, 17, 0L, ft_clean_exit, &game);
	mlx_hook(game.mlx_window, 2, 1L << 0, ft_key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}

/*
/------- To do list -------/
- Destroy ptrs in exit
- Add malloc error msg
- Norm
*/
