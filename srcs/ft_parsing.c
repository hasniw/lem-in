/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/07/01 02:59:33 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

void		ft_print_room(t_var *var)
{
	int i = 0;

	while (var->vertex->next)
	{
		ft_printf("ROOM%d : %s\n", i, var->vertex->name);
		i++;
		var->vertex = var->vertex->next;
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