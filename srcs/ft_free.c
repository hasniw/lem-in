/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 03:16:46 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/15 17:30:35 by wahasni          ###   ########.fr       */
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

void	free_start_end(t_var *var)
{
	t_vertex	*tmp_vertex;
	t_links		*tmp_link;

	tmp_vertex = (t_vertex *)var->vertex;
	tmp_link = (t_links *)tmp_vertex->links;
	free(var->room_start->links);
	free(var->room_end->links);
	free(var->room_start->name);
	free(var->room_end->name);
	free(var->room_start);
	free(var->room_end);
}

void	free_all(t_var *var)
{
	t_vertex	*current;
	t_vertex	*next;
	t_links		*current_links;
	t_links		*current_links_next;

	current = var->vertex;
	ft_printf("{red}MASSUD : %s\n{reset}\n", var->vertex->name);
	while (current)
	{
	        next = current->next;
			current_links = current->links;
			printf("NAME : %s\n", current->name);
			while (current_links)
			{
				current_links_next = current_links->next;
				printf("msandana BEFORE\n");
				// free(current_links->vertex->name);
				free(current_links);
				printf("msandana AFTER\n");
				current_links = current_links_next;
			}
			printf("RAJ1\n");
			// printf("RAJ3\n");
			free(current->name);
			free(current);
			// printf("RAJ4\n");
	        current = next;
			// printf("RAJ5\n");
	}
	var->vertex = (t_vertex *)0;
	// printf("POULOIFDFS : %s\n", var->vertex->name);
	printf("RAJ\n");
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
