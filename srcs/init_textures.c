/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:43 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/30 16:02:30 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_color(t_game *game)
{
	game->texture.ceiling = ft_my_color(game->texture.path[5]);
	game->texture.floor = ft_my_color(game->texture.path[4]);
}

void	ft_init_texture_part_2(t_game *game)
{
	game->texture.we.img_ptr = mlx_xpm_file_to_image(game->mlx, \
			game->texture.path[3], &game->texture.we.width, \
			&game->texture.we.heigth);
	if (!game->texture.we.img_ptr \
	|| !(game->texture.we.width == game->texture.we.heigth))
		ft_put_error(MSG_14, 2, game);
	game->texture.we.img_addr = mlx_get_data_addr(game->texture.we.img_ptr, \
			&game->texture.we.bpp, &game->texture.we.size_line, \
			&game->texture.we.endian);
	game->texture.ea.img_ptr = mlx_xpm_file_to_image(game->mlx, \
			game->texture.path[2], &game->texture.ea.width, \
			&game->texture.ea.heigth);
	if (!game->texture.ea.img_ptr \
	|| !(game->texture.ea.width == game->texture.ea.heigth))
		ft_put_error(MSG_14, 2, game);
	game->texture.ea.img_addr = mlx_get_data_addr(game->texture.ea.img_ptr, \
			&game->texture.ea.bpp, &game->texture.ea.size_line, \
			&game->texture.ea.endian);
}

void	ft_init_texture(t_game *game)
{
	game->texture.no.img_ptr = mlx_xpm_file_to_image(game->mlx, \
			game->texture.path[1], &game->texture.no.width, \
			&game->texture.no.heigth);
	if (!game->texture.no.img_ptr \
	|| !(game->texture.no.width == game->texture.no.heigth))
		ft_put_error(MSG_14, 2, game);
	game->texture.no.img_addr = mlx_get_data_addr(game->texture.no.img_ptr, \
			&game->texture.no.bpp, &game->texture.no.size_line, \
			&game->texture.no.endian);
	game->texture.so.img_ptr = mlx_xpm_file_to_image(game->mlx,
			game->texture.path[0], &game->texture.so.width,
			&game->texture.so.heigth);
	if (!game->texture.so.img_ptr \
	|| !(game->texture.so.width == game->texture.so.heigth))
		ft_put_error(MSG_14, 2, game);
	game->texture.so.img_addr = mlx_get_data_addr(game->texture.so.img_ptr, \
			&game->texture.so.bpp, &game->texture.so.size_line, \
			&game->texture.so.endian);
	ft_init_texture_part_2(game);
}
