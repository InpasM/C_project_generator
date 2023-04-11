/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:46:40 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:37:10 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_memset() function fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 * 
 * @param void* b 
 * @param int c 
 * @param size_t len 
 * @return The ft_memset() function returns a pointer to the memory area s.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	char_c;

	i = 0;
	char_c = c;
	while (i < len)
	{
		((char *)b)[i] = char_c;
		i++;
	}
	return (b);
}
