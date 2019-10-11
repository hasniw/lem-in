/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/11 17:19:59 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		ft_print_link(t_var *var)
{
	ft_printf("{yellow}ALL LINK{reset}\n");
	t_vertex *tmp = (t_vertex *)var->vertex;
	t_links	*tmp_links;
	
	// (void)tmp;
	// (void)tmp_links;
	// (void)i;
	int i = 1;
	while (tmp)
	{
		ft_printf("{blue}ROOM OF WHO IS LINKED : %s{reset}\n", tmp->name);
		tmp_links = tmp->links;
		while (tmp_links)
		{
			if (!tmp->links->vertex)
				return ;
			ft_printf("{black}ROOM[%d] : %s{reset}\n", i, tmp_links->vertex->name);
			tmp_links = tmp_links->next;
			i++;
		}
		tmp = tmp->next;
		i = 1;
	}
}

void		ft_print_room(t_var *var)
{
	int i = 1;
	t_vertex *tmp = var->vertex;

	ft_printf("{yellow}ALL ROOM{reset}\n");
	while (tmp)
	{
		ft_printf("ROOM %d : %s\n", i, tmp->name);
		i++;
		tmp = tmp->next;
	}
}

int			ft_parsing(t_var *var)
{
	int		ret;
	char	*line;

	if (ft_ants(var))
		return (1);
	if (ft_room(var))
		return (1);
	if (var->line)
		if (ft_edge(var, var->line))
			return (1);
	while ((ret = get_next_line(var->fd, &line)) > 0)
		if (ft_edge(var, line))
			return (1);
	if (var->linked_start == false || var->linked_end == false)
		return (1);
	return (0);
}
