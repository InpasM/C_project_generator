/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:17:11 by msapin            #+#    #+#             */
/*   Updated: 2022/12/10 12:47:10 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strnstr() function locates the first occurrence of the
 * null-terminated string needle in the string haystack, where not more than len
 * characters are searched.
 * 
 * @param char* haystack 
 * @param char* needle 
 * @param size_t len 
 * @return If needle is an empty string, haystack is returned; if needle
 * occurs nowhere in haystack, NULL is returned; otherwise a pointer to the
 * first character of the first occurrence of needle is returned. 
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!haystack || !needle) && len == 0)
		return (NULL);
	if (needle[i] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return (&((char *)haystack)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
