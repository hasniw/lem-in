/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:41:16 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/04 18:28:58 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

// void			ft_print_name_matrix(t_var *var)
// {
// 	int i = -1;

// 	while (i < var->nbr_vertex)
// 	{
// 		if 
// 	}
// }

void		ft_create_matrix(t_var *var)
{
	size_t		i;
	t_vertex	*vertex;

	vertex = (t_vertex *)var->vertex;
	i = -1;
	var->matrix_name = (char **)malloc(sizeof(char *) * var->nbr_vertex);
	while (++i < var->nbr_vertex)
	{
		var->matrix_name[i] = ft_strdup(vertex->name);
		vertex = vertex->next;
	}
	var->matrix = (int *)malloc(sizeof(int) * var->nbr_vertex * var->nbr_vertex);
	ft_memset(var->matrix, 0, var->nbr_vertex * var->nbr_vertex);
}

void		ft_matrix(t_var *var)
{
	// int i = -1;

	ft_create_matrix(var);
	// while (var->matrix_name[++i])
	// 	printf("matrix_name[%d] : %s\n", i, var->matrix_name[i]);
}
