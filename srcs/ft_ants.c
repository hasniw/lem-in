/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ants.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 01:30:44 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/10 18:09:52 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_ants(t_var *var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(var->fd, &line)) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		if ((ft_atoi(line) > 0 && !ft_isnumber(line)) || !is_comment(line, var))
		{
			if (!is_comment(line, var))
				ft_strdel(&line);
			else
			{
				var->nbr_ant = atoi(line);
				ft_strdel(&line);
			}
		}
		else if (var->nbr_ant == 0)
			return (free_line(&line, 1));
		else
			return (free_line(&line, 0));
		if (var->nbr_ant)
			return (free_line(&line, 0));
	}
	return (0);
}
