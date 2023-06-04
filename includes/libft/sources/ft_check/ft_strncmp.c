/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:12:35 by msapin            #+#    #+#             */
/*   Updated: 2023/03/20 15:38:47 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strncmp() function compares the two strings s1 and s2.
 * 
 * @param char* s1 
 * @param char* s2 
 * @param size_t n 
 * @return An integer less than, equal to, or greater than zero if s1 (or
 * the first n bytes thereof) is found, respectively, to be less than, to
 * match, or be greater than s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				return_value;
	unsigned char	*str_1;
	unsigned char	*str_2;

	i = 0;
	return_value = 0;
	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	while ((str_1[i] != '\0' || str_2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return_value = str_1[i] - str_2[i];
			return (return_value);
		}
		i++;
	}
	return (0);
}
