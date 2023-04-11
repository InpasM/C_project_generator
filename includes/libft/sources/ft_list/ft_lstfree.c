/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:06:22 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/02/08 16:47:56 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*next_lst;

	while ((*lst))
	{
		next_lst = (*lst)->next;
		free((*lst));
		(*lst) = next_lst;
	}
}
