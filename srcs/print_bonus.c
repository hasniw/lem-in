/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 02:15:04 by hasni             #+#    #+#             */
/*   Updated: 2020/01/14 02:30:30 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_link(t_var *var)
{
	t_vertex	*tmp;
	t_links		*tmp_links;
	int			i;

	i = 1;
	tmp = (t_vertex *)var->vertex;
	ft_printf("\n{yellow}---------- ALL LINK ----------{reset}\n\n");
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

void			print_matrix(char *s)
{
	int		i;
	int		size;

	size = ft_sqrt(ft_strlen(s));
	i = 0;
	ft_printf("\n{yellow}---------- LEM IN MAP ----------{reset}\n\n");
	ft_printf("       ");
	while (i < size * size)
	{
		if (s[i] == '1')
			ft_printf("{red}1{reset} ");
		else if (s[i] == '2')
			ft_printf("{green}2{reset} ");
		else
			ft_printf("0 ");
		if ((i + 1) % size == 0)
			ft_printf("\n       ");
		i++;
	}
	write(1, "\n", 1);
}
