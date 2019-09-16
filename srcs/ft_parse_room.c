/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 18:40:31 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/14 01:55:38 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

static int	ft_room_exist(t_var *var)
{
	if (!var->vertex->name)
		return (1);
	// Check si room start et end existant
	return (0);
}

static void	ft_assign_room(t_var *var, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	ft_printf("TAB[0] : %s\n", tab[0]);
	if (var->type == other)
		ft_list_push_front(&var->vertex, (void *)tab[0]);
	else if (var->type == start)
	{
		var->pos_vertex_start = 1;
		ft_list_push_front(&var->vertex, (void *)tab[0]);
	}
	else if (var->type == end)
		ft_list_push_back(&var->vertex, (void *)tab[0]);
	if (var->pos_vertex_start > 0 && var->type != start)
		var->pos_vertex_start++;
	var->type = other;
	var->nbr_vertex++;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	ft_check_room(t_var *var, char *str)
{
	char	**tab;

	tab = ft_strsplit(str, ' ');
	if (is_number(tab[1]) || is_number(tab[2])
		|| tab[0][0] == 'L')
		return (free_tab(tab, 1));
	while (var->vertex->next)
	{
		if (ft_strcmp(var->vertex->name, tab[0]))
			return (free_tab(tab, 1));
		var->vertex = var->vertex->next;
	}
	return (0);
}

int			ft_room(t_var *var)
{
	int		ret;
	char	*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		ft_printf("{black}ROOM LINE : %s{reset}\n", line);
		if (ft_count_word(line, ' ') == 2 || is_comment(line) != 1)
		{
			if (get_comment(var, line) != 1)
				ft_strdel(&line);
			else if (!ft_check_room(var, line))
				free_line(&line, 1);
			else
				ft_assign_room(var, line);
		}
		else if (ft_room_exist(var))
			return (free_line(&line, 1));
		else
		{
			var->line = ft_strdup(line);
			return (free_line(&line, 0)); // LINE A GERER DANS ft_parse_links
		}
		ft_printf("{red}<---ROOM LINE SUIVANTE--->{reset}\n");
	}
	return (0);
}


//
void    fill_string(char **s, int x, int y, int size)
{
        (*s)[y * size + x] = '1';
        (*s)[x * size + y] = '1';
}

void    get_coordinates(t_edges *edge, char **split, int *x, int *y)
{
        int size;

        size = split_count(split);
        while (*x < size)
        {
                if (!ft_strcmp(split[*x], edge->from)
                                || !ft_strcmp(split[*x], edge->to))
                {
                        (*y)++;
                        break ;
                }
                (*y)++;
                (*x)++;
        }
        while (*y < size)
        {
                if (!ft_strcmp(split[*y], edge->from)
                                || !ft_strcmp(split[*y], edge->to))
                        break ;
                (*y)++;
        }
}

int             assign(t_edges *edge, t_vertices *vertice, char **s, int size)
{
        t_edges *tmp;
        int             x;
        int             y;
        char    **split;

        split = NULL;
        if (!(split = split_vertices(vertice)))
                return (0);
        tmp = edge;
        while (tmp)
        {
                x = 0;
                y = 0;
                get_coordinates(tmp, split, &x, &y);
                fill_string(s, x, y, size);
                tmp = tmp->next;
        }
        return (free_split(split, 1));
}

char    *stringify(t_data *data)
{
        char    *s;
        size_t  size;

        size = 0;
        size = vertices_len(data->vertices);
        if (!(s = ft_strnew(sizeof(char) * size * size)))
                return (NULL);
        ft_memset(s, '0', size * size);
        if (!assign(data->edges, data->vertices, &s, size))
                return (NULL);
        return (s);
}