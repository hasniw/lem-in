/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/01 16:14:07 by wahasni          ###   ########.fr       */
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
	tab = ft_strsplit(line, '-');
	if (!(room1 = ft_room_exist(var, tab[0])))
		free_line(&line, 1);
	if (!(room2 = ft_room_exist(var, tab[1])))
		free_line(&line, 1);
	printf("room1 : %s\n", room1->name);
	printf("room2 : %s\n", room2->name);
	ft_list_push_back_link(&room1->links, room2); // push dans link last
	ft_list_push_back_link(&room2->links, room1); // push dans la fin de la list links (cree fonction maybe)
	if (!ft_strcmp(room1->name, var->room_start->name) || !ft_strcmp(room2->name, var->room_start->name))
	{
		printf("SET LINKED_START TO TRUE\n");
		var->linked_start = true; 			// Pour etre sur d'avoir au moins 
	}
	else if (!ft_strcmp(room1->name, var->room_end->name) || !ft_strcmp(room2->name, var->room_end->name))	// une liaison start and end
	{
		printf("SET LINKED_END TO TRUE\n");
		var->linked_end = true;
	}
	return (0);
}

// Maybe try to know if the room1 and room2 are star or end 

int				ft_edge(t_var *var, char *line)
{
	var->linked_start = false;
	var->linked_end = false;
	ft_printf("{red}IN EDGE : %s{reset}\n", line);
	printf("count_word of '-' : %d\n", ft_count_word(line, '-'));
	printf("Is_comment value : %d\n", is_comment(line));
	if (!is_comment(line))
	{
		printf("It's a comment : %s\n", line);
		return (free_line(&line, 0));
	}
	else if (ft_count_word(line, '-') > 0)
	{
		printf("MILI-Before check-edges\n");	
		if (ft_check_edges(var, line))
			return (free_line(&line, 1)); // FREE LINKED LIST
	}
	else if (var->linked_start == false || var->linked_end == false)
	{
		printf("You don't linked start or end\n");
		// return (free_line(&line, 1)); // FREE LINKED LIST
	}
	return (0);
}
