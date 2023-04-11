/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:18:13 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:36:21 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_putnbr_fd() function write the integer n on the given file
 * descriptor.
 * 
 * @param int n 
 * @param int fd 
 */
void	ft_putnbr_fd(int n, int fd)
{
	char			temp_char;
	unsigned int	unsign_n;

	if (n < 0)
	{
		write (fd, "-", 1);
		unsign_n = -(unsigned int)n;
	}
	else
		unsign_n = (unsigned int)n;
	if (unsign_n <= 9)
	{
		temp_char = unsign_n + 48;
		write (fd, &temp_char, 1);
	}
	else
	{
		ft_putnbr_fd(unsign_n / 10, fd);
		ft_putnbr_fd(unsign_n % 10, fd);
	}
}
