/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:46:23 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/17 18:54:59 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    storeNewPath(t_data *data, int matrix[], int nbr_nodes)
{
	int i;
	int nodes_sqrt;
	int index;

	i = 0;
	nodes_sqrt = nbr_nodes * nbr_nodes;
	while (i < nodes_sqrt)
	{
		index = getIndex(i % nbr_nodes, i / nbr_nodes, nbr_nodes);
		if (data->path[i] == USED_LINK && data->actual[index] == USED_LINK)
		    data->actual[index] = NO_LINK;
		else
		    data->actual[i] = data->path[i];
		i++;
	}
	i = nbr_nodes - 1;
	while ((index = getLastNode(data->path, i, nbr_nodes)) != -1)
	{
		matrix[getIndex(index, i, nbr_nodes)] = USED_LINK;
		i = index;
	}
}

void    cpyPaths(t_data *data, int nbr_nodes)
{
    int i;
    int nodes_sqrt;

    i = 0;
    nodes_sqrt = nbr_nodes * nbr_nodes;
    while (i < nodes_sqrt)
    {
        data->save[i] = data->actual[i];
        i++;
    }
}
