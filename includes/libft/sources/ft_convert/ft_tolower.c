/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:41:19 by msapin            #+#    #+#             */
/*   Updated: 2022/12/30 22:19:04 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_tolower() function converts an upper-case letter to the 
 * corresponding lower-case letter.  The argument must be representable as 
 * an unsigned char or the value of EOF.
 * 
 * @param int c
 * @return If the argument is an upper-case letter, the tolower() function 
 * returns the corresponding lower-case letter if there is one; otherwise, 
 * the argument is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
