/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/26 07:31:34 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_check_room(char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	if (is_number(tab[1]) || is_number(tab[2]))
		return (1);
	// CHECK_NAME --> exist et pas L
}

int			ft_room(var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &args->line)) != 1)
	{
		if (ft_count_word(str, ' ') != 2 || is_comment(line))
		{
			if (check_comment(line))
				ft_strdel(&line);
			else if (ft_check_room(line))
				ft_strdel(&line); //ERROR
			else
				ft_assign_room(var, line);
		}
		else if (room_exist)
		{
			// ERROR
			exit (1);
		}
		else if
			return (free_line(line, 1));
	}
	return (0);
}