/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:59 by msapin            #+#    #+#             */
/*   Updated: 2022/12/30 22:35:01 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The  ft_bzero() function erases the data in the n bytes of the 
 * memory starting at the location pointed to by s, by writing zeros
 * (bytes containing '\0') to that area.
 * 
 * @param void* s 
 * @param size_t n 
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
