/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 19:11:38 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/27 19:12:10 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_freedom(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*temp;

	ptr = malloc(nmemb * size);
	if (!ptr)
		ft_freedom((void**)ptr);
	temp = (char *)ptr;
	while (size--)
		*temp++ = '\0';
	return (ptr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	ls;
	size_t	i;
	char	*psub;

	ls = ft_strlen(s);
	i = 0;
	if (start >= ls)
		return (ft_calloc(1, 1));
	if (len + start > ls)
		len = ls - start;
	psub = malloc((len + 1) * sizeof(char));
	if (!psub)
		return (NULL);
	while (i < len && s[i])
	{
		psub[i] = s[start];
		i++;
		start++;
	}
	psub[i] = '\0';
	return (psub);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (0);
}
