/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:25:08 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/19 12:25:08 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;
	int				readed;

	if(fd < 0 || BUFFER_SIZE < 0 || read(fd,&line,0) < 0)
		return (NULL);
	readed = 1;
	line = NULL;
	read_and_stash(fd,&stash,&readed);
	if(stash == NULL)
		return (NULL);
	extract_line(stash,&line);
	clean_stash(&stash);
	if(line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return(line);
}

void	read_and_stash(int fd, t_list **stash,int *readed)
{
	char *buf;

	while (!found_newline(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		*readed = (int)read(fd, buf, BUFFER_SIZE);
		if((*stash == NULL && *readed == 0) || *readed == -1)
		{
			free(buf);
			return ;
		}
		buf[*readed] = '\0';
		add_stash(stash,buf,*readed);
		free(buf);
	}
}

void add_stash(t_list **stash,char *buf,int readed)
{
	int		i;
	t_list	*last;
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if(!newnode)
		return ;
	newnode->next = NULL;
	newnode->content = malloc(sizeof(char) * (readed + 1));
	if(newnode->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < readed)
	{
		newnode->content[i] = buf[i];
		i++;
	}
	newnode->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = newnode;
		return ;
	}
	last = get_last_node(*stash);
	last->next = newnode;
}

void extract_line(t_list *stash,char **line)
{
	int	i;
	int	j;

	if(stash == NULL)
		return ;
	generate_line(line,stash);
	if(*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		while (stash->content[i])
		{
			i = 0;
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;	
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0'; 
}
void clean_stash(t_list **stash)
{
	t_list *last;
	t_list *clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if(stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = get_last_node(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if(last->content && last->content[i] != '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((strlen(last->content) - i) + 1));
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}
