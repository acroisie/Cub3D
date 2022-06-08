/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:20:02 by acroisie          #+#    #+#             */
/*   Updated: 2022/06/08 17:01:49 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	ft_find_end_of_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_fill_buffer(int fd, char *buffer)
{
	char		*temp;
	ssize_t		ret;

	if (buffer == NULL)
		temp = ft_strndup("", 1);
	else
		temp = ft_strndup(buffer, BUFFER_SIZE);
	while (!ft_find_end_of_line(temp))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret <= 0 || temp == 0)
		{
			buffer[ret] = '\0';
			break ;
		}
		buffer[ret] = '\0';
		temp = ft_strjoin_free_s1(temp, buffer);
	}
	return (temp);
}

char	*ft_line_split(char *brut_line, char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (brut_line[i] && (brut_line[i] != '\n'))
		i++;
	if (brut_line[i] == '\0')
		return (line = ft_strndup(brut_line, i));
	i++;
	line = ft_strndup(brut_line, i);
	while (brut_line[i])
	{
		buffer[j] = brut_line[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*brut_line;
	char			*line;

	brut_line = ft_fill_buffer(fd, buffer);
	line = ft_line_split(brut_line, buffer);
	ft_gc_free(brut_line);
	if (line[0] == '\0')
	{
		ft_gc_free(line);
		return (NULL);
	}
	return (line);
}
