/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 06:09:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/12/30 05:31:02 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/libft.h"

# define MAX 4096
# define QUIET 1 << 0
# define COLOR 1 << 1
# define MAP 1 << 2
# define LINK 1 << 0

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

typedef struct				s_path
{
	int						vertex;
	int						ant;
	struct s_path			*next;
}							t_path;

typedef struct				s_flow
{
	t_path					*path;
	int						size;
	int						ants;
	struct s_flow			*next;
}							t_flow;

// typedef struct				s_vertex
// {
// 	struct s_vertex			*next;
// 	int						vertex;
// }							t_vertex;

typedef struct				s_vert
{
	int						u;
	int						v;
}							t_vert;

typedef struct				s_queue
{
	t_vertex				*front;
	t_vertex				*rear;
	int						count;
}							t_queue;

typedef struct				s_args
{
	t_queue					*queue;
	char					*edges;
	char					*state;
	int						*taken;
	int						nb_vertice;
	int						max_bfs;
	int						nb_ant;
	int						step_number;
	char					*saved_map;
	int						*went_back;
	int						*path;
}							t_args;

typedef struct 		s_var
{
	int				flag;
	int				i_start;
	int				i_end;
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
	char			*matrix; // Pour matrice : y * nbr de ant + x
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