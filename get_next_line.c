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

char	*ft_strjoin(char *masterbuf, char *buf)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!masterbuf)
	{
		masterbuf = ft_calloc(1, 1);
		if (!masterbuf)
			return (NULL);
	}
	ptr = malloc((ft_strlen(masterbuf) + ft_strlen(buf) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	while (masterbuf[++i])
		ptr[i] = masterbuf[i];
	j = -1;
	while (buf[++j])
		ptr[i + j] = buf[j];
	ptr[i + j] = '\0';
	ft_freedom((void **)&masterbuf);
	return (ptr);
}

char	*ft_getnext(char *masterbuf)
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

char	*ft_readln(char *masterbuf, int fd)
{
	char	*buf;
	int		bytes_read;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(masterbuf, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_freedom((void **)&masterbuf);
			return (ft_freedom((void **)&buf));
		}
		buf[bytes_read] = '\0';
		masterbuf = ft_strjoin(masterbuf, buf);
	}
	ft_freedom((void **)&buf);
	return (masterbuf);
}

char	*ft_getline(char *masterbuf)
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
	static char	*masterbuf = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	masterbuf = ft_readln(masterbuf, fd);
	if (!masterbuf)
		return(NULL);
	line = ft_getline(masterbuf);
	if (!ft_strchr(line, '\n'))
		ft_freedom((void **)&masterbuf);		
	masterbuf = ft_getnext(masterbuf);
	return (line);
}

//int	main(void)
//{
//	int		fd;
//	char	*line;

//	fd = open("empty", O_RDONLY);
//	line = get_next_line(fd);
//	while (line)
//	{
//		printf("f: %s\n", line);
//		ft_freedom((void **)&line);
//		line = get_next_line(fd);
//	}

//}
