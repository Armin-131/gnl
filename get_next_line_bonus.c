/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:43:07 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/28 18:43:13 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strjoin(char *masterbuf, char *buf)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = malloc((ft_strlen(masterbuf) + ft_strlen(buf) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (masterbuf[i])
	{
		ptr[i] = masterbuf[i];
		i++;
	}
	j = 0;
	while (buf[j])
	{
		ptr[i + j] = buf[j];
		j++;
	}
	ptr[i + j] = '\0';
	ft_freedom((void **)&masterbuf);
	return (ptr);
}

static char	*ft_getnext(char *masterbuf)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (masterbuf && masterbuf[i] != '\0')
	{
		if (masterbuf[i] == '\n')
		{
			i++;
			temp = ft_substr(masterbuf, i, (ft_strlen(masterbuf) - i));
			break ;
		}
		i++;
	}
	ft_freedom((void **)&masterbuf);
	return (temp);
}

static char	*ft_readln(char *masterbuf, int fd)
{
	char	*buf;
	int		bytes_read;

	if (masterbuf == NULL)
		masterbuf = ft_calloc(1, 1);
	while (!ft_strchr(masterbuf, '\n'))
	{
		buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buf)
			return (NULL);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_freedom((void **)&buf));
		else if (bytes_read == 0)
		{
			ft_freedom((void **)&buf);
			return (masterbuf);
		}
		buf[bytes_read] = '\0';
		masterbuf = ft_strjoin(masterbuf, buf);
		ft_freedom((void **)&buf);
	}
	return (masterbuf);
}

static char	*ft_getline(char *masterbuf)
{
	size_t	i;
	char	*line;

	i = 0;
	line = NULL;
	while (masterbuf && masterbuf[i] != '\0')
	{
		if (masterbuf[i] == '\n')
		{
			line = ft_substr(masterbuf, 0, i + 1);
			break ;
		}
		i++;
	}
	if (masterbuf && masterbuf[i] == '\0' && i != 0)
		line = ft_substr(masterbuf, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*masterbuf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	masterbuf[fd] = ft_readln(masterbuf[fd], fd);
	if(!masterbuf)
		return(NULL);
	line = ft_getline(masterbuf[fd]);
	if (!ft_strchr(line, '\n'))
		ft_freedom((void **)&masterbuf);
	masterbuf[fd] = ft_getnext(masterbuf[fd]);
	return (line);
}

int	main(void)
{
	int		fd;
	int		fd1;
	char	*line;

	fd = open("Hello.txt", O_RDONLY);
	fd1 = open("LOL.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("f: %s\n", line);
		ft_freedom((void **)&line);
		line = get_next_line(fd1);
		printf("f1: %s\n", line);
		ft_freedom((void **)&line);
		line = get_next_line(fd);
	}
}
