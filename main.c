/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaven <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:03:10 by abenaven          #+#    #+#             */
/*   Updated: 2024/10/21 21:27:23 by abenaven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int	fd;
	char	s[20];

	fd = open("Hello.txt", O_RDONLY);
	read(fd, s, 5);
	printf("%d",fd);
	printf("%s", s);

}
