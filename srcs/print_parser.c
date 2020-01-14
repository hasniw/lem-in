/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:30:34 by hasni             #+#    #+#             */
/*   Updated: 2020/01/14 02:34:49 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_room(t_var *var)
{
	int			i;
	t_vertex	*tmp;

	i = 1;
	tmp = var->vertex;
	ft_printf("{yellow}ALL ROOM{reset}\n");
	while (tmp)
	{
		ft_printf("ROOM %d : %s\n", i, tmp->name);
		i++;
		tmp = tmp->next;
	}
}

void	ft_print_matrix(t_var *var)
{
	size_t	j;

	j = 0;
	while (j < var->nbr_vertex * var->nbr_vertex)
	{
		if (var->matrix[j] == '1')
			ft_printf("{blue}[%d]{reset}", (int)j++);
		else
			ft_printf("{blue}[%c]{reset}", var->matrix[j++]);
	}
	ft_printf("\n");
}
