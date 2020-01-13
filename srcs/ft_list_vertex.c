/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_vertex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 01:47:10 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/13 17:13:58 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_list_size(t_vertex *begin_list)
{
	t_vertex	*list;
	int			i;

	i = 0;
	list = begin_list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_vertex		*ft_create_elem(void *name)
{
	t_vertex	*list;

	if (!(list = ft_memalloc(sizeof(t_vertex))))
		return (NULL);
	if (!(list->name = ft_strdup(name)))
		return (NULL);
	return (list);
}

void			ft_list_push_second(t_vertex **begin_list, void *name)
{
	t_vertex	*new;
	t_vertex	*list;

	new = ft_create_elem(name);
	list = (t_vertex *)*begin_list;
	if (!list->next)
		list->next = new;
	else
	{
		new->next = list->next;
		list->next = new;
	}
}

void			ft_list_push_back(t_vertex **begin_list, void *name)
{
	t_vertex	*list;

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

void			ft_list_push_front(t_vertex **begin_list, void *name)
{
	t_vertex	*list;

	if (*begin_list)
	{
		list = ft_create_elem(name);
		list->next = *begin_list;
		*begin_list = list;
	}
	else
		*begin_list = ft_create_elem(name);
}
