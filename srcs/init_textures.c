/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:43 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/28 13:59:15 by lnemor           ###   ########lyon.fr   */
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
	game->texture.ea.img_ptr = mlx_xpm_file_to_image(game->mlx,
			"./asset/texture_ea.xpm", &game->texture.ea.width,
			&game->texture.ea.heigth);
	if (!game->texture.ea.img_ptr)
		dprintf(2, "retournez un  error de pth");
	game->texture.ea.img_addr = mlx_get_data_addr(game->texture.ea.img_ptr,
			&game->texture.ea.bits_per_pixel,
			&game->texture.ea.size_line,
			&game->texture.ea.endian);
	dprintf(2, "text\n");
}
