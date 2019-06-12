/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:55:07 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/11 22:26:36 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumber(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			break ;
		i++;
	}
	return (i == ft_strlen(s));
}