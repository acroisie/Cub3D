/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:08:32 by acroisie          #+#    #+#             */
/*   Updated: 2022/05/23 10:46:50 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdio.h>

typedef struct s_map
{
	char	**map;
}t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_window;
	t_map	map;
}t_game;

t_map	ft_errors_check(int argc, char **argv);
void	ft_puterror(int msg_id);

#endif
