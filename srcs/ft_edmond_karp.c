/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edmond_karp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 04:27:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/17 16:53:41 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void    setBfsData(t_data *data, int nbr_nodes)
{
    int i;
    int nodes_sqrt;

    i = -1;
    nodes_sqrt = nbr_nodes * nbr_nodes;
    while (++i < nodes_sqrt)
        data->path[i] = NO_LINK;
    setQueue(data->queue, 0);
    data->first = TRUE;
    data->curr_node = 0;
    data->child_node = 0;
}

int bfs(t_data *data, int matrix[], int nbr_nodes)
{
    int i;
    int indexFrom;
    int IndexTo;
    int

    setBfsData(data, nbr_nodes);
    while (data->child_node != nbr_nodes - 1 && data->curr_node != END_OF_QUEUE)
    {
        if (data->first
        && (indexTo = isBackFlow(matrix, nbr_nodes, data->curr_node)) != -1)
        {
            enqueue(data->queue, indexTo);
            data->path[getIndex(data->curr_node, indexTo, nbr_nodes)] = USED_LINK;
            data->first = FALSE;
        }
        else
        {
            i = 0;
            while (i < nbr_nodes)
            {
                indexFrom = getIndex(data->curr_node, i, nbr_nodes);
                if (neverUsed(data, i, nbr_nodes) && matrix[indexFrom] != USED_LINK && matrix[indexFrom] != NO_LINK)
                {
                    enqueue(data->queue, indexFrom);
                    data->path[getIndex(data->curr_node, indexTo, nbr_nodes)] = USED_LINK;
                }
                i++;
            }
        }
        dequeue(data->queue);
        data->curr_node = data->queue[0];
    }
    return (getLastNode(data->path, nbr_nodes - 1, nbr_nodes));
}
