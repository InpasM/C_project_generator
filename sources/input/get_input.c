/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehdisapin <mehdisapin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 09:33:40 by mehdisapin        #+#    #+#             */
/*   Updated: 2023/06/28 22:14:26 by mehdisapin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/project_gen.h"

void	add_element(int *is_elem, char *question)
{
	char	tmp_bool[4];

	*is_elem = -1;
	while (*is_elem < 0)
	{
		system("clear");
		ft_printf(question, BWHT, NOCOLOR);
		scanf("%3s", tmp_bool);
		if (strcmp(tmp_bool, "yes") == 0 || strcmp(tmp_bool, "1") == 0)
		{
			*is_elem = 1;
			break ;
		}
		else if (strcmp(tmp_bool, "no") == 0 || strcmp(tmp_bool, "0") == 0)
		{
			*is_elem = 0;
			break ;
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
	/*// ft_printf("%s# ###################################### #\n", BLK);
	// ft_printf("#%s           %sProject Generator%s            #\n", NOCOLOR, \
	// BWHT, BLK);
	// ft_printf("#%s           %sby    SAPIN Mehdi%s            #\n", NOCOLOR, \
	// BWHT, BLK);
	// ft_printf("# ###################################### #%s\n\n\n", NOCOLOR);*/
	project->name[0] = '\0';
	while (!project->name[0])
	{
		ft_printf("       %s -- Name of  the Project -- %s\n\n-> ", BWHT, \
		NOCOLOR);
		scanf("%99s", project->name);
		ft_printf("\n\n");
	}
}

static int	contain_c(char *str, int type_project)
{
	int	len;

	len = ft_strlen(str);
	if (type_project == C)
	{
		if (len < 3)
			return (0);
		if (str[len - 1] != 'c' && str[len - 1] != '.')
			return (0);
	}
	else if (type_project == CPP)
	{
		if (len < 5)
			return (0);
		if (str[len - 1] != 'p' && str[len - 2] != 'p' && str[len - 3] != 'c' && str[len - 4] != '.')
			return (0);
	}
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
	char	*ask;

	ask = ft_strdup("%s -- Use this project structure ? (yes/no) -- %s\n\n");
	ask = ft_strjoin(ask, project->name);
	ask = ft_strjoin(ask, "\n  |-- includes\n");
	if (project->is_libft)
		ask = ft_strjoin(ask, "  :  |-- libft/\n");
	ask = ft_strjoin(ask, "  :  |-- ");
	ask = ft_strjoin(ask, project->name);
	ask = ft_strjoin(ask, ".h\n  :\n  |-- sources\n  :  |-- .objs/\n  :  |-- \
files.c\n  :\n  |-- Makefile\n\n-> ");
	return (ask);
}

void	init_project(t_file *project)
{
	// project->db->add_db = 0;
	// project->db->nb_lib = 0;
	project->is_folder = 0;
	project->folders[0][0] = '\0';
	project->nb_folder = 0;
	project->c_file[0][0][0] = '\0';
}

void	ask_folder_name(t_file *project)
{
	char	tmp_answer[100];
	int		count;

	system("clear");
	tmp_answer[0] = '\0';
	if (project->is_folder)
	{	
		count = 1;
		while (strcmp(tmp_answer, "end") != 0)
		{
			ft_printf("%s -- Name of Folder %d ? (\"end\" to stop) -- \
%s\n\n-> ", WHTB, count, NOCOLOR);
			scanf("%99s", tmp_answer);
			if (strcmp(tmp_answer, "end") == 0)
			{
				project->is_folder = 1;
				break ;
			}
			strcpy(project->folders[project->nb_folder], tmp_answer);
			project->nb_folder++;
			count++;
			ft_printf("\n\n");
		}
		ft_printf("\n\n");
	}
}

int	cpy_file(t_file *project, char *tmp_answer, int i, int j)
{
	if (contain_c(tmp_answer, project->type_project))
		strcpy(project->c_file[i][j], tmp_answer);
	else if (only_c(tmp_answer) && !(tmp_answer[ft_strlen(tmp_answer) - 1] == '.'))
	{
		if (project->type_project == C)
			strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, ".c"));
		else if (project->type_project == CPP)
			strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, ".cpp"));
	}
	else if (tmp_answer[ft_strlen(tmp_answer) - 1] == '.' && ft_strlen(tmp_answer) > 1)
	{
		if (project->type_project == C)
			strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, "c"));
		else if (project->type_project == CPP)
			strcpy(project->c_file[i][j], ft_strjoin(tmp_answer, "cpp"));
	}
	else
		j--;
	j++;
	return (j);
}

void	ask_file_name(t_file *project)
{
	char	tmp_answer[100];
	int		i;
	int		j;
	int		k;

	system("clear");
	tmp_answer[0] = '\0';
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
					j = cpy_file(project, tmp_answer, i, j);
				else if (i == 0 && j == 0)
				{
					if (project->type_project == C)
						strcpy(project->c_file[i][j], "main.c");
					else if (project->type_project == CPP)
						strcpy(project->c_file[i][j], "main.cpp");
				}
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
			{
				if (project->type_project == C)
					ft_printf("%s -- Name of File.c %d ? (\"end\" to stop) -- %s\n\n%s/  ", WHTB, j + 1, NOCOLOR, "sources");
				else if (project->type_project == CPP)
					ft_printf("%s -- Name of File.cpp %d ? (\"end\" to stop) -- %s\n\n%s/  ", WHTB, j + 1, NOCOLOR, "sources");
			}
			else
			{
				if (project->type_project == C)
					ft_printf("%s -- Name of File.c %d ? (\"end\" to stop) -- %s\n\n%s/  ", WHTB, j + 1, NOCOLOR, project->name);
				else if (project->type_project == CPP)
					ft_printf("%s -- Name of File.cpp %d ? (\"end\" to stop) -- %s\n\n%s/  ", WHTB, j + 1, NOCOLOR, project->name);
			}
			k = 0;
			while (project->c_file[i][k][0])
				ft_printf("%s  ", project->c_file[i][k++]);
			ft_printf("\n\n-> ");
			scanf("%19s", tmp_answer);
			if (strcmp(tmp_answer, "end") != 0)
				j = cpy_file(project, tmp_answer, i, j);
			else if (i == 0 && j == 0)
			{
				if (project->type_project == C)
					strcpy(project->c_file[i][j], "main.c");
				else if (project->type_project == CPP)
					strcpy(project->c_file[i][j], "main.cpp");
			}
			ft_printf("\n\n");
		}
	}
}

int	add_to_database(t_file *project)
{
	char	tmp_name[100];
	char	tmp_value[256];
	char	tmp_flags[100];
	(void)tmp_flags;
	(void)tmp_value;
	(void)project;

	system("clear");
	ft_printf("       %s -- Adding a new Library -- %s\n\n", WHTB, \
	NOCOLOR);
	tmp_name[0] = '\0';
	while (!tmp_name[0])
	{
		ft_printf("%sName:%s ", WHTB, \
		NOCOLOR);
		if (scanf("%99s", tmp_name) < 0)
			break ;
		ft_printf("\n\n");
	}
	// system("clear");
	tmp_value[0] = '\0';
	while (!tmp_value[0])
	{
		ft_printf("%sGit Repository or Folder Path:%s ", WHTB, \
		NOCOLOR);
		if (scanf("%255s", tmp_value) < 0)
			break ;
		ft_printf("\n\n");
	}
	write_str(project->db->fd_db, "\n\n");
	write_str(project->db->fd_db, "name=");
	if (tmp_name[0])
		write_str(project->db->fd_db, tmp_name);

	int	tmp_len = ft_strlen_null(tmp_value);
	// printf("last char %s\n", tmp_value + (tmp_len - 4));
	write_str(project->db->fd_db, ",");
	if (tmp_len > 4 && ft_strmatch(tmp_value + (tmp_len - 4), ".git"))
		write_str(project->db->fd_db, "git=");
	// printf("%d\n", access(tmp_value, F_OK));
	else if (access(tmp_value, F_OK))
		write_str(project->db->fd_db, "path=");
	if (tmp_value[0])
		write_str(project->db->fd_db, tmp_value);
	return (0);
}

void	add_lib(t_file *project)
{
	add_element(&project->db->add_db, "       %s -- Add libraries ? (yes/no) -- \
%s\n\n-> ");
}

int	ask_for_libraries(t_file *project, char **argv, char **envp)
{
	int	tmp_add = 0;
	(void)tmp_add;
	(void)project;
	parsing_database(project, argv, envp);
	if (!project->db->nb_lib)
	{
		add_element(&tmp_add, "       %s -- No libraries register! -- %s\n\
	Configure new library ? (yes/no)\n\n-> ");
		if (tmp_add)
			if (add_to_database(project) == 0)
				if (parsing_database(project, argv, envp) != 0)
					return (-1);
	}
	else
	{
		add_lib(project);
	}
	return (0);
}

int	ask_project_language(t_file *project)
{
	char	tmp_bool[4];

	system("clear");
	ft_printf("%s# ###################################### #\n", BLK);
	ft_printf("#%s           %sProject Generator%s            #\n", NOCOLOR, \
	BWHT, BLK);
	ft_printf("#%s           %sby    SAPIN Mehdi%s            #\n", NOCOLOR, \
	BWHT, BLK);
	ft_printf("# ###################################### #%s\n\n", NOCOLOR);
	
	project->type_project = 0;
	while (project->type_project == 0)
	{
		ft_printf("     %s -- Language of the project -- %s\n\n1/ C\n2/ C++\n\n-> ", BWHT, \
		NOCOLOR);
		scanf("%2s", tmp_bool);
		if (strcmp(tmp_bool, "1") == 0 || strcmp(tmp_bool, "C") == 0)
		{
			project->type_project = 1;
			break ;
		}
		else if (strcmp(tmp_bool, "2") == 0 || strcmp(tmp_bool, "C++") == 0)
		{
			project->type_project = 2;
			break ;
		}
		else if (!tmp_bool[0])
			exit (1);
		ft_printf("\n\n");
	}
	ft_printf("\n\n");
	return (0);
}

void	get_c_info(t_file *project, char **argv, char **envp)
{
	ask_for_libraries(project, argv, envp);

	add_element(&project->is_libft, "       %s -- Add LIBFT ? (yes/no) -- \
%s\n\n-> ");

	add_element(&project->use_struct, ask_struct(project));
	if (project->use_struct)
		add_element(&project->is_folder, " %s -- Add folder into sources ? \
(yes/no) -- %s\n\n-> ");
	else
		add_element(&project->is_folder, ft_strjoin(ft_strjoin(" %s -- Add \
folder into ", project->name), " ? (yes/no) -- %s\n\n-> "));
	ask_folder_name(project);
	ask_file_name(project);
}

void	get_cpp_info(t_file *project)
{
	(void)project;
	char	*h_file_question = ft_multijoin("       %s -- Add ", project->name, ".hpp file ? (yes/no) -- %s\n\n-> ", NULL);

	// printf("%s\n", h_file_question);
	add_element(&project->add_header, h_file_question);

	/*add_element(&project->add_header, "       %s -- Add .h / .hpp files ? (yes/no) -- \
%s\n\n-> ");
	if (project->add_header)
	{
		printf("ask name of header\n");
	}*/

	add_element(&project->add_cpp_files, "       %s -- Add .cpp files ? (yes/no) -- \
%s\n\n-> ");
	if (project->add_cpp_files)
	{
		// printf("ask name of cpp files\n");
		ask_file_name(project);
	}
}

int	get_user_input(t_file *project, char **argv, char **envp)
{
	(void)ask_struct;
	(void)add_element;
	(void)ask_project_name;
	(void)envp;
	(void)argv;

	init_project(project);
	ask_project_language(project);
	ask_project_name(project);
	// project->type_project = 2;
	// project->name[0] = 't';
	// project->name[1] = 'e';
	// project->name[2] = 's';
	// project->name[3] = 't';
	// project->name[4] = 0;
	if (project->type_project == 1)
		get_c_info(project, argv, envp);
	else if (project->type_project == 2)
		get_cpp_info(project);
	return (1);
}
