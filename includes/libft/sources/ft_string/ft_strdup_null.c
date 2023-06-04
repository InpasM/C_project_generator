/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_null.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:36:35 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/03/09 12:47:04 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strdup_null() function returns a pointer to a new string which 
 * is a duplicate of the string s even if s is null.
 * 
 * @param char* s1 
 * @return On success, returns a pointer to the duplicated string. It
 * returns NULL if insufficient memory available.
 */
char	*ft_strdup_null(const char *s1)
{
	size_t	i;
	size_t	len_s1;
	char	*copy_str;

	i = 0;
	len_s1 = ft_strlen_null(s1);
	copy_str = ft_calloc(len_s1 + 1, sizeof(char));
	if (!copy_str)
		return (0);
	while (i < len_s1)
	{
		copy_str[i] = s1[i];
		i++;
	}
	return (copy_str);
}
