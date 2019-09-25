/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/25 15:18:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		ft_print_room(t_var *var)
{
	int i = 1;
	t_vertex *tmp = var->vertex;

	while (tmp)
	{
		ft_printf("ROOM %d : %s\n", i, tmp->name);
		i++;
		tmp = tmp->next;
	}
}

int			ft_parsing(t_var *var)
{
	int		ret;
	char	*line;

	printf("begin parser\n");
	if (ft_ants(var))
	{
		ft_printf("ERREUR ENTREE PARSING NBR FOURMI");
		return (1);
	}
	ft_printf("NBR DE FOURMI : %d\n", (int)var->nbr_ant);
	if (ft_room(var))
	{
		ft_printf("{erreur} NBR DE VERTEX : %d\n", (int)var->nbr_vertex);
		ft_print_room(var);
		return (1);
	}
	ft_printf("NBR DE VERTEX : %d\n", (int)var->nbr_vertex);
	ft_print_room(var);
	ft_printf("YOLO : %d\n", var->pos_vertex_start);
	// ft_matrix(var);
	if (var->line)
	{
		if (ft_edges(var, var->line))
		{
			ft_printf("ERREUR FIRST LINE EDGES\n");
			free_line(&var->line, 1);
		}
	}
	while ((ret = get_next_line(var->fd, &line)) > 0)
	{
		if (ft_edges(var, line))
		{
			ft_printf("ERREUR EDGES");
			free_line(&line, 1);
		}
	}
		return (1);
	return (0);
}
