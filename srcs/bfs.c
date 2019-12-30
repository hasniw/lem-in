/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:29:37 by wahasni           #+#    #+#             */
/*   Updated: 2019/12/29 22:25:01 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include "struct_parsing.h"

void			change_state(char **state, int vertex, int new_state)
{
	(*state)[vertex] = new_state;
}

int				get_max_bfs(t_var *var)
{
	return (ft_min(var->i_start, ft_min(var->i_end, var->nbr_ant)));
}

bool			bfs(t_args *args)
{
	reinit_args(args);
	enqueue(args->queue, 0);
	change_state(&args->state, 0, WAITING);
	return (find_path(args));
}