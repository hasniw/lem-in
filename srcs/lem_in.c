/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:55:47 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/06 23:21:46 by hasni            ###   ########.fr       */
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
	var->fd = 0;
	var->flag = 0;
}

static bool	lem_in(t_var *var)
{
	int		max_bfs;

	max_bfs = 0;
	max_bfs = get_max_bfs(var);
	if (algo(&var->matrix, (int)var->nbr_vertex, max_bfs, var->nbr_ant))
		done_single_path(var->nbr_ant, var->room_end);
	else if (!(output(var->matrix, var)))
	{
		ft_strdel(&var->matrix);
		return (0);
	}
	if (var->flag & MAP)
		print_map(var->matrix);
	ft_strdel(&var->matrix);
	return (1);
}

static int	get_flags(t_var *var, char *flag)
{
	int i;

	i = 1;
	if (flag[0] != '-')
		return (-1);
	while (flag[i])
	{
		if (flag[i] == 'q')
			var->flag |= QUIET;
		else if (flag[i] == 'c')
			var->flag |= COLOR;
		else if (flag[i] == 'm')
			var->flag |= MAP;
		else
			return (-1);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_var	*var;

	(void)ac;
	(void)av;
	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
        return (1); // Protect error in get_flags
	if (ac > 1)
	{
		if (get_flags(var, av[1]) < 0 || ac > 2)
		{
			write(1, "usage: ./lem-in [-cmq] < a lem_in map\n", 38);
			return (-1);
		}
	}
	// ft_printf("{yellow}<--------------BEGIN PARSE--------------->{reset}\n");	
	ft_init(var);
	if (ft_parsing(var))
		return (1);
	// ft_printf("{yellow}<-------------NBR FOURMI  : %d --------------->{reset}\n", (int)var->nbr_ant);	
	// ft_printf("{yellow}<----------------------------->{reset}\n");
	// ft_print_room(var);
	// ft_printf("{yellow}<----------------------------->{reset}\n");
	// ft_print_link(var);
	ft_matrix(var);
	if (!(lem_in(var)))
		write(1, "ERROR\n", 6);
	// ft_printf("{yellow}<----------------------------->{reset}\n");
	free_all(var);
	return (0);
}
