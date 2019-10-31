/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edmond_karp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 04:27:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/18 18:59:20 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	setBfsData(t_data *data, int nbr_nodes)
{
    int i;
    int nodes_sqrt;

    i = -1;
    nodes_sqrt = nbr_nodes * nbr_nodes;
    while (++i < nodes_sqrt)
        data->path[i] = NO_LINK;
    setQueue(data->queue, 0);
    data->first = true;
    data->curr_node = 0;
    data->child_node = 0;
}

int		bfs(t_data *data, int *matrix, int nbr_nodes)
{
    int i;
    int indexFrom;
    int IndexTo;

    setBfsData(data, nbr_nodes);
    while (data->child_node != nbr_nodes - 1 && data->curr_node != END_OF_QUEUE)
    {
        if (data->first
        && (IndexTo = isBackFlow(matrix, nbr_nodes, data->curr_node)) != -1)
        {
            enqueue(data->queue, IndexTo);
            data->path[getIndex(data->curr_node, IndexTo, nbr_nodes)] = USED_LINK;
            data->first = false;
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
                    data->path[getIndex(data->curr_node, IndexTo, nbr_nodes)] = USED_LINK;
                }
                i++;
            }
        }
        dequeue(data->queue);
        data->curr_node = data->queue[0];
    }
	ft_printf("{red}Value : %d{reset}\n", getLastNode(data->path, nbr_nodes - 1, nbr_nodes));
    return (getLastNode(data->path, nbr_nodes - 1, nbr_nodes));
}

int		ft_algo(t_var *var)
{
    int     i = 0;
	int		further;
	t_data	*data;

	ft_printf("{yellow}SetData{reset}\n");
	data = setData(var->nbr_vertex);
	ft_printf("{yellow}Data are set{reset}\n");	
	further = 0;
	while (further < 5 || i < 10)
	{
	    printf("I : %d\n", i);
	    if (bfs(data, var->matrix, (int)var->nbr_vertex) == - 1)
	    {
			ft_printf("{red}Break because bfs doesn't work{reset}\n");
			break;
		}
		storeNewPath(data, var->matrix, (int)var->nbr_vertex);
	    further = (!countMove(data, var->nbr_vertex, (int)var->nbr_ant)) ? further + 1 : 0;
	    i++;
	}
	//data->save;
	// print_moves();
	return (0);
}
