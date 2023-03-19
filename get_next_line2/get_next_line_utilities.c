/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilities.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evocatur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:46:30 by evocatur          #+#    #+#             */
/*   Updated: 2023/03/19 12:46:30 by evocatur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int found_newline(t_list *stash)
{
	int	i;
	t_list *current;
	
	if(stash == NULL)
		return (0);
	current = get_last_node(stash);
	i = 0;
	while (current->content[i])
	{
		if(current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list *get_last_node(t_list *stash)
{
	t_list *current;

	current = stash;

	while (current && current->next)
		current = current->next
	return (current);
}

void generate_line(char **line,t_list *stash)
{
	int i;
	int len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if(stash->content[i])
			{
				len++;
				break;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1))
	if(*line == NULL)
		return ;
}

void free_stash(t_list *stash)
{
	t_list *current;
	t_list *next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}