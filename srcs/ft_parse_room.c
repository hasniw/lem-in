/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/25 18:18:34 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_room_exist(t_var *var)
{
	if (!var->vertex->name)
		return (1);
	// Check si room start et end existant
	return (0);
}

static void	ft_assign_room(t_var *var, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	ft_printf("TAB[0] : %s\n", tab[0]);
	if (var->type == other && !var->have_start)
		ft_list_push_front(&var->vertex, (void *)tab[0]);
	else if (var->type == other && var->have_start)
	{
		printf("IN HAVE START : %s\n", tab[0]);
		ft_list_push_second(&var->vertex, (void *)tab[0]);
	}
	else if (var->type == start)
	{
		// var->pos_vertex_start = 1;
		var->have_start = start;
		ft_list_push_front(&var->vertex, (void *)tab[0]);
	}
	else if (var->type == end)
		ft_list_push_back(&var->vertex, (void *)tab[0]);
	// if (var->pos_vertex_start > 0 && var->type != start)
	// 	var->pos_vertex_start++;
	var->type = other;
	var->nbr_vertex++;
	while (tab[i])
		free(tab[i++]);
	free(tab);
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

	var->have_start = 0;
	while ((ret = get_next_line(var->fd, &line)) > 0)
	{
		ft_printf("{black}ROOM LINE : %s{reset}\n", line);
		if (ft_count_word(line, ' ') == 2 || is_comment(line) != 1)
		{
			if (get_comment(var, line) != 1)
				ft_strdel(&line);
			else if (!ft_check_room(var, line))
				free_line(&line, 1);
			else
				ft_assign_room(var, line);
		}
		else if (ft_room_exist(var))
			return (free_line(&line, 1));
		else
		{
			var->line = ft_strdup(line);
			return (free_line(&line, 0)); // LINE A GERER DANS ft_parse_links
		}
		ft_printf("{red}<---ROOM LINE SUIVANTE--->{reset}\n");
	}
	return (0);
}
