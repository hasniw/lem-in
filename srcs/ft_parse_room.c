/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/26 04:51:22 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int		ft_room(var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &args->line)) != 1)
	{
		if (is_room(var, line) || is_comment(line))
		{
			if (check_comment(line))
				ft_strdel(&line);
			else if (ft_check_room(line))
				ft_strdel(&line);
			else
				ft_assign_room(var, line);
		}
	}
	return (0);
}