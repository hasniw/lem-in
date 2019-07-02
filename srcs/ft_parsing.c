/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/02 18:44:35 by wahasni          ###   ########.fr       */
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
	// if (ft_edges(var))
	// 	return (1);
	return (0);
}

	// Un vertex identique a lui meme ne peux pas avoir de edges
	// Verifier edge start et end
	// ! =====> CREER LISTE POUR LES EDGES ET VERTEX
	// Gestion buffer pour l'affichage / Maybe liste chainee buffer
	// Tableau de struct pour les vertex et liste chainees dedant pour les link
	// Verifier que apres ##start et ##end y'a bien la room 