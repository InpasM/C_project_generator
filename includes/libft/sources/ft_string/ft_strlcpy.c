/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:55:36 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:37:30 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strlcpy() function copies up to size - 1 characters from the
 * NUL-terminated string src to dst, NUL-terminating the result.
 * 
 * @param char* dst 
 * @param char* src 
 * @param size_t dstsize 
 * @return The ft_strlcpy() functions return the total length of the string
 * they tried to create. For strlcpy() that means the length of src. 
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize != 0)
	{
		while (src[len] != '\0' && len < dstsize - 1)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	while (src[len] != '\0')
		len++;
	return (len);
}
