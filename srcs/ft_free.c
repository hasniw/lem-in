/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 03:16:46 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/17 19:22:42 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void	free_matrix(t_var *var)
{
	int	i;

	i = 0;
	while (var->matrix_name[i])
		ft_strdel(&var->matrix_name[i++]);
	free(var->matrix_name);
	free(var->matrix); 

}

// void	free_start_end(t_var *var)
// {
// 	t_vertex	*current;
// 	t_links		*current_links;
// 	t_links		*current_links_next;

// 	current = var->room_start;
// 	current_links = current->links;
// 	while (current_links)
// 	{
// 		current_links_next = current_links->next;
// 		free(current_links);
// 		current_links = current_links_next;
// 	}
// 	free(current->name);
// 	free(current);
// 	current = var->room_end;
// 	current_links = current->links;
// 	while (current_links)
// 	{
// 		current_links_next = current_links->next;
// 		free(current_links);
// 		current_links = current_links_next;
// 	}
// 	free(current->name);
// 	free(current);
// }

void	free_all(t_var *var)
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
		ft_strdel(&current->name);
		free(current);
	    current = next;
	}
	var->vertex = (t_vertex *)0;
	free(var->room_end);
	free(var->room_start);
	free_matrix(var);
	free(var);
	var = (t_var *)0;
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
