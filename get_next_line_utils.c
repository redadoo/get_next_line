/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:16:28 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/02 13:10:08 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *assig(int fd,char *str,int size)
{
	int i;
	char c;
	int j;

	j = 0;
	while (j != size)
	{
		i = read(fd,&c,1);
		str[j] = c;
		j++;
	}
	return (str);
}

char	*readline(int fd)
{
	char	m;
	int		i;
	int		size;
	char	*str;

	i = 0;
	m = 0;
	size = 9;
	str = (char *)malloc(sizeof(char) * size);
	str[5] = '\0';
	str = assig(fd,str,size);
	return (str);
}
