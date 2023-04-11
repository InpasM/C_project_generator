/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:21:25 by mehdisapin        #+#    #+#             */
/*   Updated: 2022/12/13 18:36:41 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_lstlast() function return the last element of the list.
 * 
 * @param t_list* lst 
 * @return The last element of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lstlast;

	lstlast = lst;
	if (!lstlast)
		return (lstlast);
	while (lstlast->next != NULL)
		lstlast = lstlast->next;
	return (lstlast);
}
