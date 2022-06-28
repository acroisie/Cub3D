/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnemor <lnemor@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:43 by lnemor            #+#    #+#             */
/*   Updated: 2022/06/28 12:36:38 by lnemor           ###   ########lyon.fr   */
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
	game->texture.ea = mlx_xpm_file_to_image(game->mlx,
			"./asset/texture_ea.xpm", &game->texture.size_x,
			&game->texture.size_y);
	if (!game->texture.ea)
		dprintf(2, "retournez un  error de pth");
	game->texture.ea = mlx_get_data_addr(game->texture.ea,
			&game->img.bits_per_pixel, &game->img.size_line, &game->img.endian);
	dprintf(2, "text\n");
}
