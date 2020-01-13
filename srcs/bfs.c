/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:37 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/13 15:21:54 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state;
}

int				get_max_bfs(t_var *var)
{
	return (ft_min(var->i_start, ft_min(var->i_end, var->nbr_ant)));
}

int			bfs(t_args *args)
{
	reinit_args(args);
	enqueue(args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args));
}
