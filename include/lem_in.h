/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 06:09:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/26 07:23:51 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/libft.h"

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

typedef struct		s_queue
{
	int				*p;
	struct s_queue	next; 
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
	int				start;
	int				end;
	char			**matrix;
}					t_var;

/*
** PARSING
*/

/*
** PARSE-ANT
*/

int					ft_ants(t_var *var);

/*
** FREE
*/

int					free_line(char **line, int i);

#endif