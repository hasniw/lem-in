/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:34:20 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/27 04:29:45 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int	is_comment(char *str)
{
	if (str[0] != '#')
		return (1);
	if (str[1] == '#')
		if (!ft_strcmp("start", str + 2)
		|| !ft_strcmp("finish", str + 2))
			return (2);
	return (0);
}