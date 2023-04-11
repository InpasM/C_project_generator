/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:06:20 by mehdisapin        #+#    #+#             */
/*   Updated: 2022/12/13 18:36:44 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_lstmap() function iterate on the list lst and apply the
 * function f on each element. Create a new list with all the results.
 * 
 * @param t_list* lst 
 * @param *f 
 * @param *del 
 * @return The new list or NULL if unsuccessful allocation. 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstmap;
	t_list	*elem;

	if (!f || !del)
		return (NULL);
	lstmap = NULL;
	while (lst != NULL)
	{
		elem = ft_lstnew(f(lst->content));
		if (!elem)
		{
			ft_lstclear(&lstmap, del);
			return (NULL);
		}
		ft_lstadd_back(&lstmap, elem);
		lst = lst->next;
	}
	return (lstmap);
}
