/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:43 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/28 19:02:53 by lnemor           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	ft_init_color(t_game *game)
{
	game->texture.ceiling = ft_my_color(game->texture.path[5]);
	game->texture.floor = ft_my_color(game->texture.path[4]);
}

void	ft_init_texture(t_game *game)
{
	game->texture.no.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"./asset/texture_no.xpm", &game->texture.no.width,
			&game->texture.no.heigth);
	if (!game->texture.no.img_ptr)
		dprintf(2, "retournez un  error de pth");
	game->texture.no.img_addr = mlx_get_data_addr(game->texture.no.img_ptr,
			&game->texture.no.bits_per_pixel,
			&game->texture.no.size_line,
			&game->texture.no.endian);
			
	game->texture.so.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"./asset/texture_so.xpm", &game->texture.so.width,
			&game->texture.so.heigth);
	if (!game->texture.so.img_ptr)
		dprintf(2, "retournez un  error de pth");
	game->texture.so.img_addr = mlx_get_data_addr(game->texture.so.img_ptr,
			&game->texture.so.bits_per_pixel,
			&game->texture.so.size_line,
			&game->texture.so.endian);
			
	game->texture.ea.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"./asset/texture_ea.xpm", &game->texture.ea.width,
			&game->texture.ea.heigth);
	if (!game->texture.ea.img_ptr)
		dprintf(2, "retournez un  error de pth");
	game->texture.ea.img_addr = mlx_get_data_addr(game->texture.ea.img_ptr,
			&game->texture.ea.bits_per_pixel,
			&game->texture.ea.size_line,
			&game->texture.ea.endian);
			
	game->texture.we.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"./asset/texture_we.xpm", &game->texture.we.width,
			&game->texture.we.heigth);
	if (!game->texture.we.img_ptr)
		dprintf(2, "retournez un  error de pth");
	game->texture.we.img_addr = mlx_get_data_addr(game->texture.we.img_ptr,
			&game->texture.we.bits_per_pixel,
			&game->texture.we.size_line,
			&game->texture.we.endian);
}
