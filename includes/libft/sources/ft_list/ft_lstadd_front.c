/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:42:38 by mehdisapin        #+#    #+#             */
/*   Updated: 2022/12/13 18:36:31 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_lstadd_front() function add the element new at the start of
 * the list lst.
 * 
 * @param t_list** lst 
 * @param t_list* new 
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		new->content = NULL;
	new->next = (*lst);
	(*lst) = new;
}
