/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:48:12 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/08 16:46:45 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	the_luther(int i, char *temp)
{
	ft_gc_free(temp);
	return (i);
}

int	ft_process_format_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] != ',' && line[i])
	{
		if (!ft_isdigit(line[i]) || i > 2)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_check_format_color(char *line, t_texture *texture)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	texture->colors = ft_split(line, ',');
	i = ft_process_format_check(line);
	if (line[i + 1])
	{
		line = &line[i + 1];
		j = ft_process_format_check(line);
	}
	if (line[j + 1])
	{
		line = &line[j + 1];
		k = ft_process_format_check(line);
	}
	if (i <= 0 || j <= 0 || k <= 0 || ft_atoi (texture->colors[0]) > 255 || \
	ft_atoi (texture->colors[1]) > 255 || ft_atoi (texture->colors[2]) > 255)
	{
		ft_free_split(texture->colors);
		return (1);
	}
	ft_free_split(texture->colors);
	return (0);
}

void	ft_store_texture(char *line, int i, int out, t_texture *texture)
{
	int		save;
	char	*temp;

	save = i + 2;
	while (line[i] != '\n' && line[i])
		i++;
	temp = ft_strndup(&line[save], (i - save));
	if (ft_check_format_color(temp, texture))
	{
		ft_free_split(texture->path);
		ft_gc_free(temp);
		ft_put_error(MSG_8, 2);
	}
	else
		texture->path[out] = ft_gc_strdup(temp);
	ft_gc_free(temp);
}
