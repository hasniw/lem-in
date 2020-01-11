/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 01:25:45 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	free_all_wthout_matrix(t_var *var, int i)
{
	t_vertex	*current;
	t_vertex	*next;
	t_links		*current_links;
	t_links		*current_links_next;

	current = var->vertex;
	while (current)
	{
	    next = current->next;
		current_links = current->links;
		while (current_links)
		{
			current_links_next = current_links->next;
			free(current_links);
			current_links = current_links_next;
		}
		free(current->name);
		free(current);
	    current = next;
	}
	var->vertex = (t_vertex *)0;
	free(var->room_end);
	free(var->room_start);
	free(var);
	var = (t_var *)0;
	return (i);
}

int			ft_parsing(t_var *var)
{
	char	*line;

	if (ft_ants(var))
		return (free_var(var, 1));
	if (ft_room(var))
		return (free_room(var, 1));
	if (var->line)
		if (ft_edge(var, var->line))
			return (free_all_wthout_matrix(var, 1));
	while (get_next_line(var->fd, &line) > 0)
	{
		ft_putendl(line);
		if (ft_edge(var, line))
			return (free_all_wthout_matrix(var, 1));
	}
	if (var->linked_start == false || var->linked_end == false)
		return (free_all_wthout_matrix(var, 1));
	return (0);
}
