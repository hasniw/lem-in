/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:32:46 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 17:52:45 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_links	*ft_create_elem_link(t_vertex *vertex)
{
	t_links	*list;

	list = NULL;
	if (!(list = malloc(sizeof(t_links))))
		return (NULL);
	if (list)
	{
		if (!(list->vertex = vertex))
			return (NULL);
		list->next = NULL;
	}
	return (list);
}

void	ft_list_push_back_link(t_links **begin_list, t_vertex *vertex)
{
	t_links	*list;

	list = *begin_list;
	if (list->vertex)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem_link(vertex);
	}
	else
		*begin_list = ft_create_elem_link(vertex);
}
