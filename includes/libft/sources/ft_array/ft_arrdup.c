/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:05:43 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/02/03 15:02:13 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_arrdup() function allocate and return a duplication of the
 * array of string pointed to by arr.
 * 
 * @param char** arr 
 * @return The new array of string or NULL if unsuccessful allocation 
 */
char	**ft_arrdup(char **arr)
{
	char	**new_arr;
	int		arrlen;
	int		i;

	arrlen = ft_arrlen(arr);
	new_arr = ft_calloc(arrlen + 2, sizeof(char *));
	if (!new_arr)
		return (NULL);
	i = -1;
	while (++i < arrlen)
		new_arr[i] = ft_strdup(arr[i]);
	return (new_arr);
}
