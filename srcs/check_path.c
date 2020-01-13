/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:25 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/13 15:28:45 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_used_link(t_args *args, int vertex, int i)
{
	return (args->edges[vertex * args->nb_vertice + i] & TAKEN);
}

int	check_link(t_args *args, int vertex, int i)
{
	return (args->edges[vertex * args->nb_vertice + i] & LINK);
}

int	check_end(t_args *args, int vertex, int i)
{
	return (i == args->nb_vertice - 1 || vertex == args->nb_vertice - 1);
}

int	check_connection(t_args *args, int vertex, int to)
{
	return (check_used_link(args, vertex, to) || check_link(args, vertex, to));
}

int	check_available(char *state, int vertex)
{
	return (state[vertex] == INITIAL);
}
