/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/09/16 11:02:23 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		ft_print_room(t_var *var)
{
	int i = 1;
	t_vertex *tmp = var->vertex;

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
	{
		ft_printf("ERREUR ENTREE PARSING NBR FOURMI");
		return (1);
	}
	ft_printf("NBR DE FOURMI : %d\n", (int)var->nbr_ant);
	if (ft_room(var))
	{
		ft_printf("{erreur} NBR DE VERTEX : %d\n", (int)var->nbr_vertex);
		ft_print_room(var);
		return (1);
	}
	ft_printf("NBR DE VERTEX : %d\n", (int)var->nbr_vertex);
	ft_print_room(var);
	ft_printf("YOLO : %d\n", var->pos_vertex_start);
	// ft_matrix(var);
	if (var->line)
	{
		if (ft_edges(var, var->line))
		{
			ft_printf("ERREUR FIRST LINE EDGES\n");
			free_line(&var->line, 1);
		}
	}
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_edges(var, line))
		{
			ft_printf("ERREUR EDGES");
			free_line(&line, 1);
		}
	}
	// 	return (1);
	return (0);
}

	// Un vertex identique a lui meme ne peux pas avoir de edges
	// Verifier edge start et end
	// ! =====> CREER LISTE POUR LES EDGES ET VERTEX
	// Gestion buffer pour l'affichage / Maybe liste chainee buffer
	// Tableau de struct pour les vertex et liste chainees dedant pour les link
	// Verifier que apres ##start et ##end y'a bien la room 

int             check_split(char **s)
{
        if (s[1] && ft_strlen(s[1]) >= 10)
        {
                if (ft_strlen(s[1]) > 11 || ft_atoll(s[1]) > INT_MAX
                                || ft_atoll(s[1]) < INT_MIN)
                        return (0);
        }
        if (s[2] && ft_strlen(s[2]) >= 10)
        {
                if (ft_strlen(s[2]) > 11 || ft_atoll(s[2]) > INT_MAX
                                || ft_atoll(s[2]) < INT_MIN)
                        return (0);
        }
        return (s[0][0] != 'L' && ft_isint(s[1])
                        && ft_isint(s[2]));
}

int             split_count(char **split)
{
        int i;

        i = 0;
        while (split[i])
                i++;
        return (i);
}

int             count_spaces(char *s)
{
        int count;

        count = 0;
        while (*s && s)
        {
                if (*s == ' ')
                        count++;
                s++;
        }
        return (count == 2);
}

int             count_dash(char *s)
{
        int count;

        count = 0;
        while (*s && s)
        {
                if (*s == '-')
                        count++;
                s++;
        }
        return (count == 1);
}

int             get_edge(char *s, char ***split, t_vertices *head)
{
        int i;
        char *tmp;

        i = 0;
        while (s[i])
        {
                if (s[i] == '-')
                {
                        if (!(tmp = ft_strndup(s, i)))
                                return (0);
                        if (!(check_vertices_name(head, tmp)))
                        {
                                if (!(*split = ft_memalloc(sizeof(char*) * 3)))
                                        return (0);
                                if (!((*split)[0] = ft_strdup(tmp))
                                        || !((*split)[1] = ft_strdup(s + i + 1)))
                                        return (0);
                                ft_memdel((void**)&tmp);
                                return (2);
                        }
                        ft_memdel((void**)&tmp);
                }
                i++;
        }
        return (0);
}

int             get_vertex(char *s, char ***split, char *info)
{
                if (*info & VERTICES)
                        return (0);
                *split = ft_strsplit(s, ' ');
                if (ft_strchr(*split[0], '-'))
                        *info |= DASH;
                return (1);
}

int             split_arg(t_data *data, char *s, char ***split)
{
        int i;

        i = 0;
        while (s[i] && s[i] != ' ')
                i++;
        if (s[i] == ' ' && count_spaces(s))
        {
                return get_vertex(s, split, &(data->info));
        }
        else if (count_dash(s))
        {
                if (!data->vertices)
                        return (0);
                *split = ft_strsplit(s, '-');
                data->info |= VERTICES;
                return (2);
        }
        else if (data->info & DASH)
                return (get_edge(s, split, data->vertices));
        else
                return (0);
}
