/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/09 03:28:23 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_room_exist(t_var *var) // Tcheck si on a au moins une room et que start et end existe
{
	return (!var->vertex || !var->vertex->name || !var->have_start || !var->have_end);
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

static int	ft_check_room(t_var *var, char *str)
{
	char	**tab;

	if ((var->type == start && var->have_start == 1)
		|| (var->type == end && var->have_end == 1))
		return (0);
	tab = ft_strsplit(str, ' ');
	if (!tab[1] || !tab[2])
		return (free_tab(tab, 0));
	if (!ft_isnumber(tab[1]) && !ft_isnumber(tab[2]) && tab[0][0] != 'L')
		return (free_tab(tab, 1));
	return (free_tab(tab, 0));
}

int			ft_room(t_var *var)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(var->fd, &line)) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		if (ft_count_word(line, ' ') == 2 || (is_comment(line, var) != 1 && is_comment(line, var) != -1))
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
		else if (ft_room_exist(var))
			return (free_line(&line, 1));
		else if (is_comment(line, var) == -1)
			return (free_line(&line, 1));
		else
		{
			var->line = ft_strdup(line);
			return (free_line(&line, 0));
		}
	}
	return (0);
}
