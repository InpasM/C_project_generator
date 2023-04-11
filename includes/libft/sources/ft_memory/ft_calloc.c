/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:00:26 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:36:59 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_calloc() function allocates memory for an array of count
 * elements of size bytes each and returns a pointer to the allocated memory.
 * 
 * @param size_t count 
 * @param size_t size 
 * @return A pointer to the allocated memory or NULL.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	if (size > 0 && count > SIZE_MAX / size)
		return (NULL);
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, count * size);
	return (memory);
}
