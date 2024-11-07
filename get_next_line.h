/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:57:11 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/21 19:37:25 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_freedom(void **ptr);
char	*get_next_line(int fd);
char	*ft_getline(char *masterbuf);
char	*ft_readln(char *masterbuf, int fd);
char	*ft_getnext(char *masterbuf);
char	*ft_strjoin(char *masterbuf, char *buf);

#endif