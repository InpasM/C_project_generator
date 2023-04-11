/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:37:05 by msapin            #+#    #+#             */
/*   Updated: 2023/01/03 16:37:20 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	check_format(char c, va_list listptr)
{
	if (c == 'c')
		return (write_char(va_arg(listptr, int)));
	else if (c == 's')
		return (write_string(va_arg(listptr, char *)));
	else if (c == 'p')
		return (write_pointer((unsigned long)va_arg(listptr, void *)));
	else if (c == 'd' || c == 'i')
		return (write_dec_int(va_arg(listptr, int)));
	else if (c == 'u')
		return (write_base(va_arg(listptr, unsigned int), BASE_DEC, 10));
	else if (c == 'x')
		return (write_base(va_arg(listptr, unsigned int), BASE_HEX_LOW, 16));
	else if (c == 'X')
		return (write_base(va_arg(listptr, unsigned int), BASE_HEX_UP, 16));
	else if (c == '%')
		return (write_char('%'));
	return (write (1, &c, 1));
}

static int	generate_str(const char *str, va_list listptr)
{
	int	i;
	int	tmp_len;
	int	len_fullstr;

	i = 0;
	len_fullstr = 0;
	while (str[i])
	{
		tmp_len = 0;
		if (str[i] != '%' && str[i] != '\0')
		{
			write (1, &str[i], 1);
			len_fullstr++;
		}
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			tmp_len = check_format(str[i + 1], listptr);
			if (tmp_len == -1)
				return (-1);
			len_fullstr += tmp_len;
			i++;
		}
		i++;
	}
	return (len_fullstr);
}

int	ft_printf(const char *str, ...)
{
	va_list	listptr;
	int		len_fullstr;

	if (write (1, 0, 0) != 0)
		return (-1);
	len_fullstr = -1;
	va_start(listptr, str);
	len_fullstr = generate_str(str, listptr);
	va_end(listptr);
	return (len_fullstr);
}
