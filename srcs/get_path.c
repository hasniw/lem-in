/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:06 by wahasni           #+#    #+#             */
/*   Updated: 2020/03/03 00:34:39 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		updatemap(char *map, int u, int v, int size)
{
	map[v * size + u] ^= 3;
	map[u * size + v] ^= 3;
}

void			update_from_path(t_args *args, char *map, int u)
{
	while (u > 0)
	{
		updatemap(map, u, args->path[u], args->nb_vertice);
		u = args->path[u];
	}
}

int				get_path(t_args *args)
{
	int				u;
	static int		count = 10;

	if (!(check_path_yield(args, args->nb_vertice)))
	{
		if (count-- == 0)
		{
			ft_memdel((void**)&args->path);
			return (0);
		}
	}
	u = args->nb_vertice - 1;
	if (args->path[u] == 0 && args->edges[u] == '0')
	{
		ft_memdel((void**)&args->path);
		return (0);
	}
	update_from_path(args, args->edges, u);
	while (u > 0)
	{
		u = args->path[u];
		args->taken[u] = 1;
	}
	args->taken[u] = 0;
	return (1);
}
