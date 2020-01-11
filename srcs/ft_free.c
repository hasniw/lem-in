/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 03:16:46 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/11 00:53:13 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_matrix(t_var *var)
{
	int	i;

	i = 0;
	while (var->matrix_name[i])
		ft_strdel(&var->matrix_name[i++]);
	free(var->matrix_name);
	free(var->matrix); 

}

int		free_var(t_var *var, int i)
{
	free(var);
	return (i);
}

int		free_room(t_var *var, int i)
{
	t_vertex *tmp;
	t_vertex *next;

	tmp = (t_vertex *)var->vertex;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->name);
		free(tmp->links);
		free(tmp);
		tmp = tmp->next;
	}
	free(var);
	free(var->room_end);
	free(var->room_start);
	return (i);
}

int		free_all(t_var *var, int i)
{
	t_vertex	*current;
	t_vertex	*next;
	t_links		*current_links;
	t_links		*current_links_next;

	current = var->vertex;
	while (current)
	{
	    next = current->next;
		current_links = current->links;
		while (current_links)
		{
			current_links_next = current_links->next;
			free(current_links);
			current_links = current_links_next;
		}
		free(current->name);
		free(current);
	    current = next;
	}
	var->vertex = (t_vertex *)0;
	free(var->room_end);
	free(var->room_start);
	free_matrix(var);
	free(var);
	var = (t_var *)0;
	return (i);
}

int		free_tab(char **tab, int ret)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (ret);
}

int		free_line(char **line, int i)
{
	ft_strdel(line);
	return (i);
}
