/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:41:16 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/07 18:51:42 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static void		ft_print_matrix(t_var *var)
{
	size_t	i = 0;
	size_t	j = 0;
	while (i < var->nbr_vertex)
	{
		while (j < var->nbr_vertex)
			ft_printf("{blue}[%d]{reset}", var->matrix[j++]);
		j = 0;
		i++;
	}
	ft_printf("\n");
}

static void		assign_matrix(t_vertex *vertex, char **name, t_var *var, int x)
{
	int			i;
	t_vertex	*room;

	i = 0;
	room = (t_vertex *)vertex;
	while (vertex->links)
	{
		while (ft_strequ(vertex->links->vertex->name, name[i]) != 1)
			i++;
		if (ft_strequ(vertex->links->vertex->name, name[i]))
		{
			printf("POPO : 1er : %d | 2eme : %d\n", (int)(x + i * var->nbr_vertex), (int)(i + x * var->nbr_vertex));
			var->matrix[x + i * var->nbr_vertex] = 1;
			var->matrix[i + x * var->nbr_vertex] = 1;
			i = 0;
			vertex->links = vertex->links->next;
		}
	}
}

static void		ft_set_matrix(t_var *var)
{
	size_t		y;
	size_t		x;
	t_vertex	*room;

	room = (t_vertex *)var->vertex;
	y = 0;
	while (y < var->nbr_vertex)
	{
		x = 0;
		while (x < var->nbr_vertex)
		{
			ft_printf("{green}Value of x : %d & y : {reset}%d\n", (int)x, (int)y);
			ft_printf("{red}before assign_matrix{reset}\n");
			assign_matrix(room, var->matrix_name, var, x);
			ft_printf("{red}after assign_matrix{reset}\n");
			room = room->next;
			x++;
		}
		y++;
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
	// int i = 0;   

	printf("YTSDGDFGDSFG : %d\n", ft_strequ("aA", "aA"));
	ft_create_matrix(var);
	ft_print_matrix(var);
	ft_set_matrix(var);
	// while (var->matrix_name[i])
	// {
	// 	printf("matrix_name[%d] : %s\n", i, var->matrix_name[i]);
	// 	i++;
	// }
}
