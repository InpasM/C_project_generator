/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:21:27 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:37:27 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strlcat() function appends the NUL-terminated string src to
 * the end of dst. It will append at most size - strlen(dst) - 1 bytes,
 * NUL-terminating the result.
 * 
 * @param char* dst 
 * @param char* src 
 * @param size_t dstsize 
 * @return The total length of the string they tried to create. For strlcat()
 * that means the initial length of dst plus the length of src. 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	len_dst;
	size_t	temp_len_dst;

	len = 0;
	if ((!dst || !src) && dstsize == 0)
		return (0);
	len_dst = ft_strlen(dst);
	temp_len_dst = ft_strlen(dst);
	if (!(dstsize == 0 || len_dst > dstsize))
	{
		while (src[len] != '\0' && temp_len_dst < dstsize - 1)
		{
			dst[len_dst + len] = src[len];
			len++;
			temp_len_dst++;
		}
		dst[len_dst + len] = '\0';
		return (len_dst + ft_strlen(src));
	}
	else
		return (dstsize + ft_strlen(src));
}
