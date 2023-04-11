/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:25:35 by msapin            #+#    #+#             */
/*   Updated: 2022/12/13 18:35:37 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief The ft_atoi() function converts the initial portion of the
 * string pointed to by str to int.
 * 
 * @param char* str 
 * @return The converted value or 0 on error.
 */
int	ft_atoi(const char *str)
{
	long	i;
	int		sign;
	long	return_int;

	i = 0;
	sign = 1;
	return_int = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		if (return_int != (return_int * 10 + ((str[i] - 48) * sign)) / 10)
			return ((sign + 1) / 2 / -1);
		return_int = return_int * 10 + (str[i] - 48) * sign;
		i++;
	}
	return ((int)(return_int));
}
