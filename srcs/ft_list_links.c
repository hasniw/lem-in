/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:32:46 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/29 19:45:04 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

t_links		*ft_create_elem(void *name)
{
	t_links	*list;

	list = NULL;
	list = malloc(sizeof(t_links));
	if (list)
	{
		if (!(list->name = ft_strdup(name)))
			return (NULL);
		list->next = NULL;
	}
	return (list);
}

void			ft_list_push_back(t_links **begin_list, void *name)
{
	t_links	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(name);
	}
	else
		*begin_list = ft_create_elem(name);
}