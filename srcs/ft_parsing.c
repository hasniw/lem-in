/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 21:53:34 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/26 04:51:23 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int			ft_parsing(t_var *var)
{
	if (ft_ants(var))
		return (1);
	if (ft_room(var))
		return (1);
	if (ft_edges(var))
		return (1);
	return (0);
}

	// Check commande              ]
	// Check commantaire           ]
	// Check nbr de fourmi         ]
	// Check salles
	// Check tubes
	// ==> C'est une erreur
	// Les salles ne sont pas forcement des chiffres, pas dans l'ordre et pa continu
	// Nom d'une salle ne commence jamais par L ou #
	// Ignorer toutes commande non start et end
	// Si pas assez de donnee afficher ERROR
	// ! Stocker x, y des salles
	// ! Stocker nom des salles
	// ! Stocker depart / arriver
	// Un vertex identique a lui meme ne peux pas avoir de edges
	// Verifier edge start et end
	// 