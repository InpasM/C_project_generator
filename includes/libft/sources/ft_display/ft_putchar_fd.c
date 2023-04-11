/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:18:01 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:36:16 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_putchar_fd() function write char c on the given file
 * descriptor.
 * 
 * @param char c 
 * @param int fd 
 */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
