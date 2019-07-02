/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:34:20 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/02 04:07:24 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int	is_comment(char *str)
{
	if (str[0] != '#')
		return (1);
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
	if (is_comment(str) == 1 || (var->type == start || var->type == end)) // Si avant ##START ou ##END 
		return (1);
	if (!is_comment(str))
		var->type = other;
	else if (is_comment(str) == 2)
		var->type = start;
	else if (is_comment(str) == 3)
		var->type = end;
	return (0);
}