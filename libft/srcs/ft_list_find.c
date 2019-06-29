/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 17:55:14 by wahasni           #+#    #+#             */
/*   Updated: 2019/06/28 03:24:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	_list  *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return (list_ptr);
		list_ptr = list_ptr->next;
	}
	return (NULL);
}
