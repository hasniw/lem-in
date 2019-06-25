/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 06:09:54 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/25 02:43:45 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/includes/libft.h"

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
	char			**matrix;
}					t_var;

#endif