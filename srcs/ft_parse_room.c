/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/27 23:27:38 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void	ft_assign_room(t_var *var, char *str)
{
	//Si le maillon est vide, parcourir la liste chainee sinon
	//En fonction de l'etat : t_type 
	//Stocker name dans room:start / room:end  / room
	return (0);
}

static int	ft_check_room(t_var *var, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	if (is_number(tab[1]) || is_number(tab[2])
	|| tab[0][0] == 'L')
	{
		free(tab);
		return (1);
	}
	while (var->vertex)
	{
		if (ft_strcmp(var->vertex->name, tab[0]))
		{
			free(tab);
			return (1);
		}
		var->vertex = var->vertex->next;
	}
	return (0);
}

int			ft_room(t_var *var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &args->line)) != 1)
	{
		if (ft_count_word(str, ' ') != 2 || is_comment(line))
		{
			if (get_comment(line) == 1)
				ft_strdel(&line);
			else if (ft_check_room(var, line))
				ft_strdel(&line); //ERROR
			else
				ft_assign_room(var, line);
		}
		else if (room_exist)
		{
			// ERROR
			exit (1);
		}
		else if
			return (free_line(line, 1));
	}
	return (0);
}