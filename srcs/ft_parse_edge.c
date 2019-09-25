/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/25 17:14:26 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_roomislinked(var)
{
	return (1);
}

static int	ft_room_exist(t_var *var, char *str)
{
	t_vertex	*room;

	room = (t_vertex *)var->vertex;
	while (room)
	{
		if (ft_strequ(room->name, str))
			return (0);
		room = room->next;
	}
	return (1);
}

static int	ft_check_edges(t_var *var, char *line)
{
	char	**tab;

	if (ft_count_word(line, '-') == 1)
		return (1);
	tab = ft_strsplit(line, '-');
	if (ft_room_exist(var, tab[0]) || ft_room_exist(var, tab[1]))
		free_line(&line, 1);
	
	//Assignement dans t_link
	
	// Check si les deux noms de room sont present et pas dautres caracteres entre '-'
}

int			ft_edge(t_var *var, char *line)
{
	if (ft_count_word(line, '-') || !is_comment(line))
	{
		if (!is_comment(line) || !ft_check_edge(var, line))
			free_line(&line, 1); // FREE LINKED LIST
	}
	else if (not one link for start and end)
		free_line(&line, 1); // FREE LINKED LIST
	else // Line qu'on ne veut pas mais on traite quand meme car tous ce qu'on a avnt nous suffit
	return (0);
}