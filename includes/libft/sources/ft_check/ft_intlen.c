/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:58:32 by msapin            #+#    #+#             */
/*   Updated: 2023/01/03 15:03:50 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_intlen(int n)
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
