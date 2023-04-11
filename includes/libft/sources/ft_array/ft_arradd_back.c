/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:02:54 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/02/03 15:02:03 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_arradd_back() function allocate and return a new array of
 * string, result of the add of the string elem at the end of the array 
 * pointed to by arr.
 * 
 * @param char** arr 
 * @param char* elem 
 * @return The new array of string or NULL if unsuccessful allocation 
 */
char	**ft_arradd_back(char **arr, char *elem)
{
	char	**new_arr;
	int		arrlen;
	int		i;

	arrlen = ft_arrlen(arr);
	new_arr = ft_calloc(arrlen + 2, sizeof(char *));
	if (!new_arr)
		return (NULL);
	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			new_arr[i] = arr[i];
			i++;
		}
	}
	new_arr[arrlen] = elem;
	return (new_arr);
}
