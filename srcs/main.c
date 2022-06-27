/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:07:45 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/27 17:01:58 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_clean_exit(t_game *game)
{
	if (game->fd)
		close(game->fd);
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->mlx_window)
		mlx_destroy_window(game->mlx, game->mlx_window);
	ft_gc_destroy();
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = ft_errors_check(argc, argv);
	ft_init_color(&game);
	ft_init_texture(&game);
	game.mlx = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx, 16 * UNIT, 9 * UNIT, "cub3D");
	game.img.img_ptr = mlx_new_image(game.mlx, 16 * UNIT, 9 * UNIT);
	game.img.img_addr = mlx_get_data_addr(game.img.img_ptr, \
	&game.img.bits_per_pixel, &game.img.size_line, &game.img.endian);
	ft_raycast_engine(&game);
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
