/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:41:46 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:35:39 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	intlen(int n)
{
	size_t		len_int;
	long int	long_n;

	long_n = n;
	len_int = 0;
	if (long_n == 0)
		return (1);
	if (long_n < 0)
	{
		len_int++;
		long_n *= -1;
	}
	while (long_n > 0)
	{
		len_int++;
		long_n /= 10;
	}
	return (len_int);
}

static void	cpyint(char	*char_int, int n, size_t len)
{
	unsigned int	unsign_n;
	size_t			sign;

	if (n == 0)
		char_int[0] = '0';
	if (n < 0)
	{
		char_int[0] = '-';
		unsign_n = -(unsigned int)n;
		sign = 1;
	}
	else
	{
		unsign_n = (unsigned int)n;
		sign = 0;
	}
	while (len > sign)
	{
		char_int[len - 1] = (unsign_n % 10) + 48;
		unsign_n = unsign_n / 10;
		len--;
	}
}

/**
 * @brief The ft_itoa() function allocate and return a string of characters
 * corresponding to the integer received into argument.
 * 
 * @param int n 
 * @return The string of char corresponding to the integer or NULL if 
 * unsuccessful allocation.
 */
char	*ft_itoa(int n)
{
	char	*char_int;

	char_int = (char *)malloc(sizeof(char) * (intlen(n) + 1));
	if (!char_int)
		return (0);
	cpyint(char_int, n, intlen(n));
	char_int[intlen(n)] = '\0';
	return (char_int);
}
