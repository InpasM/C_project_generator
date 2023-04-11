/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:27:06 by msapin            #+#    #+#             */
/*   Updated: 2023/01/03 16:38:17 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	write_pointer(size_t ptr)
{
	char	*return_ptr;
	int		ptr_len;
	int		i;

	if (!ptr)
		return (write (1, "0x0", 3));
	ptr_len = conv_base_len(ptr, 16);
	return_ptr = malloc(sizeof(char) * (ptr_len + 4));
	if (!return_ptr)
		return (free(return_ptr), -1);
	return_ptr[0] = '0';
	return_ptr[1] = 'x';
	i = 0;
	while (ptr_len + 1 - i > 1)
	{
		return_ptr[ptr_len + 1 - i] = BASE_HEX_LOW[ptr % 16];
		ptr /= 16;
		i++;
	}
	return_ptr[ptr_len + 3] = '\0';
	return (write (1, return_ptr, ptr_len + 2), free(return_ptr), ptr_len + 2);
}

int	write_dec_int(int dec_int)
{
	int		len_int;
	char	*tmp_conv;

	len_int = ft_intlen(dec_int);
	tmp_conv = malloc(sizeof(char) * (len_int + 1));
	if (!tmp_conv)
		return (-1);
	cpint(tmp_conv, dec_int, len_int);
	tmp_conv[len_int] = '\0';
	return (write (1, tmp_conv, len_int), free(tmp_conv), len_int);
}

int	write_base(unsigned int nbr, char *base, int base_len)
{
	char	*str_conv;
	int		len_conv;
	int		i;

	len_conv = conv_base_len(nbr, base_len);
	str_conv = malloc(sizeof(char) * (len_conv + 1));
	if (!str_conv)
		return (-1);
	i = 0;
	while (len_conv - i > 0)
	{
		str_conv[len_conv - 1 - i] = base[nbr % base_len];
		nbr /= base_len;
		i++;
	}
	str_conv[len_conv] = '\0';
	return (write (1, str_conv, len_conv), free(str_conv), len_conv);
}
