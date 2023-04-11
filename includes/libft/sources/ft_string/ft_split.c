/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:28:49 by msapin            #+#    #+#             */
/*   Updated: 2022/12/30 22:43:19 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	nbr_char(const char *s, char c)
{
	int		i;
	int		nbr_c;

	i = 0;
	nbr_c = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			nbr_c++;
		i++;
	}
	return (nbr_c);
}

static int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

/**
 * @brief The ft_split() function allocate and return an array of strings
 * obtain by splitting string s with char c as delimiter. The array will
 * be NUL-terminated.
 * 
 * @param char* s 
 * @param char c 
 * @return The array of split strings
 */
char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbr_c;
	int		i;
	int		j;

	i = 0;
	j = -1;
	nbr_c = nbr_char(s, c);
	tab = malloc(sizeof(char *) * (nbr_c + 1));
	if (!tab)
		return (NULL);
	while (++j < nbr_c)
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_substr(s, i, size_word(s, c, i));
		if (!tab[j])
			return (free_tab(tab), NULL);
		i += size_word(s, c, i);
	}
	tab[j] = NULL;
	return (tab);
}
