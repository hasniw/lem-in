/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:27:47 by wahasni           #+#    #+#             */
/*   Updated: 2020/04/03 17:26:05 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_source(char *map, int u, int v, int size)
{
	int i;

	if (u == 0 || v == 0)
		return (1);
	else if (u == size - 1 || v == size - 1)
		return (0);
	i = 0;
	while (i < size)
	{
		if (map[size * u + i] & TAKEN && i != v)
			return (find_source(map, i, u, size));
		i++;
	}
	return (0);
}

static int		get_adj_vertice(char *map, int v, int size, int *val1)
{
	int i;
	int val2;

	i = 0;
	val2 = 0;
	*val1 = 0;
	while (i < size)
	{
		if (map[size * v + i] & TAKEN)
		{
			if (!(*val1))
				*val1 = i;
			else
				val2 = i;
		}
		if (val2 == size - 1 || (*val1 && val2))
			return (val2);
		i++;
	}
	return (val2);
}

static int		find_previous(char *map, int v, int size)
{
	int val1;
	int val2;

	val2 = get_adj_vertice(map, v, size, &val1);
	if (v == val1 || v == val2 || val1 == 0 || val2 == 0)
	{
		return (0);
	}
	return (find_source(map, val1, v, size) ? val1 : val2);
}

int				check_taken(t_args *args, int vertex)
{
	int i;
	int size;

	i = 0;
	size = args->nb_vertice;
	if (vertex == size - 1)
		return (1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] & TAKEN)
			return (0);
		i++;
	}
	return (1);
}

int				get_previous(int vertex, t_args *args)
{
	int i;
	int size;

	i = 0;
	size = args->nb_vertice;
	if (vertex == size - 1 || vertex == 0)
		return (-1);
	while (i < size)
	{
		if (args->edges[vertex + (size * i)] & TAKEN)
			return (find_previous(args->edges, vertex, size));
		i++;
	}
	return (-1);
}
