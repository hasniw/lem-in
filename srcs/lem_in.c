/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 00:55:47 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/16 11:01:47 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_var *var;

    if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
        return (1);
	if (ft_parsing(var))
		return (1);
	ft_printf("PARSING BON\n");
	return (0);
}
