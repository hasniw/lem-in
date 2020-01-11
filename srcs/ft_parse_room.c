/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 17:13:55 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	assign_line(t_var *var, char *line)
{
	var->line = ft_strdup(line);
	return (free_line(&line, 0));
}

static void	ft_assign_room(t_var *var, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	if (var->type == other && var->have_start == 0)
		ft_list_push_front(&var->vertex, (void *)tab[0]);
	else if (var->type == other && var->have_start == 1)
		ft_list_push_second(&var->vertex, (void *)tab[0]);
	else if (var->type == start)
	{
		var->have_start = 1;
		ft_list_push_front(&var->vertex, (void *)tab[0]);
		var->room_start = ft_strdup(tab[0]);
	}
	else if (var->type == end)
	{
		var->have_end = 1;
		ft_list_push_back(&var->vertex, (void *)tab[0]);
		var->room_end = ft_strdup(tab[0]);
	}
	var->type = other;
	var->nbr_vertex++;
	free_tab(tab, 0);
}

int			ft_room(t_var *var)
{
	char	*line;

	while (get_next_line(var->fd, &line) > 0)
	{
		ft_putendl(line);
		if (ft_check_condition(var, line))
		{
			if (get_comment(var, line) != 1)
				ft_strdel(&line);
			else if (!ft_check_room(var, line))
				return (free_line(&line, 1));
			else
			{
				ft_assign_room(var, line);
				ft_strdel(&line);
			}
		}
		else if (ft_vertex_exist(var))
			return (free_line(&line, 1));
		else if (is_comment(line, var) == -1)
			return (free_line(&line, 1));
		else
			return (assign_line(var, line));
	}
	return (0);
}
