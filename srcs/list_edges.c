/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:28:53 by jdescler          #+#    #+#             */
/*   Updated: 2020/01/06 17:30:02 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				check_existing_edges(t_edges *head, char *from, char *to)
{
	t_edges *current;

	current = head;
	while (current != NULL)
	{
		if (ft_strcmp(current->from, from) == 0
				&& ft_strcmp(current->to, to) == 0)
		{
			return (-1);
		}
		if (ft_strcmp(current->from, to) == 0
				&& ft_strcmp(current->to, from) == 0)
		{
			return (-1);
		}
		current = current->next;
	}
	return (1);
}

int				check_edges_name(t_vertices *head, char *from, char *to)
{
	t_vertices	*current;
	int			ret;

	ret = 0;
	current = head;
	while (current != NULL)
	{
		if (ft_strcmp(current->name, from) == 0
				|| ft_strcmp(current->name, to) == 0)
		{
			ret++;
		}
		current = current->next;
	}
	if (ret == 2)
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

t_edges			*new_edge(char const *from, char const *to)
{
	t_edges *list;

	if (!(list = (t_edges*)malloc(sizeof(t_edges))))
		return (NULL);
	if (!(from))
		list->from = NULL;
	else
	{
		if (!(list->from = ft_strdup(from)))
			return (NULL);
	}
	if (!(to))
		list->to = NULL;
	else
	{
		if (!(list->to = ft_strdup(to)))
			return (NULL);
	}
	list->next = NULL;
	return (list);
}

int				add_edge(t_edges **head, char *from, char *to)
{
	t_edges *new;

	if (!(new = new_edge(from, to)))
		return (-1);
	new->next = *head;
	*head = new;
	return (1);
}
