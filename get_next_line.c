/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:08:51 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/22 19:47:19 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*getrest(char *masterbuf)
{
	size_t	i;

	i = 0;
	while (masterbuf[i] != '\n' && masterbuf[i] != '\0')
	{
		i++;
		if (masterbuf[i] == '\n')
		{
			i++;
			masterbuf = ft_substr(masterbuf, i, (ft_strlen(masterbuf) - i));
		}
	}
}
char	*ft_readngetln(char *masterbuf, int fd)
{
	char	*buf;
	size_t	bytes_read;
	char	*line;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (0);
	while (!ft_strchr(masterbuf, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
		ft_strjoin(masterbuf, buf);
		free(buf);
	}
	bytes_read = 0;
	while (masterbuf[bytes_read] != '\n')
	{
		bytes_read++;
		if (masterbuf[bytes_read] = '\n')
		{
			line = ft_substr(masterbuf, 0, bytes_read);
			break;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*masterbuf = NULL;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_readngetln(masterbuf, fd);
	masterbuf = ft_getrest(&masterbuf);

}
