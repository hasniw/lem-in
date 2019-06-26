/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 01:30:44 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/26 03:25:46 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_ants(t_var *var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &args->line)) != 1)
	{
		if (is_number(line) && is_comment(line))
		{
			if (is_comment(line))
				ft_strdel(&line);
			else
				var->nbr_ant = atoi(line);
		}
		else
		{
			ft_putstr("ERROR\n");
			exit (free_line(&line, 1));
		}
	}
	return (0);
}