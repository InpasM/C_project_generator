/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:10:40 by mehdisapin        #+#    #+#             */
/*   Updated: 2022/12/13 18:36:50 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_lstsize() function count the number of elements in the list.
 * 
 * @param t_list* lst 
 * @return The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		lstsize;

	lstsize = 0;
	while (lst != NULL)
	{
		lstsize++;
		lst = lst->next;
	}
	return (lstsize);
}
