/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:46:32 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:37:16 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strdup() function returns a pointer to a new string which 
 * is a duplicate of the string s.
 * 
 * @param char* s1 
 * @return On success, returns a pointer to the duplicated string. It
 * returns NULL if insufficient memory available.
 */
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len_s1;
	char	*copy_str;

	i = 0;
	len_s1 = ft_strlen(s1) + 1;
	copy_str = malloc(sizeof(char) * len_s1);
	if (!copy_str)
		return (0);
	while (i < len_s1)
	{
		copy_str[i] = s1[i];
		i++;
	}
	return (copy_str);
}
