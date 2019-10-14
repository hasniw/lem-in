/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:41:16 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/14 19:27:09 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		ft_print_matrix(t_var *var)
{
	size_t	j = 0;
	while (j < var->nbr_vertex * var->nbr_vertex)
	{
		if (var->matrix[j] == 1)
			ft_printf("{blue}[%d]{reset}", (int)j++);
		else
			ft_printf("{blue}[%d]{reset}", var->matrix[j++]);
	}
	ft_printf("\n");
}

static void		assign_matrix(t_vertex *vertex, char **name, t_var *var, int x)
{
	int			i;
	t_links		*links;

	i = 0;
	links = (t_links *)vertex->links;
	while (links)
	{
		if (!links->vertex)
			return ;
		while (ft_strequ(links->vertex->name, name[i]) != 1)
			i++;
		if (ft_strequ(links->vertex->name, name[i]))
		{
			var->matrix[x + i * var->nbr_vertex] = 1;
			var->matrix[i + x * var->nbr_vertex] = 1;
			i = 0;
			links = links->next;
		}
	}
}

static void		ft_set_matrix(t_var *var)
{
	size_t		i;
	t_vertex	*room;

	room = (t_vertex *)var->vertex;
	i = 0;
	while (i < var->nbr_vertex)
	{
		assign_matrix(room, var->matrix_name, var, i++);
		room = room->next;
	}
}

void		ft_create_matrix(t_var *var)
{
	size_t		i;
	t_vertex	*vertex;

	vertex = (t_vertex *)var->vertex;
	i = -1;
	var->matrix_name = (char **)ft_memalloc(sizeof(char *) * (var->nbr_vertex + 1));
	while (++i < var->nbr_vertex)
	{
		var->matrix_name[i] = ft_strdup(vertex->name);
		vertex = vertex->next;
	}
	var->matrix = (int *)ft_memalloc(sizeof(int) * (var->nbr_vertex * var->nbr_vertex + 1));
}

void		ft_matrix(t_var *var)
{
	ft_printf("{yellow}<----------------------------->{reset}\n");
	ft_printf("{yellow}Set matrix{reset}\n");
	ft_create_matrix(var);
	ft_print_matrix(var);
	ft_set_matrix(var);
	ft_print_matrix(var);
}
