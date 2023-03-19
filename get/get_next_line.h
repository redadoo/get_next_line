/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <evocatur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 09:43:34 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/02 10:59:54 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h> 
# include <stdlib.h>
# include <string.h>

static int filedes;

char	*get_next_line(int fd);
char	*readline(int fd);
int		linelengh(int fd);



#endif