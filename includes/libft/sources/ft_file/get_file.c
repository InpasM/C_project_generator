/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:48:56 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/02/02 23:41:41 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*gf_strjoin(char *next_line, char const *buffer)
{
	char	*tmp_join;
	size_t	i;
	size_t	j;
	size_t	len_strjoin;

	if (!next_line || !buffer)
		return (NULL);
	i = 0;
	j = 0;
	len_strjoin = ft_strlen(next_line) + ft_strlen(buffer);
	tmp_join = malloc(sizeof(char) * (len_strjoin + 1));
	if (!tmp_join)
		return (free(next_line), next_line = NULL, NULL);
	while (next_line[j])
		tmp_join[i++] = next_line[j++];
	j = 0;
	while (buffer[j])
		tmp_join[i++] = buffer[j++];
	tmp_join[i] = '\0';
	return (free(next_line), next_line = NULL, tmp_join);
}

/**
 * @brief The get_file() function read and return a string of the content of
 * the file pass as arguments by fd.
 * 
 * @param int fd 
 * @return The new string of the file or NULL if unsuccessful allocation
 */
char	*get_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*str_file;
	int		nbytes;

	str_file = NULL;
	nbytes = 1;
	while (nbytes != 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
			return (NULL);
		buffer[nbytes] = '\0';
		if (!str_file)
			str_file = ft_strdup(buffer);
		else
			str_file = gf_strjoin(str_file, buffer);
	}
	return (str_file);
}
