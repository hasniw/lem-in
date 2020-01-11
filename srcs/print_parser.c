/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 19:30:34 by hasni             #+#    #+#             */
/*   Updated: 2020/01/11 18:05:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**void		ft_print_link(t_var *var)
**{
**	t_vertex	*tmp;
**	t_links		*tmp_links;
**	int			i;
**
**	i = 1;
**	tmp = (t_vertex *)var->vertex;
**	ft_printf("{yellow}ALL LINK{reset}\n");
**  while (tmp)
**	{
**		ft_printf("{blue}ROOM OF WHO IS LINKED : %s{reset}\n", tmp->name);
**		tmp_links = tmp->links;
**		while (tmp_links)
**		{
**			if (!tmp->links->vertex)
**				return ;
**	ft_printf("{black}ROOM[%d] : %s{reset}\n", i, tmp_links->vertex->name);
**			tmp_links = tmp_links->next;
**			i++;
**		}
**		tmp = tmp->next;
**		i = 1;
**	}
**}
*/

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
