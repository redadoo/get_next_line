/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:17:29 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/02 12:44:41 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *get_next_line(int fd)
{
	if (!filedes && fd)
	{
		filedes = fd;
		return(readline(fd));
	}
	else if (fd)
	{
		return(readline(filedes));
	}
	return(NULL);
}

