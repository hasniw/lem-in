/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:55:47 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 00:58:59 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

static int	print_error(int i)
{
	write(1, "ERROR\n", 6);
	return (i);
}

static void	ft_init(t_var	*var)
{
	var->linked_start = false;
	var->linked_end = false;
	var->have_start = 0;
	var->have_end = 0;
	var->fd = 0;
	var->flag = 0;
	var->room_end = NULL;
	var->room_start = NULL;
}

static bool	lem_in(t_var *var)
{
	int		max_bfs;

	write(1, "\n", 1);
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
	char	*line;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
        return (print_error(-1));
	if (ac > 1)
	{
		if (get_flags(var, av[1]) < 0 || ac > 2)
		{
			write(1, "usage: ./lem-in [-cmq] < a lem_in map\n", 38);
			return (free_var(var, -1));
		}
	}
	ft_init(var);
	if (ft_parsing(var))
	{
		while (get_next_line(var->fd, &line) > 0)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			ft_strdel(&line);
		}
		write(1, "\n", 1);
		return (print_error(-1));
	}
	if (ft_matrix(var))
		return (free_all(var, 0));
	if (!(lem_in(var)))
		print_error(-1);
	return (free_all(var, 0));
}
