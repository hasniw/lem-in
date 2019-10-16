/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 06:09:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/10/14 18:11:42 by wahasni          ###   ########.fr       */
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
	struct s_links	*links;
	struct s_vertex	*next;
}					t_vertex;

typedef struct		s_links
{
	t_vertex		*vertex;
	struct s_links	*next;
}					t_links;


typedef struct		s_queue
{
	int				*p;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_bfs
{
	t_queue			*queue;
	int				*path;
}					t_bfs;

typedef struct 		s_var
{
	size_t			nbr_vertex;
	size_t			nbr_ant;
	t_type			type;
	int				have_start : 2; // t_bool plus interessant
	int				have_end;
	t_bool			linked_start;
	t_bool			linked_end;
	int				pos_vertex_start;
	char			*line;
	char			**matrix_name; // Pour matrice
	int				*matrix; // Pour matrice : y * nbr de ant + x
	int				fd;
	char			*room_start;
	char			*room_end;
	t_vertex		*vertex;
}					t_var;

/*
** PARSING
*/

int					ft_parsing(t_var *var);
int					ft_ants(t_var *var);
int					ft_room(t_var *var);
int					ft_edge(t_var *var, char *line);

/*
** FREE
*/

int					free_line(char **line, int i);
int					free_tab(char **tab, int ret);
void				free_all(t_var *var);
void				free_matrix(t_var *var);

/*
** COMMENT
*/

int					is_comment(char *str, t_var *var);
int					get_comment(t_var *var, char *str);

/*
** LIST-VERTEX
*/

void				ft_list_push_front(t_vertex **begin_list, void *name);
void				ft_list_push_second(t_vertex **begin_list, void *name);
void				ft_list_push_back(t_vertex **begin_list, void *name);
t_vertex			*ft_create_elem(void *name);
int					ft_list_size(t_vertex *begin_list);

/*
** LIST-LINK
*/

void				ft_list_push_back_link(t_links **begin_list, t_vertex *vertex);

/*
** MATRIX
*/

void				ft_matrix(t_var *var);

/*
** PRINT
*/

void				ft_print_room(t_var *var);
void				ft_print_link(t_var *var);


#endif