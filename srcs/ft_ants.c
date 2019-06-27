/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 01:30:44 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/27 07:02:01 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_ants(t_var *var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		// Peut on avoir plusieurs nombre de fourmis ?
		if (ft_atoi(line) > 0 || !is_comment(line))
		{
			if (!is_comment(line))
				ft_strdel(&line);
			else
				var->nbr_ant = atoi(line);
		}
		else if (var->nbr_ant == 0)
		{
			ft_putstr("ERROR\n");
			exit (free_line(&line, 1));
		}
		else
			return (0);
	}
	return (0);
}