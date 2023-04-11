/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:29:14 by msapin            #+#    #+#             */
/*   Updated: 2022/12/30 22:19:16 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_toupper() function converts a lower-case letter to the 
 * corresponding upper-case letter.  The argument must be representable as 
 * an unsigned char or the value of EOF.
 * 
 * @param int c
 * @return If the argument is a lower-case letter, the toupper() function 
 * returns the corresponding upper-case letter if there is one; otherwise, 
 * the argument is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
