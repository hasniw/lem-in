/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:02:37 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 17:50:23 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_check_condition(t_var *var, char *line)
{
	if (ft_count_word(line, ' ') == 2
		|| (is_comment(line, var) != 1 && is_comment(line, var) != -1))
		return (1);
	return (0);
}

int	ft_vertex_exist(t_var *var)
{
	return (!var->vertex || !var->vertex->name
		|| !var->have_start || !var->have_end);
}

int	ft_check_room(t_var *var, char *str)
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
