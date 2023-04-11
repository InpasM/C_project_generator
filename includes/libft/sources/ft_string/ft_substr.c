/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:05:34 by msapin            #+#    #+#             */
/*   Updated: 2022/12/30 22:47:17 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_substr() function allocate and return a string of characters
 * from the string s. This new string start at index start with a lenght
 * max of len.
 * 
 * @param char* s 
 * @param int start 
 * @param size_t len 
 * @return The new string created or NULL if unsuccessful allocation. 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	strlen;

	i = -1;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start > strlen)
		return (ft_strdup(""));
	strlen = ft_strlen(s + start);
	if (len > strlen)
		len = strlen;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (++i < len)
		substr[i] = s[start + i];
	substr[i++] = '\0';
	return (substr);
}
