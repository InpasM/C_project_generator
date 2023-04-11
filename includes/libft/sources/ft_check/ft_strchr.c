/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:45:26 by msapin            #+#    #+#             */
/*   Updated: 2022/12/10 12:47:02 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strchr() function returns a pointer to the first occurrence
 * of the character c in the string s.
 * 
 * @param char* s 
 * @param int c 
 * @return A pointer to the matched character or NULL if the character is not
 * found.
 */
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	char_c;

	i = 0;
	char_c = c;
	if (char_c == '\0')
		return (&((char *)s)[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == char_c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}
