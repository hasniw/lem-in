/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 00:58:23 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_parsing(t_var *var)
{
	int		ret;
	char	*line;

	if (ft_ants(var))
		return (free_var(var, 1));
	if (ft_room(var))
		return (free_room(var, 1));
	if (var->line)
		if (ft_edge(var, var->line))
			return (free_all(var, 1));
	while ((ret = get_next_line(var->fd, &line)) > 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		if (ft_edge(var, line))
			return (free_all(var, 1));
	}
	if (var->linked_start == false || var->linked_end == false)
		return (free_all(var, 1));
	return (0);
}
