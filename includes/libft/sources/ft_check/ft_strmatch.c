/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:38:31 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/03/31 21:58:01 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strmatch() function check if the two strings s1 and s2 are 
 * identical.
 * 
 * @param char* s1 
 * @param char* s2 
 * @return The value returned is one if the two strings s1 and s2 are 
 * identical, and zero if not.
 */
int	ft_strmatch(const char *s1, const char *s2)
{
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	i = -1;
	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 != len_s2)
		return (0);
	while (++i < len_s1)
	{
		if (s1[i] != s2[i])
			return (0);
	}
	return (1);
}
