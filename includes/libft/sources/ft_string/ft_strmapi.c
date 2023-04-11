/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:51:19 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:37:33 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_strmapi() function apply the function f to each characters
 * of the string given by argument and create a new string of characters.
 * 
 * @param char* s 
 * @param *f 
 * @return The string created with the result of the function f on each
 * characters.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmapi;
	int		i;

	if (!s || !f)
		return (NULL);
	strmapi = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!strmapi)
		return (NULL);
	i = 0;
	while (s[i])
	{
		strmapi[i] = f(i, s[i]);
		i++;
	}
	strmapi[i] = '\0';
	return (strmapi);
}
