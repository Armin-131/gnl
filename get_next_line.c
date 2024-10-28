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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	ptr = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	while (s1[++i])
		ptr[i] = s1[i];
	j = -1;
	while (s2[++j])
		ptr[i + j] = s2[j];
	ptr[i + j] = '\0';
	ft_freedom((void **)&s1);
	return (ptr);
}

char	*ft_getrest(char *masterbuf)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (masterbuf && masterbuf[i] != '\n' && masterbuf[i] != '\0')
	{
		i++;
		if (masterbuf[i] == '\n')
		{
			i++;
			temp = ft_substr(masterbuf, i, (ft_strlen(masterbuf) - i));
			break ;
		}
	}
	ft_freedom((void **)&masterbuf);
	return (temp);
}

char	*ft_getln(char *masterbuf)
{
	size_t	i;
	char	*line;

	i = 0;
	line = NULL;
	while (masterbuf && masterbuf[i] != '\n' && masterbuf[i] != '\0')
	{
		i++;
		if (masterbuf[i] == '\n' || masterbuf[i] == '\0')
		{
			i++;
			line = ft_substr(masterbuf, 0, i);
			//printf("linesss: [%s]\n", line);
			break ;
		}
	}
	return (line);
}

char	*ft_readln(char *masterbuf, int fd)
{
	char	*buf;
	int		bytes_read;

	buf = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	if (masterbuf == NULL)
		masterbuf = ft_calloc(1, 1);
	while (!ft_strchr(masterbuf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_freedom((void **)&buf), NULL);
		buf[bytes_read] = '\0';
		if (bytes_read == 0)
		{
			ft_freedom((void **)&buf);
			return (masterbuf);
		}
		masterbuf = ft_strjoin(masterbuf, buf);
	}
	ft_freedom((void **)&buf);
	return (masterbuf);
}

char	*get_next_line(int fd)
{
	static char	*masterbuf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	masterbuf = ft_readln(masterbuf, fd);
	line = ft_getln(masterbuf);
	masterbuf = ft_getrest(masterbuf);
	return (line);
}
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("quijott.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		ft_freedom((void **)&line);
		line = get_next_line(fd);
	}
}
