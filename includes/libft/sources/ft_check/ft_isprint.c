/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:13:28 by msapin            #+#    #+#             */
/*   Updated: 2022/12/30 22:12:09 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_isdigit() function check for any printable character including
 * space.
 * 
 * @param int c 
 * @return The values returned are nonzero if the character c falls into the
 * tested class, and zero if not.
 */
int	ft_isprint(int c)
{
	if (!(c >= ' ' && c <= '~'))
		return (0);
	return (1);
}
