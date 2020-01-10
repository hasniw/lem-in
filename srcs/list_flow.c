/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_flow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:28:43 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/10 18:09:52 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_flow		*new_flow(t_path *head, int size)
{
	t_flow	*all_paths;

	if (!(all_paths = malloc(sizeof(t_flow))))
		return (NULL);
	all_paths->path = head;
	all_paths->size = size;
	all_paths->next = NULL;
	return (all_paths);
}

int			add_flow(t_flow **head, t_flow *new)
{
	t_flow	*current;

	if (*head == NULL || (*head)->size >= new->size)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		current = *head;
		while (current->next &&
				current->next->size < new->size)
		{
			current = current->next;
		}
		new->next = current->next;
		current->next = new;
	}
	return (1);
}
