/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:54:04 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/03/22 12:06:13 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_putarr_fd() function write each string of the array on the 
 * given file descriptor followed by a newline.
 * 
 * @param char** arr 
 * @param int fd 
 */
void	ft_putarr_fd(char **arr, int fd)
{
	int	i;

	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		ft_putendl_fd(arr[i], fd);
}
