/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:32:46 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/01 18:00:27 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_links	*ft_create_elem_link(t_vertex *vertex)
{
	t_links	*list;

	list = NULL;
	if (!(list = malloc(sizeof(t_links))))
		return (NULL);
	if (list)
	{
		printf("Helin vertex : %s\n", vertex->name);
		if (!(list->vertex = vertex))
			return (NULL);
		list->next = NULL;
	}
	return (list);
}

void	ft_list_push_back_link(t_links **begin_list, t_vertex *vertex) // Met un vertex a la fin d'une liste
{
	t_links	*list;

	list = *begin_list;
	printf("adresse de NULL : %p\n", NULL);
	printf("adresse : %p\n", list);
	printf("adresse vertex : %p\n", list->vertex);
	if (list->vertex)
	{
		printf("lololfsdol\n");
		printf("list->nxt : %s\n", (char *)list);
		while (list->next)
			list = list->next;
		printf("PArcours de liste finish\n");
		list->next = ft_create_elem_link(vertex);
	}
	else
		*begin_list = ft_create_elem_link(vertex);
}
