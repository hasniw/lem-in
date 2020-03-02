/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:55:47 by wahasni           #+#    #+#             */
/*   Updated: 2020/03/03 00:24:39 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <fcntl.h>

static int	print_error(int i)
{
	write(1, "ERROR\n", 6);
	return (i);
}

int			free_var(t_var *var, int i)
{
	free(var);
	return (i);
}

static void	ft_init(t_var *var)
{
	var->linked_start = false;
	var->linked_end = false;
	var->have_start = 0;
	var->have_end = 0;
	var->fd = 0;
	var->room_end = NULL;
	var->room_start = NULL;
}

static int	lem_in(t_var *var)
{
	int		max_bfs;

	write(1, "\n", 1);
	max_bfs = get_max_bfs(var);
	if (algo(&var->matrix, (int)var->nbr_vertex, max_bfs, var->nbr_ant))
		single_path(var->nbr_ant, var->room_end);
	else if (!(output(var->matrix, var)))
	{
		ft_strdel(&var->matrix);
		return (0);
	}
	if (var->flag & LINKED)
		ft_print_link(var);
	if (var->flag & MAP)
		print_matrix(var->matrix);
	ft_strdel(&var->matrix);
	return (1);
}

int			main(int ac, char **av)
{
	t_var	*var;
	char	*line;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (print_error(-1));
	if (check_arg(var, av[1], ac))
		return (free_var(var, -1));
	ft_init(var);
	if (ft_parsing(var))
	{
		while (get_next_line(var->fd, &line) > 0)
		{
			ft_putendl(line);
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
