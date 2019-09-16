/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/09 02:24:34 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_check_edges(t_var *var, char *line)
{
	if (ft_count_word(line, '-')
		return (1);
	// Check si les deux noms de room sont present et pas dautres caracteres entre '-'
}

int			ft_edge(t_var *var, char *line)
{
	if (ft_count_word(line, '-') || !is_comment(line))
	{
		if (!is_comment(line))
			ft_strdel(&line);
		else if (!ft_check_edge(var, line))
			free_line(&line, 1);
		else
			ft_assign_edge(var, line);
	}
	else if (not one link for start and end)
	else // Line qu'on ne veut pas mais on traite quand meme car tous ce qu'on a avnt nous suffit
	return (0);
}