/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:41:16 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/10 19:31:27 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			var->matrix[x + i * var->nbr_vertex] |= LINK;
			var->matrix[i + x * var->nbr_vertex] |= LINK;
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

static int	ft_create_matrix(t_var *var)
{
	size_t		i;
	t_vertex	*vertex;

	vertex = (t_vertex *)var->vertex;
	i = -1;
	if (!(var->matrix_name = (char **)ft_memalloc(sizeof(char *) * (var->nbr_vertex + 1))))
		return (0);
	while (++i < var->nbr_vertex)
	{
		if (!(var->matrix_name[i] = ft_strdup(vertex->name)))
			return (0);
		vertex = vertex->next;
	}
	if (!(var->matrix = ft_strnew(sizeof(char) * (var->nbr_vertex * var->nbr_vertex))))
		return (0);
	ft_memset(var->matrix, '0', var->nbr_vertex * var->nbr_vertex);
	return (1);
}

int			ft_matrix(t_var *var)
{
	if (!ft_create_matrix(var))
		return (1);
	ft_set_matrix(var);
	return (0);
}
