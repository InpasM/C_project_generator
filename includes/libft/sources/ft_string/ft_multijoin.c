/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multijoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:14:17 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/06/27 13:37:16 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_multijoin() function allocate and return a new string, result
 * of all string concatenation.
 * 
 * @param char* str 
 * @param ... 
 * @return The new string or NULL if unsuccessful allocation. 
 */
char	*ft_multijoin(char *str, ...)
{
	va_list	listptr;
	char	*multijoin;
	char	*tmp_arg;

	multijoin = ft_strdup_null(str);
	va_start(listptr, str);
	while (1)
	{
		tmp_arg = va_arg(listptr, char *);
		if (!tmp_arg)
			break ;
		multijoin = ft_freejoin(multijoin, tmp_arg);
	}
	va_end(listptr);
	return (multijoin);
}
