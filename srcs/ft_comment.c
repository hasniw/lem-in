/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:34:20 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 17:53:27 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	is_comment(char *str, t_var *var)
{
	if (str[0] != '#')
		return (1);
	if ((!ft_strcmp("##start", str) && var->have_start == 1)
		|| (!ft_strcmp("##end", str) && var->have_end == 1))
		return (-1);
	if (str[1] == '#')
	{
		if (!ft_strcmp("start", str + 2))
			return (2);
		else if (!ft_strcmp("end", str + 2))
			return (3);
	}
	return (0);
}

int	get_comment(t_var *var, char *str)
{
	if (is_comment(str, var) == 1 || (var->type == start || var->type == end))
		return (1);
	if (!is_comment(str, var))
		var->type = other;
	else if (is_comment(str, var) == 2)
		var->type = start;
	else if (is_comment(str, var) == 3)
		var->type = end;
	return (0);
}
