/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 06:09:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/06 01:15:39 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/libft.h"

# define MAX 4096

typedef enum		e_bool
{
    false,
    true
}					t_bool;

typedef enum		e_type
{
	other,
	start,
	end
}					t_type;

typedef struct		s_vertex
{
	char			*name;
	struct s_vertex	*next;
}					t_vertex;

typedef struct		s_queue
{
	int				*p;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_bfs
{
	t_queue			*queue;
	int				*output;
}					t_bfs;

typedef struct 		s_var
{
	size_t			nbr_vertex;
	size_t			nbr_ant;
	t_type			type;
	int				pos_vertex_start;
	char			*line;
	char			buffer[MAX];
	char			**matrix;
	t_vertex		*vertex;
}					t_var;

/*
** PARSING
*/

int					ft_parsing(t_var *var);
int					ft_ants(t_var *var);
int					ft_room(t_var *var);

/*
** FREE
*/

int					free_line(char **line, int i);
int					free_tab(char **tab, int ret);

/*
** COMMENT
*/

int					is_comment(char *str);
int					get_comment(t_var *var, char *str);

/*
** UTILS-LIST-VERTEX
*/

void				ft_list_push_front(t_vertex **begin_list, void *name);
void				ft_list_push_back(t_vertex **begin_list, void *name);
t_vertex			*ft_create_elem(void *name);
int					ft_list_size(t_vertex *begin_list);

/*
** PRINT
*/

void				ft_print_room(t_var *var);


#endif