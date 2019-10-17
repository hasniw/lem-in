/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:55:47 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/17 16:49:35 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

static void	ft_init(t_var	*var)
{
	var->linked_start = false;
	var->linked_end = false;
	var->have_start = 0;
	var->have_end = 0;
}

int	main(int ac, char **av)
{
	t_var	*var;

	if (ac != 2)
	{
		ft_printf("Need two arguments\n");
		return (1);
	}
	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
        return (1);
	if ((var->fd = open(av[1], 0)) < 0)
		return (ft_printf("Opening file failed.\n"));
	ft_printf("{yellow}<--------------BEGIN PARSE--------------->{reset}\n");	
	ft_init(var);
	if (ft_parsing(var))
		return (1);
	ft_printf("{yellow}<-------------NBR FOURMI  : %d --------------->{reset}\n", (int)var->nbr_ant);	
	ft_printf("{yellow}<----------------------------->{reset}\n");
	ft_print_room(var);
	ft_printf("{yellow}<----------------------------->{reset}\n");
	ft_print_link(var);
	ft_matrix(var);
	ft_printf("{yellow}<----------------------------->{reset}\n");
	free_all(var);
	// int further;
    // int nbr_nodes = 6;
    // int matrix[6 * 6] =
    //     {0, 1, 0, 1, 0, 0,
    //     1, 0, 1, 0, 0, 0,
    //     0, 1, 0, 0, 0, 1,
    //     1, 0, 0, 0, 1, 0,
    //     0, 0, 0, 1, 0, 1,
    //     0, 0, 1, 0, 1, 0};
    // t_data data = setData(nbr_nodes);

    // further = 0;
    // while (further < 5)
    // {
    //     if (bfs(data, matrix, nbr_nodes) == - 1)
    //         break;
    //     storeNewPath(data, nbr_nodes);
    //     further = (!countMove(data, nbr_nodes)) ? further + 1 : 0;
    // }
    // //data->save;
    // print_moves();
	return (0);
}
