/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:33:40 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/03/13 11:02:58 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/project_gen.h"

static void	add_element(int *is_elem, char *question)
{
	char	tmp_bool[4];

	*is_elem = -1;
	while (*is_elem < 0)
	{
		system("clear");
		ft_printf(question, WHTB, NOCOLOR);
		scanf("%3s", tmp_bool);
		if (strcmp(tmp_bool, "yes") == 0 || strcmp(tmp_bool, "1") == 0)
		{
			*is_elem = 1;
			break;
		}
		else if (strcmp(tmp_bool, "no") == 0 || strcmp(tmp_bool, "0") == 0)
		{
			*is_elem = 0;
			break;
		}
		else if (!tmp_bool[0])
			exit (1);
		ft_printf("\n\n");
	}
	ft_printf("\n\n");
}

static void	ask_project_name(t_file	*project)
{
	system("clear");
	ft_printf("%s# ###################################### #\n", BLK);
	ft_printf(  "#%s           %sProject Generator%s            #\n", NOCOLOR, BWHT, BLK);
	ft_printf(  "#%s           %sby    SAPIN Mehdi%s            #\n", NOCOLOR, BWHT, BLK);
	ft_printf(  "# ###################################### #%s\n\n\n", NOCOLOR);
	
	project->name[0] = '\0';
	while (!project->name[0])
	{
		ft_printf("       %s -- Name of  the Project -- %s\n\n-> ", WHTB, NOCOLOR);
		scanf("%99s", project->name);
		ft_printf("\n\n");
	}
}

static int	contain_c(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 3)
		return (0);
	if (str[len - 1] != 'c' && str[len - 1] != '.')
		return (0);
	return (1);
}

static int	only_c(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 1 && str[0] == '.')
		return (0);
	else if ((len == 2 && str[0] == '.' && str[1] == 'c'))
		return (0);
	return (1);
}

static char	*ask_struct(t_file *project)
{
	char	*ask = " %s -- Use this project structure ? (yes/no) -- %s\n\n";

	ask = ft_strjoin(ask, project->name);
	ask = ft_strjoin(ask, "\n  |-- includes\n");
	if (project->is_libft)
		ask = ft_strjoin(ask, "  :  |-- libft/\n");
	ask = ft_strjoin(ask, "  :  |-- ");
	ask = ft_strjoin(ask, project->name);
	ask = ft_strjoin(ask, ".h\n  :\n  |-- sources\n  :  |-- .objs/\n  :  |-- files.c\n  :\n  |-- Makefile\n\n-> ");
	return (ask);
}

int	get_user_input(t_file *project)
{
	char	tmp_answer[100];
	int		count;
	int		i;
	int		j;
	int		k;

	project->is_folder = 0;

	ask_project_name(project);
	add_element(&project->is_libft, "       %s -- Add LIBFT ? (yes/no) -- %s\n\n-> ");

	// add_element(&project->use_struct, " %s -- Use this project structure ? (yes/no) -- %s\n\nTest\n\n-> ");
	add_element(&project->use_struct, ask_struct(project));

	project->folders[0][0] = '\0';
	if (project->use_struct)
		add_element(&project->is_folder, " %s -- Add folder into sources ? (yes/no) -- %s\n\n-> ");
	else
		// add_element(&project->is_folder, " %s -- Add folder into sources ? (yes/no) -- %s\n\n-> ");
		add_element(&project->is_folder, ft_strjoin(ft_strjoin(" %s -- Add folder into ", project->name), " ? (yes/no) -- %s\n\n-> "));
	system("clear");
	tmp_answer[0] = '\0';
	project->nb_folder = 0;
	if (project->is_folder)
	{	
		count = 1;
		while (strcmp(tmp_answer, "end") != 0)
		{
			ft_printf("%s -- Name of Folder %d ? (\"end\" to stop) -- %s\n\n-> ", WHTB, count, NOCOLOR);
			scanf("%99s", tmp_answer);
			if (strcmp(tmp_answer, "end") == 0)
			{
				project->is_folder = 1;
				break;
			}
			strcpy(project->folders[project->nb_folder], tmp_answer);
			project->nb_folder++;
			count++;
			ft_printf("\n\n");
		}
		ft_printf("\n\n");
	}

	// ask for file name
	system("clear");
	tmp_answer[0] = '\0';
	project->c_file[0][0][0] = '\0';
	if (project->is_folder)
	{
		i = 0;
		while (i < project->nb_folder)
		{
			j = 0;
			while (strcmp(tmp_answer, "end") != 0)
			{
				ft_printf("%s -- Name of File %d ? (\"end\" to stop) -- %s\n\n%s/  ", WHTB, j + 1, NOCOLOR, project->folders[i]);
				k = 0;
				while (project->c_file[i][k][0])
					ft_printf("%s  ", project->c_file[i][k++]);
				ft_printf("\n\n-> ");
				scanf("%19s", tmp_answer);
				if (strcmp(tmp_answer, "end") != 0)
				{
					if (contain_c(tmp_answer))
						strcpy(project->c_file[i][j], tmp_answer);
					else if (only_c(tmp_answer) && !(tmp_answer[ft_strlen(tmp_answer) - 1] == '.'))
						strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, ".c"));
					else if (tmp_answer[ft_strlen(tmp_answer) - 1] == '.' && ft_strlen(tmp_answer) > 1)
						strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, "c"));
					else
						j--;
					j++;
				}
				else if (i == 0 && j == 0)
					strcpy(project->c_file[i][j], "main.c");
				ft_printf("\n\n");
			}
			system("clear");
			project->c_file[i][j][0] = 0;
			tmp_answer[0] = '\0';
			i++;
		}
		ft_printf("\n\n");
	}
	else
	{
		i = 0;
		j = 0;
		while (strcmp(tmp_answer, "end") != 0)
		{
			if (project->use_struct)
				ft_printf("%s -- Name of File.c %d ? (\"end\" to stop) -- %s\n\n%s/  ", WHTB, j + 1, NOCOLOR, "sources");
			else
				ft_printf("%s -- Name of File.c %d ? (\"end\" to stop) -- %s\n\n%s/  ", WHTB, j + 1, NOCOLOR, project->name);
			k = 0;
			while (project->c_file[i][k][0])
				ft_printf("%s  ", project->c_file[i][k++]);
			ft_printf("\n\n-> ");
			scanf("%19s", tmp_answer);
			if (strcmp(tmp_answer, "end") != 0)
			{
				if (contain_c(tmp_answer))
					strcpy(project->c_file[i][j], tmp_answer);
				else if (only_c(tmp_answer) && !(tmp_answer[ft_strlen(tmp_answer) - 1] == '.'))
					strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, ".c"));
				else if (tmp_answer[ft_strlen(tmp_answer) - 1] == '.' && ft_strlen(tmp_answer) > 1)
					strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, "c"));
				else
					j--;
				j++;
			}
			else if (i == 0 && j == 0)
				strcpy(project->c_file[i][j], "main.c");
			ft_printf("\n\n");
		}
	}
	
	return (1);
}