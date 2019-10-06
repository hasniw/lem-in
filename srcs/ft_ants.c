/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 01:30:44 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/06 19:16:17 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_ants(t_var *var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(var->fd, &line)) > 0)
	{
		if ((ft_atoi(line) > 0 && is_number(line)) || !is_comment(line))
		{
			if (!is_comment(line))
				ft_strdel(&line);
			else
				var->nbr_ant = atoi(line);
		}
		else if (var->nbr_ant == 0)
		{
			ft_putstr("ERROR\n");
			return (free_line(&line, 1));
		}
		else
			return (0);
		if (var->nbr_ant)
			return (0);
	}
	return (0);
}