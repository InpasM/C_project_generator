/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:14:13 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/06/27 13:15:05 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_freejoin() function allocate and return a new string, result
 * of s1 and s2 concatenation. Free s1.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_freejoin(char *s1, const char *s2)
{
	char	*tmp_join;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	tmp_join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp_join)
		return (free(tmp_join), tmp_join = NULL, NULL);
	while (s1[j])
		tmp_join[i++] = s1[j++];
	j = 0;
	while (s2[j])
		tmp_join[i++] = s2[j++];
	tmp_join[i] = '\0';
	return (free(s1), tmp_join);
}
