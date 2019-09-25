/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_edge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 23:35:32 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/25 15:51:33 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_check_edges(t_var *var, char *line)
{
	char	**tab;

	if (ft_count_word(line, '-') == 1)
		return (1);
	tab = ft_strsplit(line, '-');
	if (tab[0] !exist || tab[1] !existe)
		free_line(&line, 1);
	//Assignement dans t_link
	// Check si les deux noms de room sont present et pas dautres caracteres entre '-'
}

int			ft_edge(t_var *var, char *line)
{
	if (ft_count_word(line, '-') || !is_comment(line))
	{
		if (!is_comment(line) || !ft_check_edge(var, line))
			free_line(&line, 1); // FREE LINKED LIST
	}
	else if (not one link for start and end)
	else // Line qu'on ne veut pas mais on traite quand meme car tous ce qu'on a avnt nous suffit
	return (0);
}