/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:12:19 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/18 19:01:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init(t_var	*var)
{
	var->linked_start = false;
	var->linked_end = false;
	var->have_start = 0;
	var->have_end = 0;
}

t_data	*setData(int nbr_nodes)
{
    t_data  *data;
    int     i;
    int     nodes_sqrt;

    i = -1;
    nodes_sqrt = nbr_nodes * nbr_nodes;
    if (!(data = ft_memalloc(sizeof(t_data))))
        exit(EXIT_FAILURE);
    data->prev_move = -1;
    data->nbr_move = 0;
	if (!(data->save = ft_memalloc(sizeof(int) * nodes_sqrt)))
		exit(EXIT_FAILURE);
    if (!(data->actual = ft_memalloc(sizeof(int) * nodes_sqrt))
    || !(data->path = ft_memalloc(sizeof(int) * nodes_sqrt)))
        exit(EXIT_FAILURE);
    while (++i < nodes_sqrt)
    {
        data->save[i] = 0;
        data->actual[i] = 0;
    }
    return (data);
}