/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:11:10 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:37:35 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	set_in_str(char const *s1, char const *set, int index, int sign)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (s1[index] == set[i])
			return (set_in_str(s1, set, index + (1 * sign), sign));
		i++;
	}
	return (index);
}

static char	*str_extract(char const *s1, int i_start, int i_end)
{
	char	*strtrim;
	size_t	i;

	i = 0;
	strtrim = malloc(sizeof(char) * ((i_end - i_start) + 2));
	if (strtrim)
	{
		while (i_start <= i_end)
		{
			strtrim[i] = s1[i_start];
			i_start++;
			i++;
		}
		strtrim[i] = '\0';
		return (strtrim);
	}
	else
		return (0);
}

/**
 * @brief The ft_strtrim() function allocate and return a copy of the string s1
 * without the characters specified in string set at the start and end of
 * string s1.
 * 
 * @param char* s1 
 * @param char* set 
 * @return The string s1 trim or NULL if unsuccessful allocation. 
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_start;
	size_t	i_end;

	if (!s1)
		return (NULL);
	i_start = set_in_str(s1, set, 0, 1);
	if (i_start == ft_strlen(s1))
		return (ft_strdup(""));
	i_end = set_in_str(s1, set, ft_strlen(s1) - 1, -1);
	if ((i_end - i_start) == ft_strlen(s1))
		return ((char *)s1);
	else
		return (str_extract(s1, i_start, i_end));
}
