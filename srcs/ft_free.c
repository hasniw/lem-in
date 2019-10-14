/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 03:16:46 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/14 19:05:59 by wahasni          ###   ########.fr       */
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

void	free_all(t_var *var)
{
	t_vertex	*current;
	t_vertex	*next;
	t_links		*current_links;
	t_links		*current_links_next;

	current = var->vertex;
	ft_printf("{red}MASSUD : %s\n{reset}\n", var->vertex->name);
	ft_print_link(var);
	while (current)
	{
	        next = current->next;
			current_links = current->links;
			while (current_links)
			{
				current_links_next = current_links->next;
				current_links_next = current->links->next;
				free(current->links);
				current_links = current_links_next;
			}
			free(current->name);
			free(current->links);
			free(current);
	        current = next;
	}
	var->vertex = (t_vertex *)0;
	free(var->room_start->links);     	// FREE LIST VAR->END/START
	free(var->room_end->links);	      	// FREE LIST VAR->END/START
	free(var->room_start->name);      	// FREE LIST VAR->END/START
	free(var->room_end->name);        	// FREE LIST VAR->END/START
	free(var->room_start);         		// FREE LIST VAR->END/START
	free(var->room_end);          		// FREE LIST VAR->END/START
	free_matrix(var);
	free(var);
	var = (t_var *)0;
}

// void	free_all(t_var *var)
// {
// 	t_vertex	*tmp;
// 	t_vertex	*tmp_next;
// 	t_links		*tmp_links;
// 	t_links		*tmp_links_next;

// 	tmp = (t_vertex *)var->vertex;
// 	while (tmp)
// 	{
// 		tmp_links = tmp->links;
// 		while (tmp_links)
// 		{
// 			if (!tmp->links->vertex)
// 				return ;
// 			tmp_links_next = tmp->links->next;
// 			free(tmp->links);
// 			tmp_links = tmp_links_next;
// 		}
// 		tmp_next = tmp->next;
// 		free(tmp);
// 		tmp = tmp_next;
// 	}
// 	var->vertex->links = (t_links *)0;
// 	var->vertex = (t_vertex *)0;
// 	free(var);
// 	// FREE_ROOM->LINKED (all lien)
// 	// FREE_ROOM
// }

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
