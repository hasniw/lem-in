/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 16:41:42 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 17:49:00 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int			check_arg(t_var *var, char *av, int ac)
{
	if (ac > 1)
	{
		if (get_flags(var, av) < 0 || ac > 2)
		{
			write(1, "usage: ./lem-in [-cmq] < a lem_in map\n", 38);
			return (-1);
		}
	}
	return (0);
}
