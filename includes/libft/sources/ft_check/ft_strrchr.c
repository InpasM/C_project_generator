/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:24:39 by msapin            #+#    #+#             */
/*   Updated: 2022/12/10 12:47:19 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strrchr() function returns a pointer to the last occurrence
 * of the character c in the string s.
 * 
 * @param char* s 
 * @param int c 
 * @return A pointer to the matched character or NULL if the character is not
 * found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	char_c;

	i = ft_strlen(s);
	char_c = c;
	while (i >= 0)
	{
		if (s[i] == char_c)
			return (&((char *)s)[i]);
		i--;
	}
	return (0);
}
