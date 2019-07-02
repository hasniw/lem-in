/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/02 04:19:32 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_room_exist(t_var *var)
{
	if (!var->vertex->name)
		return (1);
	return (0);
}

static void	ft_assign_room(t_var *var, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	ft_printf("TAB[0] : %s\n", tab[0]);
	if (var->type == other)
	{
		ft_printf("111111111111\n");
		ft_list_push_back(&var->vertex, (void *)tab[0]);
	}
	else if (var->type == start)
	{
		ft_printf("2222222222\n");
		ft_list_push_front(&var->vertex, (void *)tab[0]);
	}
	else if (var->type == end)
	{
		ft_printf("3333333333\n");
		var->pos_vertex_end = ft_list_size(var->vertex) + 1; // Pour connaitre la position dans la list de end
		ft_list_push_back(&var->vertex, (void *)tab[0]);
	}
	ft_printf("NAME : %s\n", var->vertex->name);
	if (var->vertex->next)
		ft_printf("NAME-NEXT : %s\n", var->vertex->name);
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

	while ((ret = get_next_line(0, &line)) > 0)
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
			return (free_line(&line, 0)); // LINE A GERER DANS ft_parse_links
		ft_printf("{red}<---ROOM LINE SUIVANTE--->{reset}\n");
	}
	return (0);
}
