/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edges.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/03 03:51:27 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_edges(t_var *var, char *line)
{
	if (ft_count_word(line, '-') || !is_comment(line))
	{
		if (!is_comment(line))
			ft_strdel(&line);
		else if (!ft_check_edges(var, line))
			free_line(&line, 1);
		else
			
	}
	return (0);
}