/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/29 05:20:23 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_room_exist(t_var *var)
{
	return (0);
}

static void	ft_assign_room(t_var *var, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	if (var->type == other)
		ft_list_push_back(&var, (void *)tab[0]);
	else if (var->type == start)
		ft_list_push_front(&var, (void *)tab[0]);
	else if (var->type == end)
	{
		var->pos_vertex_end = ft_list_ + 1;
		ft_list_push_back(&var, (void *)tab[0]);
	}
	return (free_tab(tab, 0));
}

static int	ft_check_room(t_var *var, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	if (is_number(tab[1]) || is_number(tab[2])
	|| tab[0][0] == 'L')
		return (free_tab(tab, 1));
	while (var->vertex->next)
	{
		if (ft_strcmp(var->vertex->name, tab[0]))
			return (free_tab(tab, 1));
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
		var->type = true;
		if (ft_count_word(str, ' ') != 2 || is_comment(line))
		{
			if (get_comment(line) != 1)
				ft_strdel(&line);
			else if (ft_check_room(var, line))
			{
				ft_strdel(&line);
				return (1);
			}
			else
				ft_assign_room(var, line);
		}
		else if (si on a au moins room start / end)
			return (free_line(line, 0));
		else
			return (free_line(line, 1));
	}
	return (0);
}