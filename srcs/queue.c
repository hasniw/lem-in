/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:52:29 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/17 16:52:29 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void    setQueue(int queue[], int node)
{
    queue[0] = node;
    queue[1] = END_OF_QUEUE;
}

void    enqueue(int queue[], int node)
{
    int i;

    i = 0;
    while (queue[i] != END_OF_QUEUE && i < QUEUE_MAX_LEN - 1)
        i++;
    queue[i] = node;
    queue[i + 1] = END_OF_QUEUE;
}

void    dequeue(int queue[])
{
    int i;

    i = 0;
    while (queue[i] != END_OF_QUEUE)
    {
        queue[i] = queue[i + 1];
        i++;
    }
}
