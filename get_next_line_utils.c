/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:16:28 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/02 12:53:02 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int linelengh(int fd)
{
	char	m;
	int		j;
	int		size;

	m = 0;
	size = 0;
	j = read(fd,&m,1);
	while ( m != '\n' && j > 0)
	{
		j = read(fd,&m,1);
		size++;
	}
	return (size + 1);
}

char *assig(int fd,char *str,int size)
{
	int i;
	char c;
	while (size)
	{
		i = read(fd,&c,1);
		printf("%i",i);
		size--;
	}
	return (str);
}

char	*readline(int fd)
{
	char	m;
	int		i;
	int		size;
	char	*str;

	size = linelengh(fd);
	str = (char *)malloc(sizeof(char) * size);
	str[5] = '\0';
	str = assig(fd,str,size);
	return (str);
}
