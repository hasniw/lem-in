/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:41:16 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/26 00:51:40 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void			ft_print_name_matrix(t_var *var)
{
	int i = -1;

	while (i < var->nbr_vertex)
	{
		if 
	}
}

void			ft_set_matrix(t_var *var)
{
	int			i;
	t_vertex	*room;

	i = -1;
	room = (t_vertex *)var->vertex;
	while (++i < var->nbr_vertex)
	{
		var->matrix[i] = room->name;
		room = room->next;
	}
}

void		ft_create_matrix(t_var *var)
{
	int i;

	i = -1;
	var->matrix = (char **)malloc(sizeof(char *) * var->nbr_vertex);
	while (++i < var->nbr_vertex)
		var->matrix[i] = (char *)malloc(sizeof(char) * var->nbr_vertex);
}

void		ft_matrix(t_var *var)
{
	ft_create_matrix(var);
	ft_set_matrix(var);
}
