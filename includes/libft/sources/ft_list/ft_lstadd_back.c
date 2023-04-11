/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:33:02 by mehdisapin        #+#    #+#             */
/*   Updated: 2022/12/13 18:36:28 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_lstadd_back() function add the element new at the end of the
 * list lst.
 * 
 * @param t_list** lst 
 * @param t_list* new 
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstadd_back;

	if (!(*lst))
		(*lst) = new;
	else
	{
		lstadd_back = (*lst);
		while (lstadd_back->next != NULL)
			lstadd_back = lstadd_back->next;
		lstadd_back->next = new;
	}
}
