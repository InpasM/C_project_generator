/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:56:24 by msapin            #+#    #+#             */
/*   Updated: 2022/12/15 15:33:58 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// /**
//  * @brief The ft_strjoin() function allocate and return a new string, result
//  * of s1 and s2 concatenation.
//  * 
//  * @param char* s1 
//  * @param char* s2 
//  * @return The new string or NULL if unsuccessful allocation. 
//  */
char	*ft_strjoin(char const *s1, char const *s2)
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
	return (tmp_join);
}
