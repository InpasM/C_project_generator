/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:41:50 by msapin            #+#    #+#             */
/*   Updated: 2022/12/10 12:46:59 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_memcmp() function compares the first n bytes (each 
 * interpreted as unsigned char\) of the memory areas s1 and s2.
 * 
 * @param void* s1 
 * @param void* s2 
 * @param size_t n 
 * @return An integer less than, equal to, or greater than zero if the first
 * n bytes of s1 is found, respectively, to be less than, to match, or be
 * greater than the first n bytes of s2.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				return_value;
	unsigned char	*str_1;
	unsigned char	*str_2;

	i = 0;
	return_value = 0;
	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str_1[i] != str_2[i])
		{
			return_value = str_1[i] - str_2[i];
			return (return_value);
		}
		i++;
	}
	return (0);
}
