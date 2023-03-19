/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:29 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/19 12:25:29 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h> 
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
    char *content;
    struct s_list *next;
}              t_list;

char *get_next_line(int fd);
void	read_and_stash(int fd, t_list **stash,int *readed);
t_list *get_last_node(t_list *stash);
int found_newline(t_list *stash);
void add_stash(t_list **stash,char *buf,int readed);
void extract_line(t_list *stash,char **line);
void generate_line(char **line,t_list *stash);
void free_stash(t_list *stash);

#endif

