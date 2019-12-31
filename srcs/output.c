/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:28:25 by jdescler          #+#    #+#             */
/*   Updated: 2019/12/31 19:25:43 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

size_t		vertices_len(t_vertex *head)
{
	size_t		i;
	t_vertex	*tmp;

	i = 0;
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char		**split_vertices(t_vertex *head)
{
	char		**split;
	t_vertex	*tmp;
	int			i;

	i = 0;
	tmp = head;
	if (!(split = (char**)ft_memalloc(sizeof(char*)
					* (vertices_len(head) + 1))))
		return (NULL);
	while (tmp)
	{
		if (!(split[i] = ft_strdup(tmp->name)))
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (split);
}

static void	parse_map(char *map, int size, t_flow **flow)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < size)
	{
		if ((map)[i] & TAKEN)
			get_one_path(i, flow, map, size);
		i++;
	}
}

int			output(char *map, t_var *var)
{
	char	**split;
	int		size;
	t_flow	*flow;
	int		nb_path;

	flow = NULL;
	split = NULL;
	size = vertices_len(var->vertex);
	nb_path = number_of_path(map, size);
	if (!(split = split_vertices(var->vertex)))
		return (0);
	parse_map(map, size, &flow);
	if (!flow)
		return (free_split(split, 0));
	if (get_ants_per_path(flow, var->nbr_ant, nb_path) == -1)
		return (free_split(split, 0));
	print_output(split, flow, var->flag & COLOR);
	free_flow(flow);
	return (free_split(split, 1));
}
