/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/29 19:31:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

// static int	ft_roomislinked(t_var *var) // FOR START AND END
// {

// 	return (1);
// } 

// Set value when i linked start or end
// Set value when i linked start or end
// Set value when i linked start or end
// Set value when i linked start or end
// Set value when i linked start or end

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

static int	ft_check_edges(t_var *var, char *line)
{
	char		**tab;
	t_vertex	*room1;
	t_vertex	*room2;

	if (ft_count_word(line, '-') == 1)
		return (1);
	tab = ft_strsplit(line, '-');
	if (!(room1 = ft_room_exist(var, tab[0])) || !(room2 = ft_room_exist(var, tab[1])))
		free_line(&line, 1);
	// room1->links->vertex = room2; // push dans link last
	// room2->links->vertex = room1; // push dans la fin de la list links (cree fonction maybe)
	// if (room = room_start)
	// 	linked_start = 1; 			// Pour etre sur d'avoir au moins 
	// else if (room = room_end)	// une liaison start and end
	// 	linked_end = 1;
	return (0);
}

int			ft_edge(t_var *var, char *line)
{
	if (ft_count_word(line, '-') || !is_comment(line))
	{
		if (!is_comment(line) || ft_check_edge(var, line))
			free_line(&line, 1); // FREE LINKED LIST
	}
	else if (linked_start && linked_end)
		free_line(&line, 1); // FREE LINKED LIST
	else // Line qu'on ne veut pas mais on traite quand meme car tous ce qu'on a avnt nous suffit
	return (0);
}