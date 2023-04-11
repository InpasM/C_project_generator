/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:26:51 by msapin            #+#    #+#             */
/*   Updated: 2023/01/03 16:38:31 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	write_char(int arg)
{
	return (write (1, &arg, 1));
}

int	write_string(char *str)
{
	if (!str)
		return (write (1, "(null)", 6));
	return (write (1, str, ft_strlen(str)));
}

int	conv_base_len(size_t n, int len_base)
{
	int	conv_len;

	conv_len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / len_base;
		conv_len++;
	}
	return (conv_len);
}

void	cpint(char	*char_int, int n, size_t len)
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
