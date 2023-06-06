/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msapin <msapin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:44:36 by msapin            #+#    #+#             */
/*   Updated: 2023/06/06 11:03:43 by msapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/project_gen.h"

char    *line_file(char *file_name, int version)
{
    char    *return_line;
	char	*endline;
	int		i;
	int		j;
	int		strlen;
	int		lenrem;

	return_line = ft_calloc(82, sizeof(char));
	strlen = ft_strlen(file_name);
	lenrem = 51 - strlen;
	i = 0;
	if (version == 0)
	{
		endline = ft_strdup(":+:      :+:    :+:    #\n");
		return_line[i] = '#';
	}
	else if (version == 1)
	{
		i = 1;
		return_line[0] = '/';
		return_line[1] = '*';
		endline = ft_strdup(":+:      :+:    :+:   */\n");
	}
	while (++i < 5)
		return_line[i] = ' ';
	j = -1;
	while (++j < strlen)
		return_line[i + j] = file_name[j];
	i = i + j;
	j = -1;
	while (++j < lenrem)
		return_line[i + j] = ' ';
	i = i + j;
	j = -1;
	while (++j < 25)
		return_line[i + j] = endline[j];
    return (return_line);
}

char	*get_mail(char *username)
{
	char	*return_mail;

	if (getenv("MAIL42"))
		return_mail = ft_strjoin(ft_strjoin(ft_strjoin(ft_strdup(username), " <"), getenv("MAIL42")), ">");
	else
		return_mail = ft_strjoin(ft_strjoin(ft_strjoin(ft_strdup(username), " <"), username), "@student.42lyon.fr>");
	return (return_mail);
}

char    *line_mail(char *username, int version)
{
    char    *return_line;
    char    *mail;
	char	*begin;
	char	*endline;
	int		i;
	int		j;
	int		mailen;
	int		lenrem;

	mail = get_mail(username);
	return_line = ft_calloc(82, sizeof(char));
	mailen = ft_strlen(mail);
	lenrem = 43 - mailen;
	i = -1;
	if (version == 0)
	{
		begin = ft_strdup("#    By: ");
		endline = ft_strdup("+#+  +:+       +#+         #\n");
	}
	else if (version == 1)
	{
		begin = ft_strdup("/*   By: ");
		endline = ft_strdup("+#+  +:+       +#+        */\n");
	}
	while (++i < 9)
		return_line[i] = begin[i];
	j = -1;
	while (++j < mailen)
		return_line[i + j] = mail[j];
	i = i + j;
	j = -1;
	while (++j < lenrem)
		return_line[i + j] = ' ';
	i = i + j;
	j = -1;
	while (++j < 29)
		return_line[i + j] = endline[j];
    return (return_line);
}

char	*line_date(char *username, char *fulldate, char *begin, char *end, int size_rem)
{
	char    *return_line;
	char	*tmp_str;
	int		i;
	int		j;
	int		len_name;
	int		len_date;
	int		lenrem;

	i = -1;
	len_name = ft_strlen(username);
	len_date = ft_strlen(fulldate);
	lenrem = size_rem - len_name;
	return_line = ft_calloc(82, sizeof(char));
	while (++i < 14)
		return_line[i] = begin[i];
	j = -1;
	while (++j < len_date)
		return_line[i + j] = fulldate[j];
	tmp_str = ft_strdup(" by ");
	i = i + j;
	j = -1;
	while (++j < 4)
		return_line[i + j] = tmp_str[j];
	i = i + j;
	j = -1;
	while (++j < len_name)
		return_line[i + j] = username[j];
	i = i + j;
	j = -1;
	while (++j < lenrem)
		return_line[i + j] = ' ';
	i = i + j - 1;
	j = -1;
	while (++j + i < 82)
		return_line[i + j] = end[j];
	return (return_line);
}

char	*get_date()
{
	time_t 		rawtime;
	struct tm	timeinfo;
	char	**tmp_split;
	char	*timeclock;
	char	*fulldate;
	char	*year;
	char	*month;
	char	*day;

	time(&rawtime);
	timeinfo = *localtime(&rawtime);
	tmp_split = ft_split(asctime(&timeinfo), ' ');
	timeclock = ft_strdup(tmp_split[ft_arrlen(tmp_split) - 2]);
	year = ft_itoa(timeinfo.tm_year + 1900);
	if (timeinfo.tm_mon + 1 < 10)
		month = ft_strjoin("0", ft_itoa(timeinfo.tm_mon + 1));
	else
		month = ft_itoa(timeinfo.tm_mon + 1);
	if (timeinfo.tm_mday < 10)
		day = ft_strjoin("0", ft_itoa(timeinfo.tm_mday));
	else
		day = ft_itoa(timeinfo.tm_mday);
	fulldate = ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(ft_strjoin(year, "/"), month), "/"), day), " "), timeclock);
	return (fulldate);
}

// if version == 0 header for Makefile    else    version == 1 header for file.h and file.c
void	generate_header(int fd, char *file_name, int version)
{
	char	*username = getenv("USER");

	if (version == 0)
	{
		write_str(fd, "# **************************************************************************** #\n");
		write_str(fd, "#                                                                              #\n");
		write_str(fd, "#                                                         :::      ::::::::    #\n");
		write_str(fd, line_file(file_name, 0));
		write_str(fd, "#                                                     +:+ +:+         +:+      #\n");
		write_str(fd, line_mail(username, 0));
		write_str(fd, "#                                                 +#+#+#+#+#+   +#+            #\n");
		write_str(fd, line_date(username, get_date(), "#    Created: ", "#+#    #+#              #\n", 19));
		write_str(fd, line_date(username, get_date(), "#    Updated: ", "###   ########.fr        #\n", 18));
		write_str(fd, "#                                                                              #\n");
		write_str(fd, "# **************************************************************************** #\n\n");
	}
	else if (version == 1)
	{
		write_str(fd, "/* ************************************************************************** */\n");
		write_str(fd, "/*                                                                            */\n");
		write_str(fd, "/*                                                        :::      ::::::::   */\n");
		write_str(fd, line_file(file_name, 1));
		write_str(fd, "/*                                                    +:+ +:+         +:+     */\n");
		write_str(fd, line_mail(username, 1));
		write_str(fd, "/*                                                +#+#+#+#+#+   +#+           */\n");
		write_str(fd, line_date(username, get_date(), "/*   Created: ", "#+#    #+#             */\n", 19));
		write_str(fd, line_date(username, get_date(), "/*   Updated: ", "###   ########.fr       */\n", 18));
		write_str(fd, "/*                                                                            */\n");
		write_str(fd, "/* ************************************************************************** */\n\n");
	}
}
