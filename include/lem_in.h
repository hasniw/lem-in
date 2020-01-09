/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 06:09:54 by wahasni           #+#    #+#             */
/*   Updated: 2020/01/09 19:49:30 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"

# define INITIAL 1
# define WAITING 2
# define VISITED 3
# define LINK 1 << 0
# define TAKEN 1 << 1
# define QUIET 1 << 0
# define COLOR 1 << 1
# define MAP 1 << 2
# define TAKEN 1 << 1

# define RED  "\x1B[31m"
# define RST  "\x1B[0m"

# define bool int

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

typedef struct				s_vertex_second
{
	struct s_vertex_second	*next;
	int						vertex;
}							t_vertex_second;

typedef struct				s_vert
{
	int						u;
	int						v;
}							t_vert;

typedef struct				s_queue
{
	t_vertex_second				*front;
	t_vertex_second				*rear;
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
int					free_all(t_var *var, int i);
void				free_matrix(t_var *var);
int					free_room(t_var *var, int i);
int					free_var(t_var *var, int i);

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

int					ft_matrix(t_var *var);

/*
** PRINT
*/

void				ft_print_room(t_var *var);
void				ft_print_link(t_var *var);

/*
****************************************
***********     FUNCTIONS     **********
****************************************
*/

/*
**  algo functions
*/

int							algo(char **edges, int nb_vertices,
								int max_bfs, int nb_ant);
void						reinit_args(t_args *args);

/*
**  bfs functions
*/

int							get_max_bfs(t_var *var);
bool						bfs(t_args *args);
int							check_available(char *state, int vertex);
void						change_state(char **state, int vertex,
											int new_state);
/*
** queue functions
*/

bool						is_empty(t_queue *queue);
int							dequeue(t_queue *queue);
void						enqueue(t_queue *queue, int vertex);
void						free_queue_vertex(t_queue *queue);

/*
** linked list functions for t_path
*/

int							push_vertex(t_path **head, int vertex);
t_path						*init_path(int vertex);

/*
** linked list functions for t_flow
*/

t_flow						*new_flow(t_path *head, int size);
int							add_flow(t_flow **head, t_flow *new);

/*
**  free functions
*/

void						free_queue(t_queue *queue);
void						free_path(t_path *head);
void						free_flow(t_flow *flow);
void						free_args(t_args *args);

/*
**	path functions
*/

bool						find_path(t_args *args);
bool						get_path(t_args *args);

/*
**	update functions
*/

void						update_from_path(t_args *args, char *map, int u);

/*
**	yield functions
*/

bool						check_path_yield(t_args *args, int size);

/*
** check path functions
*/

bool						check_used_link(t_args *args, int vertex, int i);
bool						check_link(t_args *args, int vertex, int i);
bool						check_end(t_args *args, int vertex, int i);
bool						check_taken(t_args *args, int vertex);
bool						check_connection(t_args *args, int vertex, int to);
int							get_previous(int vertex, t_args *args);

int							output(char *map, t_var *data); // t_data to t_var
size_t						vertices_len(t_vertex *head); // t_vertice to t_vertex
int							free_split(char **split, int ret);

/*
** path functions
*/

int							number_of_path(char *map, int size);
int							get_one_path(int start,
								t_flow **flow, char *map, int size);

/*
** ants functions
*/

int							get_ants_per_path(t_flow *flow, int nb_ants,
												int nb_path);

/*
** print functions
*/

void						print_output(char **vertices,
										t_flow *flow, int color);
void						print_map(char *s);
void						done_single_path(int ants, char *sink);


/*
** free functions
*/

void						free_flow(t_flow *flow);

#endif