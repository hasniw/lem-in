/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:47 by wahasni           #+#    #+#             */
/*   Updated: 2020/03/03 00:28:49 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_args	*init_args(int nb_vert, char **edges, int max_bfs, int nb_ant)
{
	t_args *args;

	if (!(args = malloc(sizeof(t_args))))
		return (NULL);
	if (!(args->state = ft_strnew(nb_vert)))
		return (NULL);
	if (!(args->saved_map = ft_strnew(nb_vert * nb_vert)))
		return (NULL);
	if (!(args->taken = ft_memalloc((nb_vert) * sizeof(int))))
		return (NULL);
	if (!(args->went_back = ft_memalloc((nb_vert) * sizeof(int))))
		return (NULL);
	if (!(args->path = ft_memalloc(nb_vert * sizeof(int))))
		return (NULL);
	if (!(args->edges = ft_strdup(*edges)))
		return (NULL);
	ft_memset(args->state, INITIAL, nb_vert);
	args->max_bfs = max_bfs;
	args->nb_ant = nb_ant;
	args->step_number = 0;
	args->nb_vertice = nb_vert;
	if (!(args->queue = ft_memalloc(sizeof(t_queue))))
		return (NULL);
	return (args);
}

void			reinit_args(t_args *args)
{
	ft_memset(args->state, INITIAL, ft_strlen(args->state));
	ft_memset(args->went_back, 0, args->nb_vertice * sizeof(int));
	ft_memset(args->path, 0, args->nb_vertice * sizeof(int));
	ft_bzero(args->queue, sizeof(t_queue));
}

int				ft_algo(char **edges, int size, int max_bfs, int nb_ant)
{
	t_args	*args;
	int		max;

	if ((*edges)[size - 1] == '1')
		return (1);
	max = max_bfs;
	if (!(args = init_args(size, edges, max_bfs, nb_ant)))
		return (1);
	while (max_bfs > 0)
	{
		if (!bfs(args))
			break ;
		max_bfs--;
		free_queue_vertex(args->queue);
	}
	ft_memcpy(*edges, args->saved_map, size * size);
	free_args(args);
	return (0);
}
