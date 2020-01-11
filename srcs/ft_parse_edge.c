/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 17:36:23 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		add_one_start(t_var *var)
{
	var->linked_start = true;
	var->i_start += 1;
}

static void		add_one_end(t_var *var)
{
	var->linked_end = true;
	var->i_end += 1;
}

static t_vertex	*ft_room_exist(t_var *var, char *str)
{
	t_vertex	*room;

	room = (t_vertex *)var->vertex;
	while (room)
	{
		if (ft_strequ(room->name, str))
			return (room);
		room = room->next;
	}
	return ((void *)0);
}

static int		ft_check_edges(t_var *var, char *line)
{
	char		**tab;
	t_vertex	*room1;
	t_vertex	*room2;

	if (ft_count_word(line, '-') != 1)
		return (1);
	tab = ft_strsplit(line, '-');
	if (!tab[0] || !tab[1])
		return (free_tab(tab, 1));
	if (!(room1 = ft_room_exist(var, tab[0])))
		return (free_tab(tab, 1));
	if (!(room2 = ft_room_exist(var, tab[1])))
		return (free_tab(tab, 1));
	free_tab(tab, 0);
	ft_list_push_back_link(&room2->links, room1);
	ft_list_push_back_link(&room1->links, room2);
	if (!ft_strcmp(room1->name, var->room_start)
		|| !ft_strcmp(room2->name, var->room_start))
		add_one_start(var);
	if (!ft_strcmp(room1->name, var->room_end)
		|| !ft_strcmp(room2->name, var->room_end))
		add_one_end(var);
	return (0);
}

int				ft_edge(t_var *var, char *line)
{
	if (is_comment(line, var) != 1)
	{
		if (is_comment(line, var) == 0)
			return (free_line(&line, 0));
		return (free_line(&line, 1));
	}
	else if (ft_count_word(line, '-') > 0)
	{
		if (ft_check_edges(var, line))
			return (free_line(&line, 1));
		free_line(&line, 0);
	}
	else
		return (free_line(&line, 1));
	return (0);
}
