/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:50:00 by msapin            #+#    #+#             */
/*   Updated: 2023/01/04 14:43:50 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*gnl_strjoin(char *next_line, char const *buffer)
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

static char	*read_next_line(int fd, char *next_line)
{
	char	buffer[BUFFER_SIZE + 1];
	int		byte_count;

	if (!next_line)
		next_line = ft_calloc(1, sizeof(char));
	if (!next_line)
		return (NULL);
	byte_count = 1;
	while (byte_count != 0)
	{
		byte_count = read(fd, buffer, BUFFER_SIZE);
		if (byte_count == -1)
			return (NULL);
		buffer[byte_count] = 0;
		next_line = gnl_strjoin(next_line, buffer);
		if (!next_line)
			return (NULL);
		if (ft_strrchr(next_line, '\n') != 0)
			byte_count = 0;
	}
	return (next_line);
}

static char	*get_return_line(char *next_line)
{
	char	*line;
	int		i;

	i = 0;
	if (!next_line[i])
		return (NULL);
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (next_line[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (next_line[i] && next_line[i] != '\n')
	{
		line[i] = next_line[i];
		i++;
	}
	if (next_line[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*save_next_line(char *next_line)
{
	char		*new_line;
	size_t		i;
	size_t		j;

	i = 0;
	while (next_line[i] && next_line[i] != '\n')
		i++;
	if (!next_line[i])
		return (free(next_line), next_line = NULL, NULL);
	new_line = ft_calloc(ft_strlen(next_line) - i + 1, sizeof(char));
	if (!new_line)
		return (free(next_line), next_line = NULL, NULL);
	i++;
	j = 0;
	while (next_line[i] != '\0')
		new_line[j++] = next_line[i++];
	return (free(next_line), next_line = NULL, new_line);
}

char	*get_next_line(int fd)
{
	static char	*next_line[OPEN_MAX];
	char		*return_line;
	int			read_byte;

	read_byte = read(fd, 0, 0);
	if (fd < 0 || BUFFER_SIZE <= 0 || read_byte < 0)
		return (free(next_line[fd]), next_line[fd] = NULL, NULL);
	next_line[fd] = read_next_line(fd, next_line[fd]);
	if (!next_line[fd])
		return (free(next_line[fd]), next_line[fd] = NULL, NULL);
	return_line = get_return_line(next_line[fd]);
	if (!return_line)
		return (free(next_line[fd]), next_line[fd] = NULL, NULL);
	next_line[fd] = save_next_line(next_line[fd]);
	return (return_line);
}
