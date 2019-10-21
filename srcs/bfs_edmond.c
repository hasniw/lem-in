/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_edmond.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:44:01 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/17 18:44:01 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		getIndex(int from, int to, int nbr_nodes)
{
    return (nbr_nodes * from + to);
}

int		isBackFlow(int *matrix, int nbr_nodes, int to_node)
{
    int i;
    int index;

    i = 0;
    while (i < nbr_nodes)
    {
        index = getIndex(i, to_node, nbr_nodes);
        if (i != 0 && matrix[index] == USED_LINK)
            return (i);
        i++;
    }
    return (-1);
}

int     neverUsed(t_data *data, int node2, int nbr_nodes)
{
    int indexFrom;
    int indexTo;

    indexFrom = getIndex(data->curr_node, node2, nbr_nodes);
    indexTo = getIndex(node2, data->curr_node, nbr_nodes);
    if (data->path[indexFrom] != NO_LINK || data->path[indexTo] != NO_LINK)
        return (FALSE);
    return (TRUE);
}

int     getLastNode(int path[], int to_node, int nbr_nodes)
{
    int i;
    int index;

    i = 0;
    while (i < nbr_nodes)
    {
        index = getIndex(i, to_node, nbr_nodes);
        if (path[index] == LINK)
            return (i);
        i++;
    }
    return (-1);
}

int    countMove(t_data *data, int nbr_nodes, int nbr_ant)
{
    int nbr_usable_nodes;
    int i;
    int nodes_sqrt;
    int nbr_path;

    i = -1;
    nodes_sqrt = nbr_nodes * nbr_nodes;
    nbr_usable_nodes = 0;
    nbr_path = 0;
    while (++i < nodes_sqrt)
    {
        nbr_path += (data->actual[i] == USED_LINK && i < nbr_nodes) ? 1 : 0
        nbr_usable_nodes += (data->actual[i] == USED_LINK) ? 1 : 0;
    }
    if (data->prev_move == -1 || data->prev_move > /*calcul*/)
    {
        data->prev_move = /*calcul*/;
        cpyPaths();
        return (TRUE);
    }
    return (FALSE);
}
