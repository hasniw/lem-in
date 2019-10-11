/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/11 17:19:17 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

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
	tab = ft_strsplit(line, '-'); // FREE TAB
	if (!ft_strcmp(tab[1], tab[0]))
		return (free_tab(tab, 1));
	if (!(room1 = ft_room_exist(var, tab[0])))
		return (free_tab(tab, 1)); //Erreur Don't exist room
	if (!(room2 = ft_room_exist(var, tab[1])))
		return (free_tab(tab, 1)); //Erreur Don't exist room
	ft_list_push_back_link(&room2->links, room1); // push dans la fin de la list links (cree fonction maybe)
	ft_list_push_back_link(&room1->links, room2); // push dans link last
	if (!ft_strcmp(room1->name, var->room_start->name) || !ft_strcmp(room2->name, var->room_start->name))
		var->linked_start = true;			// Pour etre sur d'avoir au moins 
	if (!ft_strcmp(room1->name, var->room_end->name) || !ft_strcmp(room2->name, var->room_end->name))	// une liaison start and end
		var->linked_end = true;
	return (0);
}

int				ft_edge(t_var *var, char *line)
{
	if (is_comment(line) != 1)
	{
		if (is_comment(line) == 0)
			return (free_line(&line, 0));
		else
			return (free_line(&line, 1));
	}
	else if (ft_count_word(line, '-') > 0)
		if (ft_check_edges(var, line))
			return (free_line(&line, 1)); // FREE LINKED LIST
	return (0);
}
